/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmond_karp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:18:50 by kesaint-          #+#    #+#             */
/*   Updated: 2020/04/19 12:44:32 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline t_bool	already_contains(t_path *heap, t_room *room)
{
	if ((room->data.state & NOT_WALKABE) == NOT_WALKABE)
		return (TRUE);
	while (heap)
	{
		if (heap->room == room)
			return (TRUE);
		heap = heap->previous;
	}
	return (FALSE);
}

static inline int8_t	add_links(t_ctx *ctx, t_room *end,
		t_room **links, t_path *heap)
{
	t_path	node;
	t_room	*room;

	ctx->current->visited = TRUE;
	if (!links || !*links)
		return (edmond_karp(ctx->current, end, heap, ctx->pointer));
	if (already_contains(heap, *links))
		return (add_links(ctx, end, links + 1, heap));
	if (heap)
		heap->next = &node;
	room = *links;
	node.visited = FALSE;
	node.parent = ctx->current;
	node.previous = heap;
	node.room = room;
	node.next = NULL;
	return (add_links(ctx, end, links + 1, &node));
}

static inline uint32_t	get_path_length(t_path *path)
{
	uint32_t	length;

	length = 0;
	while (path)
	{
		length++;
		path->room->count++;
		path = path->parent;
	}
	return (length - 2);
}

static inline int8_t	store_path(t_three **three_pointer, t_path *path)
{
	uint32_t	length;

	length = get_path_length(path);
	if (check_path(three_pointer, path, length) == FALSE)
		remove_path(path);
	return (add_path(three_pointer, path, length));
}

int8_t					edmond_karp(t_path *current, t_room *end,
		t_path *heap, t_three **three_ptr)
{
	t_ctx ctx;

	ctx.current = current;
	ctx.pointer = three_ptr;
	if (!current->visited)
		return (add_links(&ctx, end, current->room->links, heap));
	if (current->room == end)
		return (store_path(three_ptr, current));
	if (current->next)
		return (edmond_karp(current->next, end, heap, three_ptr));
	return (ERROR);
}
