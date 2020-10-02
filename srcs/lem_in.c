/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:18:56 by kesaint-          #+#    #+#             */
/*   Updated: 2020/03/12 16:49:28 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline t_room	*get_end_room(t_room *room)
{
	while (room && room->next)
		room = room->next;
	return (room);
}

int						lem_in(t_info *info)
{
	t_room	*end;
	t_path	start;

	if (!check_constraints(info))
		return (ERROR);
	check_map(info->map);
	ft_putstr(info->map);
	ft_putchar('\n');
	end = get_end_room(info->rooms);
	ft_memset(&start, 0, sizeof(t_path));
	start.room = info->rooms;
	while (edmond_karp(&start, end, &start, &info->three) == SUCCESS)
	{
		start.visited = FALSE;
		start.next = NULL;
	}
	if (!info->three)
		return (ERROR);
	info->three->next = info->three->next;
	display_ants(info);
	return (SUCCESS);
}
