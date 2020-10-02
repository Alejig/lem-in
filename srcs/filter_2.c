/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 17:56:18 by aljigmon          #+#    #+#             */
/*   Updated: 2020/04/09 18:10:43 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void				remove_count_links(t_three *three)
{
	t_path	*path;

	path = three->path;
	while (path)
	{
		path->room->count--;
		path = path->next;
	}
}

void					delete_path(t_three **three_pointer,
		t_three **three_ptr)
{
	t_three	*node;
	t_three *three;

	three = *three_ptr;
	remove_count_links(three);
	if (*three_pointer == three)
	{
		*three_pointer = three->next;
		return (free(three));
	}
	node = *three_pointer;
	while (node)
	{
		if (node == three)
		{
			node->previous->next = node->next;
			if (node->next)
				node->next->previous = node->previous;
			return (free(three));
		}
		node = node->next;
	}
}

t_bool					three_contains(t_three_w *three, t_path *path)
{
	while (three)
	{
		if (three->three->path == path)
			return (TRUE);
		three = three->previous;
	}
	return (FALSE);
}

static t_bool inline	overlap_path(t_path *path, t_path *other)
{
	t_path	*node;

	node = other;
	while (path->next)
	{
		node = other;
		while (node->next)
		{
			if (node->room == path->room)
			{
				return (TRUE);
			}
			node = node->next;
		}
		path = path->next;
	}
	return (FALSE);
}

uint32_t				remove_overlap(t_info *info, t_three_w *three)
{
	t_three_w	*next;
	t_three_w	*start;

	start = three;
	while (three && three->next)
	{
		while (three && !three->three)
			three = three->next;
		next = three->next;
		while (next && !next->three)
			next = next->next;
		if (!three || !next)
			return (0);
		if (overlap_path(three->three->path->next, next->three->path->next))
		{
			if (three->three->length < next->three->length)
				delete_path(&info->three, &next->three);
			else
				delete_path(&info->three, &three->three);
			three = start;
			continue ;
		}
		three = three->next;
	}
	return (0);
}
