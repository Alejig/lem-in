/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:40:23 by aljigmon          #+#    #+#             */
/*   Updated: 2020/03/12 14:43:09 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_data
{
	uint8_t			state;
	int32_t			f;
	int32_t			g;
	int32_t			h;
}					t_data;

typedef struct		s_point {
	uint32_t		x;
	uint32_t		y;
}					t_point;

typedef struct		s_room
{
	t_data				data;
	t_point				point;
	uint32_t			count;
	const char			*name;
	uint32_t			ants;
	uint8_t				availabe;
	uint32_t			turn;
	uint32_t			neighbors;
	struct s_room		**links;
	struct s_room		*previous;
	struct s_room		*next;
}					t_room;

typedef struct		s_path
{
	t_room			*room;
	t_bool			visited;
	struct s_path	*parent;
	struct s_path	*next;
	struct s_path	*previous;
}					t_path;

typedef struct		s_three
{
	uint32_t		length;
	t_path			*path;
	t_path			*parent;
	t_bool			used;
	uint32_t		open;
	uint32_t		count;
	struct s_three	*next;
	struct s_three	*previous;
}					t_three;

typedef struct		s_three_w
{
	uint32_t			length;
	t_three				*three;
	t_room				*crossover;
	struct s_three_w	*next;
	struct s_three_w	*previous;
}					t_three_w;

typedef struct		s_ctx {
	t_path				*current;
	t_three				**pointer;
}					t_ctx;

typedef struct		s_info
{
	t_three			*three;
	uint32_t		count;
	char			*map;
	uint32_t		ants;
	t_path			*start;
	t_path			*end;
	t_room			*rooms;
}					t_info;

#endif
