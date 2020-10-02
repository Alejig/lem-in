/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:32:13 by aljigmon          #+#    #+#             */
/*   Updated: 2020/01/31 17:48:59 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include <stdlib.h>

static int	countstr(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int	getlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	copy(char **tab, char const *s, char c)
{
	int		len;

	len = getlen(s, c);
	if (!(*tab = ft_strnew(len)))
		return (0);
	ft_strncpy(*tab, s, len);
	return (len);
}

static char	**free_tab(char **tab, int i)
{
	while (i)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		count;
	int		len;
	char	**tab;

	if (!s)
		return (NULL);
	count = countstr(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	i = 0;
	while (*s && i < count)
	{
		while (*s == c)
			s++;
		if (!(len = copy(tab + i, s, c)))
			return (free_tab(tab, i));
		s += len;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
