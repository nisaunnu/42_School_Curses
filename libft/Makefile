# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nunnu <nunnu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 17:56:37 by nunnu             #+#    #+#              #
#    Updated: 2023/07/24 14:56:09 by nunnu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_isalpha.c	\
	ft_isdigit.c 		\
	ft_isalnum.c 		\
	ft_isascii.c 		\
	ft_isprint.c 		\
	ft_strlen.c 		\
	ft_memset.c 		\
	ft_bzero.c			\
	ft_memcpy.c 		\
	ft_memmove.c 		\
	ft_strlcpy.c 		\
	ft_strlcat.c 		\
	ft_toupper.c 		\
	ft_tolower.c 		\
	ft_strchr.c 		\
	ft_strrchr.c 		\
	ft_strncmp.c 		\
	ft_memchr.c 		\
	ft_memcmp.c 		\
	ft_strnstr.c 		\
	ft_atoi.c 			\
	ft_calloc.c 		\
	ft_strdup.c 		\
	ft_substr.c 		\
	ft_strjoin.c 		\
	ft_strtrim.c 		\
	ft_split.c 			\
	ft_itoa.c 			\
	ft_strmapi.c 		\
	ft_striteri.c 		\
	ft_putchar_fd.c 	\
	ft_putstr_fd.c 		\
	ft_putendl_fd.c 	\
	ft_putnbr_fd.c

BONUS = ft_lstnew.c 	\
	ft_lstadd_front.c 	\
	ft_lstsize.c 		\
	ft_lstlast.c 		\
	ft_lstadd_back.c 	\
	ft_lstdelone.c 		\
	ft_lstclear.c 		\
	ft_lstiter.c 		\
	ft_lstmap.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

GREEN   = \033[32;1m
RED     = \033[31;49;1m
YELLOW  = \033[33;49;1m
RESET   = \033[0m

all: $(NAME)

%.o: %.c
	@gcc -c $< -o $@ > /dev/null 2>&1 || (echo "	$(RED) $< :  KO $(RESET)\n"; false)
	@echo "	$< : $(GREEN) OK $(RESET)"

$(NAME): $(OBJ)
	@ar rc $(NAME) *.o
	@echo "\n	🟢$(GREEN) $@ built $(RESET)\n"

bonus: $(BONUS_OBJ)
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
