/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 13:50:30 by kesaint-          #+#    #+#             */
/*   Updated: 2020/04/19 12:06:09 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			clear_room(t_room **rooms)
{
	t_room		*room;

	if (!rooms || !*rooms)
		return ;
	room = *rooms;
	if (room->next)
		clear_room(&room->next);
	free((char*)room->name);
	if (room->links)
		free(room->links);
	free(room);
	*rooms = NULL;
}

static t_room	*create_room(char const *name, int x, int y, uint32_t data)
{
	t_room	*room;

	room = (t_room*)ft_memalloc(sizeof(t_room));
	if (!room)
		return (NULL);
	room->name = ft_strdup(name);
	if (!room->name)
		return (NULL);
	room->availabe = TRUE;
	room->point.x = x;
	room->point.y = y;
	room->data.state = data;
	return (room);
}

t_room			*parse_room(const char *line, uint32_t data)
{
	char		**words;
	char		*name;
	uint32_t	x;
	uint32_t	y;
	t_room		*room;

	room = NULL;
	words = ft_strsplit(line, ' ');
	if (!words)
		return (NULL);
	if (count_tab(words) != 3)
	{
		clear_tab(words);
		return (NULL);
	}
	name = words[0];
	x = parse_uint32(words[1]);
	y = parse_uint32(words[2]);
	if (check_uint32(words[1]) && check_uint32(words[2]))
		room = create_room(name, (uint32_t)x, (uint32_t)y, data);
	clear_tab(words);
	return (room);
}

static void		prepend_room(t_room **rooms, t_room *room)
{
	room->next = *rooms;
	(*rooms)->previous = room;
	*rooms = room;
}

void			append_room(t_room **rooms, t_room *room)
{
	t_room	*last;

	if (!*rooms)
	{
		*rooms = room;
		return ;
	}
	if ((room->data.state & SET_START) == SET_START)
		return (prepend_room(rooms, room));
	last = *rooms;
	while (last->next)
		last = last->next;
	if ((last->data.state & SET_END) == SET_END)
	{
		if (!last->previous)
			return (prepend_room(rooms, room));
		last->previous->next = room;
		room->next = last;
		room->previous = last->previous;
		last->previous = room;
		return ;
	}
	last->next = room;
	room->previous = last;
}
