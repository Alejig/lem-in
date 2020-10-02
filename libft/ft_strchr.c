/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:15:42 by aljigmon          #+#    #+#             */
/*   Updated: 2018/12/20 17:44:02 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (char*)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&str[i]);
	return (NULL);
}
