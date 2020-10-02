/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:50:31 by aljigmon          #+#    #+#             */
/*   Updated: 2018/11/16 17:48:12 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*str;

	i = 0;
	str = s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((void*)&str[i]);
		i++;
	}
	return (NULL);
}
