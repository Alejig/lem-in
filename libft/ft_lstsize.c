/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:48:55 by aljigmon          #+#    #+#             */
/*   Updated: 2019/09/28 15:14:21 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_lstsize(t_list *alst)
{
	int		i;
	t_list	*aff;

	if (alst == NULL)
		return (0);
	aff = alst;
	i = 0;
	while (aff != NULL)
	{
		i++;
		aff = aff->next;
	}
	return (i);
}
