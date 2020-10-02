/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:44:51 by aljigmon          #+#    #+#             */
/*   Updated: 2018/11/17 16:03:28 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*str;
	char	*to_find;

	j = 0;
	i = 0;
	str = (char*)haystack;
	to_find = (char*)needle;
	if (to_find[0] == '\0' || str == to_find)
		return (str);
	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && to_find[j])
				j++;
			if (!to_find[j])
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
