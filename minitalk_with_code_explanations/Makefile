# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nunnu <nunnu@student.42kocaeli.com.tr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 17:33:13 by nunnu             #+#    #+#              #
#    Updated: 2023/10/15 17:33:13 by nunnu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# library names #
CLIENT = client
SERVER = server

# client & server variables #
SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_UTILS = minitalk_utils.c

# compiling variables #
CC     = gcc
CFLAGS = -Wall -Wextra -Werror
RM     = rm -f

# colors #
GREEN   = \033[32;1m
RED     = \033[31;49;1m
YELLOW  = \033[33;49;1m
RESET   = \033[0m

all: $(SERVER) $(CLIENT)

# building & building info #
$(SERVER): $(SRC_SERVER)
	@ $(CC) $(CFLAGS) $(SRC_UTILS) $(SRC_SERVER) -o $(SERVER)
	@echo "\n	🟢$(GREEN) server built $(RESET)"
$(CLIENT): $(SRC_CLIENT)
	@ $(CC) $(CFLAGS) $(SRC_UTILS) $(SRC_CLIENT) -o $(CLIENT)
	@echo "\n	🟢$(GREEN) client built $(RESET)\n"

# cleaning #
clean:
	@ $(RM) $(CLIENT) $(SERVER)
	@echo "\n	🟡$(YELLOW) server removed $(RESET)"
	@echo "\n	🟡$(YELLOW) client removed $(RESET)\n"
fclean:
	@ $(RM) $(CLIENT) $(SERVER)
	@echo "\n	🟡$(YELLOW) server removed $(RESET)"
	@echo "\n	🟡$(YELLOW) client removed $(RESET)\n"

# cleaning and rebuild #
re: fclean all

# The names of the targets in .PHONY are not the names of the actual files. #
.PHONY: all clean fclean re
