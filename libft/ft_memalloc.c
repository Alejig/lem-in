/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:45:19 by aljigmon          #+#    #+#             */
/*   Updated: 2018/11/10 16:19:40 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static void		ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	if (s == NULL)
		return ;
	i = 0;
	str = s;
	while (i < n)
		str[i++] = 0;
}

void			*ft_memalloc(size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	if ((tab = malloc(size)) == NULL)
		return (NULL);
	ft_bzero(tab, size);
	return (tab);
}
