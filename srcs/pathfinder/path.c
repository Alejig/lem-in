/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:59:04 by kesaint-          #+#    #+#             */
/*   Updated: 2020/03/12 16:34:52 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				clear_path(t_path *path)
{
	t_path	*next;

	while (path)
	{
		next = path->next;
		free(path);
		path = next;
	}
}

t_path				*create_path(t_room *room)
{
	t_path	*path;

	path = (t_path*)ft_memalloc(sizeof(t_path));
	if (!path)
		return (NULL);
	path->room = room;
	return (path);
}

void				remove_branch(t_three **three_pointer)
{
	if (!*three_pointer)
		return ;
	clear_path((*three_pointer)->path);
	free(*three_pointer);
	*three_pointer = NULL;
}

void				append_branch(t_three **three_pointer,
		t_path *path, uint32_t length)
{
	t_three	*branch;
	t_three	*three;

	branch = (t_three*)ft_memalloc(sizeof(t_three));
	branch->length = length;
	if (!branch)
		return ;
	branch->path = path;
	if (!*three_pointer)
	{
		*three_pointer = branch;
		return ;
	}
	three = *three_pointer;
	while (three && three->next)
		three = three->next;
	branch->previous = three;
	three->next = branch;
}

t_path				*concretize_path(t_path *path)
{
	t_path	*next;
	t_path	*node;

	node = NULL;
	next = NULL;
	while (path)
	{
		node = (t_path*)ft_memalloc(sizeof(t_path));
		if (!node)
			return (NULL);
		if (next)
		{
			next->previous = node;
			node->next = next;
		}
		else
			node->previous = NULL;
		node->room = path->room;
		next = node;
		path = path->parent;
	}
	return (node);
}
