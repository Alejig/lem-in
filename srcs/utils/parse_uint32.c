/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_uint32.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:06:47 by aljigmon          #+#    #+#             */
/*   Updated: 2020/01/31 19:06:51 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "lem_in.h"

static t_bool		exceeds_limit(char *str)
{
	char	c;
	int		i;

	i = 0;
	while (str[i])
	{
		c = "4294967295"[i];
		if (str[i] > c)
			return (FALSE);
		if (str[i++] < c)
			return (TRUE);
	}
	return (TRUE);
}

t_bool				check_uint32(const char *ptr)
{
	int		i;
	char	*str;

	str = (char*)ptr;
	if (*str == '-')
		return (FALSE);
	while (*str && *str != '\n' && *str == '+')
		str++;
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	if (i > 10)
		return (FALSE);
	if (i > 9)
		return (exceeds_limit(str));
	return (TRUE);
}

uint32_t			parse_uint32(const char *str)
{
	uint32_t		nbr;
	int				i;

	nbr = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (uint8_t)str[i] - 48;
		i++;
	}
	return ((uint32_t)nbr);
}
