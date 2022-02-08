# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 15:11:40 by xuwang            #+#    #+#              #
#    Updated: 2022/02/08 16:49:55 by xuwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

CC 	= gcc

IFLAGS = -I./include -I./libft -I./mlx

LFLAGS = -L./libft -lft

CFLAGS 	= -Wall -Wextra -Werror -g3 -fsanitize=address

MFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX_DIR = ./mlx
MLX = libmlx.dylib

SRCS    := ./src/parser/parsing_map.c \
			./src/parser/parsing_map_part.c \
			./src/parser/parsing_tex.c \
			./src/parser/parsing_tex_part.c \
			./src/parser/parsing.c \
			./src/main.c \
			./src/utils/exit.c \
			./src/utils/utils.c \
			./src/parser/set_mapinfo.c \
			./src/exec/create_img.c 

OBJS := $(SRCS:%.c=%.o)

NONE			= \033[0m
CL_LINE			= \033[2K

ifeq ($(shell uname), Linux)
$(NAME): IFLAGS = -I. -I./libft -I./mlx_linux
$(NAME): MFLAGS	= -L./mlx_linux -lmlx_Linux -lXext -lX11
$(NAME): MLX_DIR = ./mlx_linux
$(NAME): MLX = libmlx.a
endif

$(NAME): $(OBJS) 
	
	@printf "$(CL_LINE)compiler>>>>>>>> $(NONE)\r"
	$(MAKE) -C ./$(MLX_DIR)
	@$(MAKE) -C ./libft
	@echo "libft done!"
	@printf "$(CL_LINE)compiler>>>>>>>> $(NONE)\r"
	@$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) -o $(NAME) $(LFLAGS) $(MFLAGS)
	@echo "cub3d done!"

all: $(NAME)
	
clean:
		@rm -rf $(OBJS)
		@$(MAKE) -C ./libft clean
		@echo "Delete>>>>>>"

ifeq ($(shell uname), Linux)
fclean: MLX_DIR = ./mlx_linux
fclean: MLX = libmlx.a
endif

fclean: clean
		@rm -rf $(NAME)
		@$(MAKE) -C ./libft fclean
		$(MAKE) -C ./$(MLX_DIR) clean
		@echo "Delete all>>>>>>"
re: fclean all

%.o: %.c
	
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: all clean fclean re
	
