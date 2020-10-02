/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 13:43:28 by kesaint-          #+#    #+#             */
/*   Updated: 2020/04/19 14:24:35 by aljigmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"
# include "get_next_line.h"
# include "defines.h"
# include "struct.h"

void			remove_path(t_path *path);
void			remove_link(t_room *room, t_room *link);
t_bool			check_path(t_three **three_pointer, t_path *path,
		uint32_t length);
t_bool			break_link(t_path *end);
void			clean_memory(t_info *info);
void			delete_unused_paths(t_info *info);
int8_t			add_path(t_three **three_pointer, t_path *path,
		uint32_t length);
void			remove_branch(t_three **three_pointer);
void			append_branch(t_three **three_pointer, t_path *path,
		uint32_t length);
t_path			*concretize_path(t_path *path);
int				check_constraints(t_info *info);
void			display_ants(t_info *info);
void			clear_path(t_path *path);
t_path			*create_path(t_room *room);
t_bool			check_uint32(const char *ptr);
int8_t			add_node_path(t_path *three, t_path *node, uint32_t length);
int8_t			edmond_karp(t_path *current, t_room *end, t_path *heap,
		t_three **three_pointer);
int8_t			apply_link(t_room *rooms, const char *line);
void			clear_room(t_room **rooms);
t_room			*parse_room(const char *line, uint32_t data);
void			append_room(t_room **rooms, t_room *next);
void			clear_paths(t_path **path);
int				parse_info(t_info *info, uint8_t state);
t_bool			str_contains(char const *str, char c);
void			clear_tab(char **words);
uint32_t		count_tab(char **words);
uint32_t		parse_uint32(const char *str);
int				lem_in(t_info *info);
char			*read_file(const int fd);
uint32_t		manhattan(t_room const *pos0, t_room const *pos1);
void			free_tab(char ***tab);
void			check_map(char *str);
t_bool			useless_path(t_info *info, t_three *three, t_path *path);
void			display_branch(t_path *path, uint32_t turn, uint32_t *count,
		uint32_t *ants);
t_three			*get_smallest_path(t_three *three);
void			delete_path(t_three **three_pointer, t_three **three_ptr);
uint32_t		remove_overlap(t_info *info, t_three_w *three);
t_bool			three_contains(t_three_w *three, t_path *path);
t_bool			treat_garbage(t_three_w *list, t_info *info, t_path *crossover);
t_bool			sorting_out_garbage(t_info *info, t_three_w *three);
t_bool			is_blocking(t_path *path);

#endif
