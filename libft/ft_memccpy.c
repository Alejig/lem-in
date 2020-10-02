/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:12:14 by aljigmon          #+#    #+#             */
/*   Updated: 2018/11/17 11:51:16 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	void				*nul;
	unsigned char		*dest;
	unsigned char		*source;

	i = 0;
	nul = NULL;
	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	while (i < n)
	{
		dest[i] = source[i];
		if (source[i] == (unsigned char)c)
		{
			i++;
			return (&dst[i]);
		}
		i++;
	}
	return (nul);
}
