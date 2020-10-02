/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:26:23 by aljigmon          #+#    #+#             */
/*   Updated: 2018/11/14 12:27:34 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static void		init(unsigned int *nb, int *i, int *count, int *n)
{
	if (*n < 0)
		*nb = *n * -1;
	else
		*nb = *n;
	*i = 0;
	*count = 1;
}

static void		ft_calcul(char *str, unsigned int n, int div, int c)
{
	int		i;

	i = 0;
	while (i < c)
	{
		if (n / div > 9)
			str[i] = (char)((n / div) % 10) + 48;
		else
			str[i] = (char)(n / div) + 48;
		div /= 10;
		i++;
	}
	str[i] = '\0';
}

char			*ft_itoa(int n)
{
	int				div;
	char			*str;
	int				count;
	int				i;
	unsigned int	nb;

	div = 1;
	init(&nb, &i, &count, &n);
	while (nb / div > 9)
	{
		div *= 10;
		count++;
	}
	if (n < 0)
	{
		if ((str = (char*)malloc(sizeof(char) * count + 2)) == NULL)
			return (NULL);
		str[i] = '-';
		i++;
	}
	else if ((str = (char*)malloc(sizeof(char) * count + 1)) == NULL)
		return (NULL);
	ft_calcul(&str[i], nb, div, count);
	return (str);
}
