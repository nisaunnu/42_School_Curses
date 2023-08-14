# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 14:48:26 by nunnu             #+#    #+#              #
#    Updated: 2023/07/31 04:42:15 by nunnu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf
AR			=	ar rcs

SRC			=	ft_printf.c			\
				ft_printf_utils.c
OBJ			=	$(SRC:.c=.o)

GREEN  		= 	\033[32;1m
RED     	= 	\033[31;49;1m
YELLOW  	= 	\033[33;49;1m
RESET   	= 	\033[0m

all: $(NAME)

%.o: %.c
	@gcc -c $< -o $@ > /dev/null 2>&1 || (echo "	$(RED) $< :  KO $(RESET)\n"; false)
	@echo "	$< : $(GREEN) OK $(RESET)"

$(NAME): $(OBJ)
	@ar rc $(NAME) *.o
	@echo "\n	🟢$(GREEN) $@ built $(RESET)\n"

clean:
	@/bin/rm -f  *.o
	@echo "\n	🟡$(YELLOW) object files removed $(RESET)\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "	🟡$(YELLOW) static library removed $(RESET)\n"

re: fclean all

.PHONY: all bonus clean fclean re
