/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 11:33:21 by kesaint-          #+#    #+#             */
/*   Updated: 2019/11/24 11:51:47 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			clear_tab(char **words)
{
	uint8_t	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

uint32_t		count_tab(char **words)
{
	uint32_t	size;

	size = 0;
	while (words[size])
		size++;
	return (size);
}
