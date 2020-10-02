/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:35:51 by aljigmon          #+#    #+#             */
/*   Updated: 2019/09/28 15:12:52 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstappend(t_list **first, t_list *elem)
{
	t_list	*tmp;

	if (first == NULL || elem == NULL || *first == NULL)
		return ;
	tmp = *first;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
}
