/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:27:28 by aljigmon          #+#    #+#             */
/*   Updated: 2018/11/19 11:26:01 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	char			*dest;
	const char		*source;

	if (dst == NULL && src == NULL)
		return (dst);
	i = 0;
	dest = dst;
	source = src;
	if (dst <= src)
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	else if (dst > src)
	{
		len--;
		while ((int)len != -1)
		{
			dest[len] = source[len];
			len--;
		}
	}
	return (dst);
}
