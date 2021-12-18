# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 15:11:40 by xuwang            #+#    #+#              #
#    Updated: 2021/12/18 11:09:53 by xuwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Cub3D

CC 	= gcc

IFLAGS = -I./include -I./libft

LFLAGS = -L./libft -lft

CFLAGS 	= -Wall -Wextra -Werror -g3 -fsanitize=address

SRCS    := ./src/parser/parsing_map.c \
			./src/parser/parsing_tex.c \
			./src/parser/parsing.c \
			./src/main.c \
			./src/utils/exit.c \
			./src/utils/utils.c 

OBJS := $(SRCS:%.c=%.o)

$(NAME): $(OBJS) 
	@$(MAKE) -C ./libft
	@echo "libft done!"
	@$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) -o $(NAME) $(LFLAGS)
	@echo "done"

all: $(NAME)
	
clean:
		@rm -rf $(OBJS)
		@$(MAKE) -C ./libft clean
		@echo "Delete>>>>>>"

fclean: clean
		@rm -rf $(NAME)
		@$(MAKE) -C ./libft fclean
		@echo "Delete>>>>>>"
re: fclean all

%.o: %.c
	@echo "compiler>>>>>>>>"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: all clean fclean re
	
