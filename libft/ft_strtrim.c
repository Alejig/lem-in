/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:41:47 by aljigmon          #+#    #+#             */
/*   Updated: 2019/09/28 15:17:33 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static void		init(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

static int		ft_nospaces(const char *s)
{
	int		i;
	int		a;

	if (s == NULL)
		return (0);
	i = ft_strlen(s) - 1;
	a = 0;
	while (i != 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i--;
	i++;
	while (s[a] && (s[a] == ' ' || s[a] == '\t' || s[a] == '\n'))
	{
		a++;
		i--;
	}
	if (i < 0)
		i = 0;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		a;
	int		c;

	init(&i, &a, &c);
	if (s == NULL)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * (ft_nospaces(s) + 1))) == NULL)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	a = ft_strlen(s) - 1;
	while (a != 0 && (s[a] == ' ' || s[a] == '\t' || s[a] == '\n'))
		a--;
	a++;
	while (i < a)
	{
		str[c] = s[i];
		c++;
		i++;
	}
	str[c] = '\0';
	return (str);
}
