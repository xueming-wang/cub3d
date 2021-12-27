# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 15:11:40 by xuwang            #+#    #+#              #
#    Updated: 2021/12/27 20:05:07 by xuwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Cub3D

CC 	= gcc

IFLAGS = -I./include -I./libft

LFLAGS = -L./libft -lft

CFLAGS 	= -Wall -Wextra -Werror -g3 -fsanitize=address

SRCS    := ./src/parser/parsing_map.c \
			./src/parser/parsing_map_part.c \
			./src/parser/parsing_tex.c \
			./src/parser/parsing_tex_part.c \
			./src/parser/parsing.c \
			./src/main.c \
			./src/utils/exit.c \
			./src/utils/utils.c \
			./src/parser/set_mapinfo.c

OBJS := $(SRCS:%.c=%.o)

NONE			= \033[0m
CL_LINE			= \033[2K

$(NAME): $(OBJS) 
	
	@printf "$(CL_LINE)compiler>>>>>>>> $(NONE)\r"
	@$(MAKE) -C ./libft
	@echo "libft done!"
	@printf "$(CL_LINE)compiler>>>>>>>> $(NONE)\r"
	@$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) -o $(NAME) $(LFLAGS)
	@echo "cub3d done!"

all: $(NAME)
	
clean:
		@rm -rf $(OBJS)
		@$(MAKE) -C ./libft clean
		@echo "Delete>>>>>>"

fclean: clean
		@rm -rf $(NAME)
		@$(MAKE) -C ./libft fclean
		@echo "Delete all>>>>>>"
re: fclean all

%.o: %.c
	
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: all clean fclean re
	
