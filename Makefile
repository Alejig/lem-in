# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aljigmon <aljigmon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 19:52:22 by aljigmon          #+#    #+#              #
#    Updated: 2020/04/09 18:47:19 by aljigmon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Wextra -g3

NAME = lem-in

SRCS_DIR = srcs/

HEADERS_DIR = includes/

SRCS_NAMES = main.c cleaner.c parser.c lem_in.c filter.c \
			 utils/parse_uint32.c \
			 utils/str_contains.c utils/tab.c \
			 pathfinder/three.c \
			 pathfinder/edmond_karp.c pathfinder/edmond_karp_2.c \
			 pathfinder/path.c map/link.c \
			 map/room.c io/display.c io/ant.c \
			 utils/check_constraints.c utils/read_file.c \
			 utils/free.c utils/check_map.c io/display_2.c \
			 filter_2.c treat_garbage.c

HEADERS_NAMES = defines.h \
				struct.h \
				lem_in.h

LIBFT_DIR = libft/

LIBFT = $(LIBFT_DIR)libft.a

LIBFT_SRCS_NAMES = ft_memset.c ft_putstr_fd.c ft_strdel.c \
				   ft_memalloc.c ft_memmove.c ft_strcmp.c \
				   ft_strdup.c ft_strsplit.c ft_memcpy.c \
				   ft_putchar.c ft_putnbr.c ft_putstr.c \
				   ft_putendl.c ft_strlen.c get_next_line.c

LIBFT_HEADERS_NAMES = libft.h get_next_line.h

LIBFT_HEADERS_DIR = $(addprefix $(LIBFT_DIR), includes/)

LIBFT_SRCS = $(addprefix $(LIBFT_DIR), $(LIBFT_SRCS_NAMES))

LIBFT_HEADERS = $(addprefix $(LIBFT_HEADERS_DIR), $(LIBFT_HEADERS_NAMES))

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAMES))

HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_NAMES))

OBJS = $(SRCS:.c=.o)

GREEN = \033[32;1m

RED = \033[31m

FINISHED_COLOR = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS) $(LIBFT)
	@$(CC) $(CFLAGS) -I$(HEADERS_DIR) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)READY$(FINISHED_COLOR)"

$(LIBFT): $(LIBFT_SRCS) $(LIBFT_HEADERS)
	@make -s -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(HEADERS_DIR) -I$(LIBFT_HEADERS_DIR) -o $@ -c $<

clean:
	@rm -rf $(OBJS)
	@make -s -C $(LIBFT_DIR) clean
	@echo "$(RED)deleting objects files from $(SRCS_DIR)$(FINISHED_COLOR)"
	@echo "$(RED)deleting objects files from $(LIBFT_DIR)$(FINISHED_COLOR)"

fclean: clean
	@rm -rf $(NAME)
	@make -s -C $(LIBFT_DIR) fclean
	@echo "$(RED)deleting $(NAME)$(FINISHED_COLOR)"
	@echo "$(RED)deleting $(LIBFT)$(FINISHED_COLOR)"

re: fclean all
