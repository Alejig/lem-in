/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:58:52 by kesaint-          #+#    #+#             */
/*   Updated: 2020/04/09 18:49:05 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool	sorting_out_garbage(t_info *info, t_three_w *three)
{
	t_three_w	*node;
	uint32_t	count;

	count = 0;
	while (three->previous)
	{
		count++;
		three = three->previous;
	}
	remove_overlap(info, three);
	node = three->next;
	while (node)
	{
		if (node->three && node->three->length > info->ants)
		{
			delete_path(&info->three, &node->three);
			node = three->next;
			count--;
			continue ;
		}
		node = node->next;
	}
	return (FALSE);
}

t_bool	is_blocking(t_path *path)
{
	if ((path->room->data.state & SET_START) == SET_START
			|| (path->room->data.state & SET_END) == SET_END)
		return (FALSE);
	if (path->room->count > 1)
		return (TRUE);
	return (FALSE);
}

void	delete_unused_paths(t_info *info)
{
	t_three		*three;
	t_path		*path;
	t_three_w	node;

	three = info->three;
	while (three)
	{
		ft_memset(&node, 0, sizeof(t_three_w));
		node.three = three;
		node.length = 1;
		path = three->path;
		while (path)
		{
			if (is_blocking(path))
			{
				node.crossover = path->room;
				treat_garbage(&node, info, path);
				three = info->three;
				break ;
			}
			path = path->next;
		}
		three = three->next;
	}
}
