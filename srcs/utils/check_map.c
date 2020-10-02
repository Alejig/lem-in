/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:11:06 by aljigmon          #+#    #+#             */
/*   Updated: 2020/03/12 14:21:05 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_map(char *map)
{
	int		size;

	size = ft_strlen(map) - 1;
	while (size >= 0 && map[size] == '\n' && map[size - 1] == '\n')
	{
		map[size] = '\0';
		size--;
	}
}
