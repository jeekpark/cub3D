# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihykim2 <jihykim2@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 04:11:59 by jihykim2          #+#    #+#              #
#    Updated: 2023/11/23 23:15:01 by jihykim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= cc
CFLAGS		= #-Wall -Wextra -Werror #-fsanitize=address
MLIB		= -L$(MLX_DIR) -lmlx -Imlx -framework Cocoa -framework Metal -framework MetalKit -framework QuartzCore
# MLIB		= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
RM			= rm -f

LIB_DIR		= ./libft/
MLX_DIR		= ./mlx/

PARSE_DIR	= ./parsing/
SRCS_PARSE	= check_argument.c \
			  init_game_info.c \
			  init_content_info.c \
			  init_texture_info.c \
			  init_map_info.c \
			  check_valid_map.c \
			  init_player_info.c \
			  get_next_line.c \
			  free_func.c \
			  utils.c
OBJS_PARSE	= $(addprefix $(PARSE_DIR), $(SRCS_PARSE:.c=.o))

EXEC_DIR	= ./ray_casting/
SRCS_EXEC	= play_game.c \
			  init_mlx.c \
			  key_hook.c \
			  rotate.c \
			  move.c \
			  calculate_vector_in_image.c \
			  find_wall_from_player.c \
			  calculate_length_of_ray.c \
			  calculate_length_of_wall.c \
			  draw.c \
			  exit_game.c \
				draw_background.c \
				get_color_in_texture.c \
				mapping_int.c \
				my_mlx_pixel_put.c
				
OBJS_EXEC	= $(addprefix $(EXEC_DIR), $(SRCS_EXEC:.c=.o))

SRCS		= cub3d.c $(SRCS_PARSE) $(SRCS_EXEC)
OBJS		= cub3d.o $(OBJS_PARSE) $(OBJS_EXEC)

all		: $(NAME)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -j 1 -C $(MLX_DIR) 2>/dev/null
	@echo $(YELLOW) "✭	[ mlx ]		Ready to use MiniLibX" $(RESET)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIB_DIR) -lft $(MLIB)
	@install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)
	@echo $(GREEN) "⚡︎	[ cub3D ]	Ready to run cub3D" $(RESET)

clean	:
	@$(MAKE) -C $(LIB_DIR) clean
	@echo $(YELLOW) "✭	[ libft ]	Removed Object files" $(RESET)
	@$(MAKE) -C $(MLX_DIR) clean
	@echo $(YELLOW) "✭	[ mlx ]		Removed Object files" $(RESET)
	@$(RM) $(OBJS)
	@echo $(GREEN) "⚡︎	[ cub3D ]	Removed Object files" $(RESET)

fclean	:
	@$(MAKE) clean
	@$(RM) $(LIB_DIR)libft.a
	@echo $(YELLOW) "✭	[ libft ]	Removed libft.a" $(RESET)
	@echo $(YELLOW) "✭	[ mlx ]		Removed mlx" $(RESET)
	@$(RM) $(NAME)
	@echo $(GREEN) "⚡︎	[ cub3D ]	Removed cub3D" $(RESET)

re		:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY	: all clean fclean re

RESET	= "\x1b[0m"
GREY	= "\x1b[30m"
RED		= "\x1b[31m"
GREEN	= "\x1b[32m"
YELLOW	= "\x1b[33m"
BLUE	= "\x1b[34m"
PURPLE	= "\x1b[35m"
CYAN	= "\x1b[36m"
WHITE	= "\x1b[37m"
