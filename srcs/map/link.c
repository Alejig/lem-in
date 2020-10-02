/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:38:23 by kesaint-          #+#    #+#             */
/*   Updated: 2019/12/01 21:26:14 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static uint32_t	count_links(t_room **rooms)
{
	uint32_t	count;

	if (!rooms)
		return (0);
	count = 0;
	while (rooms[count])
		count++;
	return (count);
}

static int8_t	append_link(t_room *room, t_room *link)
{
	t_room		**links;
	uint32_t	count;

	count = count_links(room->links);
	links = (t_room**)ft_memalloc(sizeof(t_room*) * (count + 2));
	if (!links)
		return (ERROR);
	if (room->links)
	{
		ft_memmove(links, room->links, sizeof(t_room*) * count);
		free(room->links);
	}
	links[count] = link;
	room->links = links;
	return (SUCCESS);
}

static t_room	*get_room(t_room *room, char *name)
{
	while (room
		&& ft_strcmp(room->name, name))
		room = room->next;
	return (room);
}

int8_t			apply_link(t_room *rooms, const char *line)
{
	char	**fields;
	t_room	*first;
	t_room	*second;

	fields = ft_strsplit(line, '-');
	if (!fields)
		return (ERROR);
	if (count_tab(fields) != 2)
	{
		clear_tab(fields);
		return (ERROR);
	}
	first = get_room(rooms, fields[0]);
	second = get_room(rooms, fields[1]);
	clear_tab(fields);
	if (!first || !second)
		return (ERROR);
	if (append_link(first, second) == ERROR
		|| append_link(second, first) == ERROR)
		return (ERROR);
	first->neighbors++;
	second->neighbors++;
	return (SUCCESS);
}
