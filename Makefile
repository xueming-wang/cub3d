# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xuwang <xuwang@42.student.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 15:11:40 by xuwang            #+#    #+#              #
#    Updated: 2022/03/22 17:11:57 by xuwang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC 	= clang

IFLAGS = -I./include -I./libft -I./mlx

LFLAGS = -L./libft -lft

CFLAGS 	= -Wall -Wextra -Werror #-g3 -fsanitize=address

MFLAGS	= -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX_DIR	:= ./mlx

MLX = libmlx.dylib

SRCS    := ./src/parser/parsing_map.c \
			./src/parser/parsing_map_part.c \
			./src/parser/parsing_map_part2.c \
			./src/parser/parsing_tex.c \
			./src/parser/parsing_tex_part.c \
			./src/parser/parsing.c \
			./src/main.c \
			./src/utils/exit.c \
			./src/utils/exit_util.c \
			./src/utils/utils.c \
			./src/parser/set_mapinfo.c \
			./src/exec/start_game.c \
			./src/exec/ray_casting.c \
			./src/exec/draw_tools.c \
			./src/exec/ray_casting_set.c \
			./src/exec/player_init.c \
			./src/exec/player_mov.c \
			./src/exec/player_rotate.c \
			./src/exec/text_init.c \
			./src/exec/drawing.c \
			./src/exec/key_control.c \
			

OBJS := $(SRCS:%.c=%.o)

NONE			= \033[0m
CL_LINE			= \033[2K

ifeq ($(shell uname), Linux)
$(NAME): IFLAGS = -I./include -I./libft -I./mlx_linux
$(NAME): MFLAGS	= -L./mlx_linux -lmlx_Linux -lXext -lX11 -lm
$(NAME): MLX_DIR = ./mlx_linux
$(NAME): MLX = libmlx.a
endif

$(NAME): $(OBJS) 
	
	@printf "$(CL_LINE)compiler>>>>>>>> $(NONE)\r"
	@$(MAKE) -C $(MLX_DIR)
	@echo "mlx done!"
	@printf "$(CL_LINE)compiler>>>>>>>> $(NONE)\r"
	@$(MAKE) -C ./libft
	@echo "libft done!"
	@cp $(MLX_DIR)/$(MLX) .
	@printf "$(CL_LINE)compiler>>>>>>>> $(NONE)\r"
	@$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) -o $@ $(LFLAGS) $(MFLAGS)
	@echo "cub3d done!"

all: $(NAME)
	
clean:
		@rm -rf $(OBJS)
		@rm -rf $(MLX)
		@$(MAKE) -C ./libft clean
		@echo "Delete>>>>>>"

ifeq ($(shell uname), Linux)
fclean: MLX_DIR = ./mlx_linux
fclean: MLX = libmlx.a
endif

fclean: clean
		@$(MAKE) -C ./libft fclean
		@$(MAKE) -C $(MLX_DIR) clean >/dev/null
		@rm -rf $(MLX)
		@rm -rf $(NAME)
		@echo "Delete all>>>>>>"
		
re: fclean all

%.o: %.c
	
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: all clean fclean re
	
