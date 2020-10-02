/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:21:23 by aljigmon          #+#    #+#             */
/*   Updated: 2019/02/18 14:47:41 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchange(char *str, char to_change, char new)
{
	char	*s;

	s = str;
	while (*str)
	{
		if (*str == to_change)
			*str = new;
		str++;
	}
	return (s);
}
