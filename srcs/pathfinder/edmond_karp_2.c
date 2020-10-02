/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmond_karp_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 14:22:30 by aljigmon          #+#    #+#             */
/*   Updated: 2020/04/19 14:22:47 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void					remove_path(t_path *path)
{
	path = path->parent;
	while (path)
	{
		path->room->data.state |= NOT_WALKABE;
		path = path->parent;
	}
}

void					remove_link(t_room *room, t_room *link)
{
	uint32_t	index;

	index = 0;
	while (room->links[index])
	{
		if (room->links[index] == link)
		{
			while (room->links[index])
			{
				room->links[index] = room->links[index + 1];
				index++;
			}
			return ;
		}
		index++;
	}
}

t_bool					break_link(t_path *end)
{
	t_path		*node;
	t_path		*start;

	start = end;
	while (start && start->parent)
		start = start->parent;
	node = end->parent;
	remove_link(node->room, node->parent->room);
	remove_link(node->parent->room, node->room);
	return (TRUE);
}

t_bool					check_path(t_three **three_pointer,
		t_path *path, uint32_t length)
{
	t_room		*room;
	uint32_t	index;
	uint32_t	count;

	count = 0;
	index = 0;
	if (!length)
		return (FALSE);
	while ((room = path->parent->room->links[index]))
	{
		if (room != path->room && room != path->parent->parent->room)
			count++;
		index++;
	}
	if (count)
		break_link(path);
	return (check_path(three_pointer, path->parent, length - 1));
}
