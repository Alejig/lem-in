/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:35:51 by aljigmon          #+#    #+#             */
/*   Updated: 2020/03/12 16:23:22 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int8_t	add_path(t_three **three_pointer, t_path *path, uint32_t length)
{
	t_path	*branch;

	branch = concretize_path(path);
	if (!branch)
		return (ERROR);
	append_branch(three_pointer, branch, length);
	return (SUCCESS);
}
