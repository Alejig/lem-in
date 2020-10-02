/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 11:35:19 by kesaint-          #+#    #+#             */
/*   Updated: 2020/04/09 17:05:42 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline t_bool		is_end_room(t_path *path)
{
	return ((path->room->data.state & SET_END) == SET_END);
}

static inline t_bool		is_start_room(t_path *path)
{
	return ((path->room->data.state & SET_START) == SET_START);
}

static inline void			display_move(t_path *start, t_path *end,
		uint32_t *count)
{
	t_path *s;

	if (*count)
		ft_putchar(' ');
	(*count)++;
	ft_putchar('L');
	ft_putnbr(start->room->ants);
	ft_putchar('-');
	ft_putstr(end->room->name);
	if (is_end_room(end))
	{
		s = start;
		while (s && s->previous->previous)
			s = s->previous;
		end->room->ants++;
	}
	else
		end->room->ants = start->room->ants;
	if (is_start_room(start))
		start->room->ants--;
	else
		start->room->ants = 0;
}

static inline t_path		*get_children_path(t_path *path)
{
	if (!path)
		return (NULL);
	if (is_end_room(path) || !path->room->ants)
		return (path);
	return (NULL);
}

void						display_branch(t_path *path,
		uint32_t turn, uint32_t *count, uint32_t *ants)
{
	t_path		*children;

	if (!path)
		return ;
	display_branch(path->next, turn, count, ants);
	if (!path->room->ants || (path->room->turn == turn
				&& !is_start_room(path) && !is_end_room(path)))
		return ;
	if (is_start_room(path) && !*ants)
		return ;
	children = get_children_path(path->next);
	if (!children)
		return ;
	children->room->turn = turn;
	display_move(path, children, count);
	if (is_start_room(path))
		(*ants)--;
	if ((path->room->data.state & SET_START) == SET_START)
		display_branch(path, turn, count, ants);
}
