# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 15:11:40 by xuwang            #+#    #+#              #
#    Updated: 2021/12/15 17:00:10 by xuwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Cub3D

CC 	= gcc

CFLAGS 	= -Wall -Wextra -Werror

IFLAGS = -I. -I./libft

LFLAGS = -L./libft -lft

SRCS_P	:= exit.c \
			parsing.c \
			parsing_map.c \
			parsing_tex.c \
			

OBJS_P := $(SRCS_P:%.c=%.o)

$(NAME): $(OBJS_P) $(OBJS_C)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS_P) $(LFLAGS) $(IFLAGS) -o $(NAME)

all: $(NAME) $(CHECKER) 

clean:
	$(MAKE) -C libft clean
	rm -rf $(OBJS_P)

fclean: clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re: fclean all

%.o:%.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: all clean fclean re
