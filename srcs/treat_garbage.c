/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_garbage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:45:28 by aljigmon          #+#    #+#             */
/*   Updated: 2020/04/09 18:50:45 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline t_path	*get_crossover(t_path *crossover)
{
	while (crossover)
	{
		if (is_blocking(crossover))
			return (crossover);
		crossover = crossover->next;
	}
	return (crossover);
}

static inline t_path	*next_bridge(t_three_w *list,
		t_path *crossover, t_three *three)
{
	t_path	*path;

	while (three)
	{
		path = three->path;
		if (!three_contains(list, path))
			while (path)
			{
				if (path->room == crossover->room)
					return (crossover);
				path = path->next;
			}
		three = three->next;
	}
	return (NULL);
}

t_bool					treat_garbage(t_three_w *list,
		t_info *info, t_path *crossover)
{
	t_three_w	node;
	t_three		*three;

	three = info->three;
	node.previous = list;
	node.length = list->length + 1;
	if (next_bridge(list, crossover, three))
	{
		node.crossover = crossover->room;
		node.three = three;
		node.next = NULL;
		return (treat_garbage(&node, info, crossover));
	}
	if ((crossover = get_crossover(crossover->next)))
		return (treat_garbage(list, info, crossover));
	return (sorting_out_garbage(info, list));
}
