# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 17:55:08 by nunnu             #+#    #+#              #
#    Updated: 2024/02/10 17:55:09 by nunnu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# ----- LIBRARY ----- #
HEADER = ./inc/philo.h

# ----- PATH ----- #
SRC_PATH = ./src
OBJ_DIR  = ./obj
INC_PATH = -I(HEADER)

# ----- SOURCE & OBJECT FILES ----- #
SRC = checker.c			\
	  flag_control.c	\
	  free.c			\
	  init.c			\
	  libft_utils.c		\
	  life_cycle.c		\
	  main.c			\
	  parsing.c			\
	  philo_thread.c	\
	  print.c			\
	  time.c
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# ----- COMPILING VARIABLES ----- #
CC     = cc
CFLAGS = -Wall -Wextra -Werror

# ----- COLORS ----- #
GREEN  = \033[32;1m
RED    = \033[31;49;1m
YELLOW = \033[33;49;1m
RESET  = \033[0m

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.c
	@ mkdir -p $(OBJ_DIR)
	@ $(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ)
	@ echo "\n	🟡$(YELLOW) Compilation of $(NAME) ... $(RESET)"
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@ echo "\n	🟢$(GREEN) $(NAME) created $(RESET)\n"

norm:
	@ echo "\n"
	@ norminette $(SRC_PATH) $(HEADER); \
	if [ $$? -eq 0 ]; then \
		echo "\n🟢$(GREEN) Norminette check passed!$(RESET)\n\n"; \
	else \
		echo "\n🔴$(RED) Norminette check failed!$(RESET)\n\n"; \
	fi

clean:
	@ rm -rf $(OBJ_DIR)
	@ echo "\n	🔴$(RED) Delete : objects $(RESET)\n"

fclean: clean
	@ rm -f $(NAME)
	@ echo "	🔴$(RED) Delete : $(NAME) $(RESET)\n"

re: fclean all

.PHONY: all mandatory norm clean fclean re
