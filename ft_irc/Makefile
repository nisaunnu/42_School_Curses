NAME    = ircserv

INC_DIR = inc/
SRC_DIR = src/
OBJ_DIR = obj/

INC	= $(INC_DIR)Bot.hpp					\
	  $(INC_DIR)Channel.hpp				\
	  $(INC_DIR)Client.hpp				\
	  $(INC_DIR)Command.hpp				\
	  $(INC_DIR)ErrorCodes.hpp			\
	  $(INC_DIR)FileTransfer.hpp		\
	  $(INC_DIR)FileTransferCommand.hpp	\
	  $(INC_DIR)SendFile.hpp			\
	  $(INC_DIR)Server.hpp				\
	  $(INC_DIR)Utils.hpp

SRC	= $(SRC_DIR)cmd/Invite.cpp			\
	  $(SRC_DIR)cmd/Join.cpp			\
	  $(SRC_DIR)cmd/Kick.cpp			\
	  $(SRC_DIR)cmd/Mode.cpp			\
	  $(SRC_DIR)cmd/Nick.cpp			\
	  $(SRC_DIR)cmd/Pass.cpp			\
	  $(SRC_DIR)cmd/PrivMsg.cpp			\
	  $(SRC_DIR)cmd/Quit.cpp			\
	  $(SRC_DIR)cmd/SendFile.cpp		\
	  $(SRC_DIR)cmd/Topic.cpp			\
	  $(SRC_DIR)cmd/User.cpp			\
	  $(SRC_DIR)cmd/Who.cpp				\
	  $(SRC_DIR)Bot.cpp					\
	  $(SRC_DIR)Channel.cpp				\
	  $(SRC_DIR)Client.cpp				\
	  $(SRC_DIR)ErrorCodes.cpp			\
	  $(SRC_DIR)FileTransfer.cpp		\
	  $(SRC_DIR)FileTransferCommand.cpp	\
	  $(SRC_DIR)main.cpp				\
	  $(SRC_DIR)parser.cpp				\
	  $(SRC_DIR)Server.cpp				\
	  $(SRC_DIR)signals.cpp				\
	  $(SRC_DIR)Utils.cpp

OBJ = $(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
DEP = $(OBJ:.o=.d)

CPP      = c++
DEPFLAGS = -MMD -MP
CFLAGS   = -Wall -Wextra -Werror -std=c++98

RESET  = \033[0m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/cmd
	@mkdir -p $(OBJ_DIR)/bot

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp Makefile
	@$(CPP) $(CFLAGS) $(DEPFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(BLUE)-> $<$(RESET)"

$(NAME): $(OBJ)
	@$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\n$(GREEN)$(NAME) made$(RESET)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\n$(YELLOW)objects removed$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@echo "$(YELLOW)$(NAME) removed$(RESET)\n"

re:	fclean all

-include $(DEP)

.PHONY:	all clean fclean re
