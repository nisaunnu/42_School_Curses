# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 17:56:37 by nunnu             #+#    #+#              #
#    Updated: 2024/02/22 11:16:50 by nunnu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ_DIR = ./obj
INC_DIR = ./inc
SRC_DIR = ./src
LIBFT_SRC_DIR = src/libft
PRINFT_SRC_DIR = src/ft_printf
GNL_SRC_DIR = src/get_next_line

LIBFT_SRC = $(LIBFT_SRC_DIR)/ft_isalpha.c		\
			$(LIBFT_SRC_DIR)/ft_isdigit.c		\
			$(LIBFT_SRC_DIR)/ft_isalnum.c		\
			$(LIBFT_SRC_DIR)/ft_isascii.c		\
			$(LIBFT_SRC_DIR)/ft_isprint.c		\
			$(LIBFT_SRC_DIR)/ft_strlen.c		\
			$(LIBFT_SRC_DIR)/ft_memset.c		\
			$(LIBFT_SRC_DIR)/ft_bzero.c			\
			$(LIBFT_SRC_DIR)/ft_memcpy.c		\
			$(LIBFT_SRC_DIR)/ft_memmove.c		\
			$(LIBFT_SRC_DIR)/ft_strlcpy.c		\
			$(LIBFT_SRC_DIR)/ft_strlcat.c		\
			$(LIBFT_SRC_DIR)/ft_toupper.c		\
			$(LIBFT_SRC_DIR)/ft_tolower.c		\
			$(LIBFT_SRC_DIR)/ft_strchr.c		\
			$(LIBFT_SRC_DIR)/ft_strrchr.c		\
			$(LIBFT_SRC_DIR)/ft_strncmp.c		\
			$(LIBFT_SRC_DIR)/ft_memchr.c		\
			$(LIBFT_SRC_DIR)/ft_memcmp.c		\
			$(LIBFT_SRC_DIR)/ft_strnstr.c		\
			$(LIBFT_SRC_DIR)/ft_atoi.c 			\
			$(LIBFT_SRC_DIR)/ft_calloc.c		\
			$(LIBFT_SRC_DIR)/ft_strdup.c		\
			$(LIBFT_SRC_DIR)/ft_substr.c		\
			$(LIBFT_SRC_DIR)/ft_strjoin.c		\
			$(LIBFT_SRC_DIR)/ft_strtrim.c		\
			$(LIBFT_SRC_DIR)/ft_split.c			\
			$(LIBFT_SRC_DIR)/ft_itoa.c 			\
			$(LIBFT_SRC_DIR)/ft_strmapi.c		\
			$(LIBFT_SRC_DIR)/ft_striteri.c		\
			$(LIBFT_SRC_DIR)/ft_putchar_fd.c	\
			$(LIBFT_SRC_DIR)/ft_putstr_fd.c		\
			$(LIBFT_SRC_DIR)/ft_putendl_fd.c	\
			$(LIBFT_SRC_DIR)/ft_putnbr_fd.c		\
			$(LIBFT_SRC_DIR)/ft_lstnew.c		\
			$(LIBFT_SRC_DIR)/ft_lstadd_front.c	\
			$(LIBFT_SRC_DIR)/ft_lstsize.c		\
			$(LIBFT_SRC_DIR)/ft_lstlast.c		\
			$(LIBFT_SRC_DIR)/ft_lstadd_back.c	\
			$(LIBFT_SRC_DIR)/ft_lstdelone.c		\
			$(LIBFT_SRC_DIR)/ft_lstclear.c		\
			$(LIBFT_SRC_DIR)/ft_lstiter.c		\
			$(LIBFT_SRC_DIR)/ft_lstmap.c

PRINTF_SRC = $(PRINFT_SRC_DIR)/ft_printf.c		\
			 $(PRINFT_SRC_DIR)/ft_printf_utils.c

GNL_SRC = $(GNL_SRC_DIR)/get_next_line.c		\
		  $(GNL_SRC_DIR)/get_next_line_bonus.c	\
		  $(GNL_SRC_DIR)/get_next_line_utils.c	\
		  $(GNL_SRC_DIR)/get_next_line_utils_bonus.c

SRC = $(LIBFT_SRC) $(PRINTF_SRC) $(GNL_SRC)

LIBFT_OBJ = $(LIBFT_SRC:$(LIBFT_SRC_DIR)%.c=$(OBJ_DIR)/libft/%.o)
PRINFT_OBJ = $(PRINTF_SRC:$(PRINFT_SRC_DIR)%.c=$(OBJ_DIR)/ft_printf/%.o)
GNL_OBJ = $(GNL_SRC:$(GNL_SRC_DIR)%.c=$(OBJ_DIR)/get_next_line/%.o)
OBJ = $(LIBFT_OBJ) $(PRINFT_OBJ) $(GNL_OBJ)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

all: $(NAME)

$(OBJ_DIR)/libft/%.o: $(LIBFT_SRC_DIR)/%.c
	@ mkdir -p $(OBJ_DIR)/libft
	@ $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/ft_printf/%.o: $(PRINFT_SRC_DIR)/%.c
	@ mkdir -p $(OBJ_DIR)/ft_printf
	@ $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/get_next_line/%.o: $(GNL_SRC_DIR)/%.c
	@ mkdir -p $(OBJ_DIR)/get_next_line
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
