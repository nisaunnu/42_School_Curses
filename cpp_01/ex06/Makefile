NAME = harlFilter

SRC =	main.cpp	\
		Harl.cpp
OBJ =	obj/main.o	\
		obj/Harl.o

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf
OBJ_DIR = obj

RESET  = \033[0m
GREEN  = \033[38;5;10m
AQUA   = \033[38;5;14m
PINK   = \033[38;5;199m
RED    = \033[38;5;203m
ORANGE = \033[38;5;208m

MSG_DELETE  = "$(RED)$(NAME) has been deleted.$(RESET)\n"
MSG_SUCCESS = "$(GREEN)Compilation of $(NAME) is a success.$(RESET)\n"
MSG_CLEAN   = "\n$(AQUA)$(NAME) object files have been deleted.$(RESET)\n"
MSG_DONE    = "$(GREEN)[$$bar>] 100%$(RESET) - Files $$count/$$total - Compilation completed\n"
MSG_COMPILE = "$(PINK)[$$bar>$$space]$(GREEN)  $$progress%$(RESET) - Files $$count/$$total - Compiling files\n"

define show_progress
	@total=$(words $(SRC)); \
	count=0; \
	for file in $(SRC); do \
		count=$$((count + 1)); \
		progress=$$((count * 100 / total)); \
		bar_length=$$((progress / 2)); \
		bar=$$(printf '=%.0s' $$(seq 1 $$bar_length)); \
		space=$$(printf ' %.0s' $$(seq 1 $$((50 - bar_length)))); \
		echo '\033[2J\033[H'; \
		if [ $$progress -lt 100 ]; then \
			echo $(MSG_COMPILE); \
		else \
			echo $(MSG_DONE); \
		fi; \
		sleep 0.02; \
		$(CC) $(CPPFLAGS) -c $$file -o $(OBJ_DIR)/$$(basename $$file .cpp).o; \
	done;
endef

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(call show_progress)
	@$(CC) $(CPPFLAGS) $^ -o $(NAME)
	@echo $(MSG_SUCCESS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@echo $(MSG_CLEAN)

fclean: clean
	@$(RM) $(NAME)
	@echo $(MSG_DELETE)

re: fclean all

.PHONY: all clean fclean re
