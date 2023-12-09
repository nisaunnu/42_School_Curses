# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 02:51:01 by nunnu             #+#    #+#              #
#    Updated: 2023/12/06 20:44:20 by nunnu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# ----- LIBRARY ----- #
HEADER  = fractol.h
MLX_LIB = $(MLX_PATH)/libmlx.a

# ----- PATH ----- #
MLX_PATH = ./mlx_opengl
INC_PATH = -I$(MLX_PATH) -I$(HEADER)

# ----- SOURCE & OBJECT FILES ----- #
SRC  = main.c 						\
	   draw.c 						\
	   mandelbrot.c 				\
	   julia.c 						\
	   parsing.c 					\
	   setup.c 						\
	   events.c 					\
	   burning_ship.c 				\
	   libft_utils.c
OBJ = $(SRC:.c=.o)

# ----- COMPILING VARIABLES ----- #
CC        = gcc
CFLAGS    = -Wall -Wextra -Werror
MLX_FLAGS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit

# ----- COLORS ----- #
GREEN   = \033[32;1m
RED     = \033[31;49;1m
YELLOW  = \033[33;49;1m
CYAN    = \033[36;1m
RESET   = \033[0m

all: mandatory

.c.o:
	@ ${CC} ${FLAGS} -c $< -o ${<:.c=.o}

mandatory: $(OBJ)
	@ echo "\n	🟡$(YELLOW) Compilation of $(NAME) ... $(RESET)"

	@ $(MAKE) -sC $(MLX_PATH) >/dev/null 2>&1
	@ echo "\n	🟢$(GREEN) minilibx created $(RESET)"

	@ $(CC) -o $(NAME) $(OBJ) $(MLX_FLAGS)
	@ echo "\n	🟢$(GREEN) $(NAME) created $(RESET)\n"

bonus: all
	@ echo "	🟢$(GREEN) bonus created $(RESET)\n"

norm:
	@ echo "\n"
	@ norminette $(SRC) $(HEADER); \
	if [ $$? -eq 0 ]; then \
		echo "\n🟢$(GREEN) Norminette check passed!$(RESET)\n\n"; \
	else \
		echo "\n🔴$(RED) Norminette check failed!$(RESET)\n\n"; \
	fi

clean:
	@ $(MAKE) -sC $(MLX_PATH) clean
	@ rm -rf *.o
	@ echo "\n	🔴$(RED) Delete : objects $(RESET)\n"

fclean: clean
	@ rm -f $(MLX_LIB)
	@ echo "	🔴$(RED) Delete : $(MLX_LIB) $(RESET)"
	@ rm -f $(NAME)
	@ echo "\n	🔴$(RED) Delete : $(NAME) $(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
