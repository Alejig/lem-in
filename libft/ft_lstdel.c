/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:59:05 by aljigmon          #+#    #+#             */
/*   Updated: 2019/09/28 15:13:10 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list		*deler;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	deler = (*alst)->next;
	while (deler != NULL)
	{
		del(deler->content, deler->content_size);
		free(deler);
		deler = deler->next;
	}
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
