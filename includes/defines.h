/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:22:48 by aljigmon          #+#    #+#             */
/*   Updated: 2020/01/31 16:04:25 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define BUFF_SIZE 4096

# define TRUE 1
# define FALSE 0

# define NOTHING 2
# define SUCCESS 0
# define ERROR 1

# define NOT_WALKABE 64
# define WALKABE 128
# define OCCUPIED 256

# define COMMAND		0x2323
# define START_ROOM		0x7472617473
# define END_ROOM		0x646e65

# define SET_START	2
# define SET_END	4
# define SET_ROOM	8
# define SET_LINK   16
# define SET_ANTS	32

typedef int			t_bool;

#endif
