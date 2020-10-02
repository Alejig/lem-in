/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 14:22:05 by aljigmon          #+#    #+#             */
/*   Updated: 2020/04/19 14:22:06 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		clear_path_pointer(t_path **path_pointer)
{
	t_path	*path;

	path = *path_pointer;
	if (path->next)
		clear_path_pointer(&path->next);
	free(path);
	*path_pointer = NULL;
}

static void		clear_three(t_three **three_pointer)
{
	t_three	*three;

	three = *three_pointer;
	if (!three)
		return ;
	if (three->next)
		clear_three(&three->next);
	if (three->path)
		clear_path_pointer(&three->path);
	if (three->parent)
		clear_path_pointer(&three->parent);
	free(three);
	*three_pointer = NULL;
}

void			clean_memory(t_info *info)
{
	if (info->map)
	{
		free(info->map);
		info->map = NULL;
	}
	clear_three(&info->three);
	clear_room(&info->rooms);
}
