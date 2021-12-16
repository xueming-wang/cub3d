# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 15:11:40 by xuwang            #+#    #+#              #
#    Updated: 2021/12/16 19:29:29 by xuwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Cub3D

CC 	= gcc

IFLAGS = -I./include -I./libft

LFLAGS = -L./libft -lft

CFLAGS 	= -Wall -Wextra -Werror

SRCS    := src/parser/parsing_map.c \
			src/parser/parsing_tex.c \
			src/parser/parsing.c \
			src/main.c \
			src/utils/exit.c

OBJS := $(SRCS:%.c=%.o)

$(NAME): $(OBJS) 
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) -o $(NAME) $(LFLAGS)

all: $(NAME)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) $< -o $@

.PHONY: all clean fclean re
	
