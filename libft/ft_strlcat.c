/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:01:59 by aljigmon          #+#    #+#             */
/*   Updated: 2019/09/28 15:16:30 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		sizdst;
	size_t		sizsrc;
	size_t		i;
	size_t		j;

	sizdst = ft_strlen(dst);
	sizsrc = ft_strlen(src);
	i = sizdst;
	j = 0;
	if (sizdst < size)
	{
		while (i < size - 1 && src[j])
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	if (size < sizdst)
		return (size + sizsrc);
	else
		return (sizdst + sizsrc);
}
