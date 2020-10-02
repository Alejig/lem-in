/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:13:28 by kesaint-          #+#    #+#             */
/*   Updated: 2020/02/16 18:22:04 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline int	apply_command(const char *line, uint8_t *state)
{
	if (!ft_strcmp(line, "start"))
		*state = (SET_ROOM | SET_START);
	else if (*(uint32_t*)line == END_ROOM)
		*state = (SET_ROOM | SET_END);
	return (SUCCESS);
}

static inline int	apply_room(const char *line, t_room **rooms, uint8_t *state)
{
	t_room		*room;
	uint32_t	data;

	data = 0;
	if ((*state & SET_START) == SET_START)
		data |= SET_START;
	if ((*state & SET_END) == SET_END)
		data |= SET_END;
	room = parse_room(line, data);
	if (!room)
		return (ERROR);
	append_room(rooms, room);
	*state = SET_ROOM;
	return (SUCCESS);
}

static inline int	set_ants(const char *line, t_info *info, uint8_t *state)
{
	*state = SET_ROOM;
	if (check_uint32(line) == FALSE)
		return (ERROR);
	info->ants = parse_uint32(line);
	return (SUCCESS);
}

static inline int	handle_line(const char *line, t_info *info, uint8_t *state)
{
	if (*state == SET_ANTS)
		return (set_ants(line, info, state));
	if (*(uint16_t*)line == COMMAND)
		return (apply_command(line + 2, state));
	if (*line == '#' || *line == 'L')
		return (*line == 'L' ? ERROR : SUCCESS);
	if ((*state & SET_ROOM) == SET_ROOM)
	{
		if (apply_room(line, &info->rooms, state) == SUCCESS)
			return (SUCCESS);
		if (str_contains(line, '-'))
			*state = SET_LINK;
	}
	if (*state == SET_LINK)
		return (apply_link(info->rooms, line));
	if (!*line)
	{
		*state = SET_LINK;
		return (SUCCESS);
	}
	return (ERROR);
}

int					parse_info(t_info *info, uint8_t state)
{
	int		code;
	char	**tab;
	int		i;

	i = -1;
	code = 0;
	if (!(info->map = read_file(0)))
		return (ERROR);
	if (!(tab = ft_strsplit(info->map, '\n')))
	{
		ft_strdel(&info->map);
		return (ERROR);
	}
	while (tab[++i])
		if (handle_line(tab[i], (t_info*)info, &state) == ERROR)
		{
			code = ERROR;
			break ;
		}
	free_tab(&tab);
	if (code != SUCCESS || !check_constraints((t_info*)info))
		code = ERROR;
	return (code);
}
