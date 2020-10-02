/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 19:46:09 by aljigmon          #+#    #+#             */
/*   Updated: 2020/04/19 12:05:09 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_info		info;
	uint8_t		state;
	int			code;

	state = SET_ANTS;
	ft_memset(&info, '\0', sizeof(t_info));
	if (parse_info(&info, state) == SUCCESS)
	{
		if ((code = lem_in(&info)) != SUCCESS)
			ft_putstr_fd("ERROR\n", STDERR_FILENO);
		clean_memory(&info);
		return (code);
	}
	else
		clean_memory(&info);
	ft_putstr_fd("ERROR\n", STDERR_FILENO);
	return (ERROR);
}
