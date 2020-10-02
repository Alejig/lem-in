/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:02:04 by aljigmon          #+#    #+#             */
/*   Updated: 2020/01/31 15:07:46 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	display_move(uint32_t ants, const char *name)
{
	ft_putchar('L');
	ft_putnbr(ants);
	ft_putchar('-');
	ft_putstr(name);
}
