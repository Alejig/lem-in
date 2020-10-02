/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_constraints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 18:06:07 by aljigmon          #+#    #+#             */
/*   Updated: 2020/02/16 18:06:09 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_constraints(t_info *info)
{
	t_room	*room;
	int		status[2];

	if (!info->ants || !info->rooms)
		return (FALSE);
	status[0] = 0;
	status[1] = 0;
	room = info->rooms;
	while (room)
	{
		if ((room->data.state & SET_START) == SET_START)
			status[0]++;
		if ((room->data.state & SET_END) == SET_END)
			status[1]++;
		room = room->next;
	}
	return (status[0] == 1 && status[1] == 1);
}
