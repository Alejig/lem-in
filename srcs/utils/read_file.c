/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:00:40 by aljigmon          #+#    #+#             */
/*   Updated: 2020/04/17 11:42:11 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*joinstr(char *s1, char *s2, int f)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL || s2 == NULL)
		return (s1 == NULL ? ft_strdup(s2) : ft_strdup(s1));
	if (!(str = malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_memset(str, '\0', ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	f ? ft_strdel(&s1) : NULL;
	return (str);
}

char			*read_file(const int fd)
{
	int		code;
	char	buf[4096];
	char	*str;

	code = 0;
	str = NULL;
	ft_memset(buf, '\0', 4096);
	while ((code = read(fd, &buf, 4096)) > 0)
	{
		buf[code] = '\0';
		str = joinstr(str, buf, 1);
		if (!str)
			return (NULL);
		ft_memset(buf, '\0', 4096);
	}
	if (code == -1)
		return (NULL);
	return (str);
}
