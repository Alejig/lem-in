/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 16:45:20 by aljigmon          #+#    #+#             */
/*   Updated: 2020/04/09 17:06:01 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_three						*get_smallest_path(t_three *three)
{
	t_three	*start;
	t_three	*smallest;

	start = three;
	smallest = three;
	while (three)
	{
		if (three->length < smallest->length)
		{
			smallest = three;
			three = start;
			continue ;
		}
		three = three->next;
	}
	return (smallest);
}

static inline void			display_three(t_three *three, uint32_t turn)
{
	uint32_t	count;

	count = 0;
	while (three)
	{
		display_branch(three->path, turn, &count, &three->open);
		three = three->next;
	}
	if (count)
		ft_putchar('\n');
}

static t_room				*get_end(t_room *room)
{
	while (room)
	{
		if ((room->data.state & SET_END) == SET_END)
			break ;
		room = room->next;
	}
	return (room);
}

static inline t_bool		switch_paths(uint32_t ants, t_three *smallest)
{
	uint32_t	turn;
	t_three		*node;

	node = smallest;
	turn = 1;
	while (ants)
	{
		node = smallest;
		while (node && ants)
		{
			if (turn >= node->length)
			{
				ants--;
				node->open++;
			}
			node = node->next;
		}
		turn++;
	}
	return (TRUE);
}

void						display_ants(t_info *info)
{
	t_room		*end;
	uint32_t	turn;
	t_three		*smallest;

	smallest = get_smallest_path(info->three);
	end = get_end(info->rooms);
	info->rooms->ants = info->ants;
	turn = 1;
	switch_paths(info->ants, smallest);
	while (end->ants != info->ants)
	{
		display_three(info->three, turn);
		turn++;
	}
}
