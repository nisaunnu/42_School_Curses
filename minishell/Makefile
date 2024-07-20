NAME = minishell
CC = gcc -g3
CFLAGS = -Wall -Werror -Wextra -Iinc
LDFLAGS = -lreadline
LIBFT_DIR = inc/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
SRC_DIR = src/
OBJ_DIR = obj/

SRCS =	$(SRC_DIR)aux_ft/array_size.c			\
		$(SRC_DIR)aux_ft/check_malloc.c			\
		$(SRC_DIR)aux_ft/cmd_split.c			\
		$(SRC_DIR)aux_ft/env_utils.c			\
		$(SRC_DIR)aux_ft/ft_strncpy.c			\
		$(SRC_DIR)aux_ft/my_strndup.c			\
		$(SRC_DIR)aux_ft/get_path.c				\
		$(SRC_DIR)aux_ft/here_doc_env.c			\
		$(SRC_DIR)aux_ft/input_split.c			\
		$(SRC_DIR)aux_ft/my_calloc.c			\
		$(SRC_DIR)aux_ft/my_itoa.c				\
		$(SRC_DIR)aux_ft/my_strdup.c			\
		$(SRC_DIR)aux_ft/my_strjoin.c			\
		$(SRC_DIR)aux_ft/quotes.c				\
		$(SRC_DIR)aux_ft/utils.c				\
		$(SRC_DIR)aux_ft/ft_isnumeric.c			\
		$(SRC_DIR)aux_ft/ft_isspace.c			\
		$(SRC_DIR)aux_ft/ft_free_arrays.c		\
		$(SRC_DIR)aux_ft/exit_status.c			\
		$(SRC_DIR)aux_ft/ft_strcmp.c			\
    	$(SRC_DIR)builtin/cd.c					\
    	$(SRC_DIR)builtin/echo.c				\
		$(SRC_DIR)builtin/env.c					\
		$(SRC_DIR)builtin/exit.c				\
    	$(SRC_DIR)builtin/export.c				\
    	$(SRC_DIR)builtin/export_two.c			\
    	$(SRC_DIR)builtin/handle_builtin.c		\
    	$(SRC_DIR)builtin/pwd.c					\
		$(SRC_DIR)builtin/unset.c				\
		$(SRC_DIR)execute/execute_utils.c 		\
    	$(SRC_DIR)execute/execute.c 			\
		$(SRC_DIR)execute/heredoc.c				\
		$(SRC_DIR)execute/pipe_utils_two.c		\
		$(SRC_DIR)execute/pipe_utils.c			\
		$(SRC_DIR)execute/pipe.c				\
		$(SRC_DIR)execute/programs.c			\
		$(SRC_DIR)execute/redirect.c			\
		$(SRC_DIR)input/ast_node.c				\
		$(SRC_DIR)input/ast_utils.c				\
		$(SRC_DIR)input/ast.c					\
		$(SRC_DIR)input/envp.c					\
		$(SRC_DIR)input/input.c					\
		$(SRC_DIR)input/lexer.c 				\
		$(SRC_DIR)input/token.c 				\
		$(SRC_DIR)input/token_utils.c 			\
		$(SRC_DIR)main/main.c 					\
    	$(SRC_DIR)main/minishell.c				\
    	$(SRC_DIR)signal/signal.c 				\
		$(SRC_DIR)bonus/wildcards_two.c			\
		$(SRC_DIR)bonus/wildcards.c				\

OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

GREEN   = \033[32;1m
YELLOW  = \033[33;1m
RED     = \033[31;1m
RESET   = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@ echo "\n\t$(YELLOW)compilation of $(NAME) ... $(RESET)"
	@ $(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)
	@ echo "$(GREEN)\n\t$(NAME) created\n$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@ echo "$(RED)\n\tobject files removed\n$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@ echo "$(RED)\texecutable file removed\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re
