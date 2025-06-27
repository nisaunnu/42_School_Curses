# Variables
COMPOSE_FILE = srcs/docker-compose.yml
DATA_PATH = /home/$(USER)/data

# Default target
all: build

# Create data directories
setup:
	@mkdir -p $(DATA_PATH)/wordpress
	@mkdir -p $(DATA_PATH)/mariadb

# Build and start containers
build: setup
	@docker-compose -f $(COMPOSE_FILE) up -d --build

# Start containers
up:
	@docker-compose -f $(COMPOSE_FILE) up -d

# Stop containers
down:
	@docker-compose -f $(COMPOSE_FILE) down

# Clean everything
clean: down
	@docker system prune -af
	@docker volume prune -f

# Full clean including data
fclean: clean
	@sudo rm -rf $(DATA_PATH)
	@docker volume rm $$(docker volume ls -q) 2>/dev/null || true

# Rebuild everything
re: fclean build

# Show logs
logs:
	@docker-compose -f $(COMPOSE_FILE) logs -f

# Show status
status:
	@docker-compose -f $(COMPOSE_FILE) ps

.PHONY: all setup build up down clean fclean re logs status
