NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLIB		= -L$(MLX_DIR) -lmlx -Imlx -framework Metal -framework MetalKit
RM			= rm -f

LIB_DIR		= ./my_libft/
MLX_DIR		= ./mlx/
SRCS_DIR	= ./srcs/

SRCS		= so_long.c \
			  init_utils.c \
			  get_map.c \
			  check_map.c check_valid_map.c \
			  play_game.c \
			  put_image.c press_utils.c \
			  free_all.c error_exit.c
OBJS		= $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))


all			: $(NAME)

%.o		: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME)	: $(OBJS)
	@$(MAKE) -C $(LIB_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@echo $(YELLOW) "✭	[ mlx ]		Ready to use MiniLibX" $(RESET)
	@$(CC) -o $(NAME) $(OBJS) -L$(LIB_DIR) -l_jihykim2 $(MLIB)
	@install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)
	@echo $(GREEN) "⚡︎	[ so_long ]	Ready to use so_long" $(RESET)

clean	:
	@$(MAKE) -C $(dir $(LIB_DIR)) clean
	@echo $(YELLOW) "✭	[ my_libft ]	Removed Object files" $(RESET)
	@$(MAKE) -C $(dir $(MLX_DIR)) clean
	@echo $(YELLOW) "✭	[ mlx ]		Removed Object files" $(RESET)
	@$(RM) $(OBJS)
	@echo $(GREEN) "⚡︎	[ so_long ]	Removed Object files" $(RESET)

fclean	:
	@$(MAKE) clean
	@$(RM) $(LIB_DIR)lib_jihykim2.a
	@echo $(YELLOW) "✭	[ my_libft ]	Removed lib_jihykim2.a" $(RESET)
	@echo $(YELLOW) "✭	[ mlx ]		Removed mlx" $(RESET)
	@$(RM) $(NAME)
	@echo $(GREEN) "⚡︎	[ so_long ]	Removed so_long" $(RESET)

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
