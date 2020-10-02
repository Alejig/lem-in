/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:49:16 by aljigmon          #+#    #+#             */
/*   Updated: 2018/11/18 18:34:53 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*str_dest;
	const char		*str_src;

	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	str_dest = dst;
	str_src = src;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		i++;
	}
	return (dst);
}
