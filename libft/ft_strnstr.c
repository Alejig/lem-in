/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:25:40 by aljigmon          #+#    #+#             */
/*   Updated: 2018/11/19 11:53:14 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		j;
	char		*str;
	char		*to_find;

	str = (char*)s1;
	to_find = (char*)s2;
	if (to_find[0] == '\0' || str == to_find)
		return (str);
	i = 0;
	j = 0;
	while (str[i] && i < len)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && (i + j) < len && to_find[j])
				j++;
			if (!to_find[j])
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
