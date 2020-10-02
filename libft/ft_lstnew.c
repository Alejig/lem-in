/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:39:06 by aljigmon          #+#    #+#             */
/*   Updated: 2019/09/28 15:14:02 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*element;

	if ((element = (t_list*)malloc(sizeof(*element))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		element->content = NULL;
		element->content_size = 0;
		element->next = NULL;
		return (element);
	}
	if ((element->content = malloc(sizeof(*content) * content_size)) == NULL)
	{
		free(element->content);
		free(element);
		return (NULL);
	}
	ft_memcpy(element->content, content, content_size);
	element->content_size = content_size;
	element->next = NULL;
	return (element);
}
