#DATABASE
DB_NAME = db_$(subst .,_,$(DOMAIN_NAME))
DB_USER=
DB_PASS:=$(shell openssl rand -base64 12)
DB_ROOT_PASS:=$(shell openssl rand -base64 12)

#WORDPRESS
ADMIN_USER=abeltran
ADMIN_PASS:=$(shell openssl rand -base64 12)
ADMIN_EMAIL=
USER_PASS=$(shell openssl rand -base64 12)

#DOMAIN
DOMAIN_NAME=abeltran.42.fr

#VOLUMES
VOLUMES_DIR=/home/abeltran/data/volumes
WP_VOLUME=$(VOLUMES_DIR)/web
DB_VOLUME=$(VOLUMES_DIR)/db
VOLUMES = $(WP_VOLUME) $(DB_VOLUME)

#VOLUME REFERENCES
VOLUME_REF = ./volumes

#ENVS
ENV_GENERAL=srcs/.env_general
ENV_DB=srcs/.env_db
ENV_WORDPRESS=srcs/.env_wordpress
ENVS = $(ENV_DB) $(ENV_GENERAL) $(ENV_WORDPRESS)

# Color Variables
GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
BOLD = \033[1m
RESET = \033[0m


all: clear_term up

clear_term:
	@clear

envs: $(ENVS)

up: $(ENVS) $(VOLUME_REF) $(VOLUMES)
	@echo "${GREEN}Starting services...${RESET}"
	@sudo docker compose -f ./srcs/docker-compose.yml up --build -d --remove-orphans
	@echo "${GREEN}Services started${RESET}"

down: $(ENVS)
	@echo "${GREEN}Stopping services...${RESET}"
	@sudo docker compose -f ./srcs/docker-compose.yml down --volumes --remove-orphans
	@echo "${GREEN}Services stopped${RESET}"

volrm:
	@echo "${RED}${BOLD}Removing volumes...${RESET}"
	@sudo docker system prune -af --volumes
	@sudo docker volume rm $(shell docker volume ls -qf dangling=true)   
	@sudo rm -rf ${VOLUMES_DIR}
	@echo "${YELLOW}Volumes removed${RESET}"

clean:
	@echo "${RED}${BOLD}Removing containers...${RESET}"
	@sudo docker compose -f srcs/docker-compose.yml down
	@sudo docker compose -f srcs/docker-compose.yml rm -f
	@echo "${YELLOW}Containers removed${RESET}"

fclean: clean cold_clean 
	@echo "${RED}${BOLD}Removing volumes...${RESET}"
	@sudo rm -rf ${VOLUMES_DIR}
	@sudo rm -rf ${VOLUME_REF}
	@sudo rm -rf ${ENVS}
	@echo "${YELLOW}Volumes removed${RESET}"
	@echo "${RED}${BOLD}Removing environment files...${RESET}"
	@sudo rm -rf ${ENVS}
	@echo "${YELLOW}Environment files removed${RESET}"

logs: clear_term
	@sudo docker compose -f ./srcs/docker-compose.yml logs

re: down up

fre: fclean all

ps:
	@docker compose -f ./srcs/docker-compose.yml ps

prune:
	@echo "${RED}${BOLD}Pruning docker...${RESET}"
	@docker system prune -a -f
	@echo "${YELLOW}Docker pruned${RESET}"

$(ENV_GENERAL):
	@echo "${GREEN}Creating general environment file...${RESET}"
	@echo "DOMAIN_NAME=$(DOMAIN_NAME)" > $(ENV_GENERAL)

$(ENV_DB):
	@echo "${GREEN}Creating database environment file...${RESET}"
	@echo "DB_NAME=$(DB_NAME)" > $(ENV_DB)
	@echo "DB_USER=$(DB_USER)" >> $(ENV_DB)
	@echo "DB_PASS=$(DB_PASS)" >> $(ENV_DB)
	@echo "DB_ROOT_PASS=$(DB_ROOT_PASS)" >> $(ENV_DB)

$(ENV_WORDPRESS):
	@echo "${GREEN}Creating wordpress environment file...${RESET}"
	@echo "ADMIN_USER=$(ADMIN_USER)" > $(ENV_WORDPRESS)
	@echo "ADMIN_PASS=$(ADMIN_PASS)" >> $(ENV_WORDPRESS)
	@echo "ADMIN_EMAIL=$(ADMIN_EMAIL)" >> $(ENV_WORDPRESS)

$(VOLUMES_DIR):
	@echo "${GREEN}Creating volumes real directory...${RESET}"
	@mkdir -p $(VOLUMES_DIR)

$(VOLUMES):
	@echo "${GREEN}Creating volumes linked directory...${RESET}"
	@mkdir -p $(VOLUMES)

$(VOLUME_REF):
	@echo "${GREEN}Creating volumes reference...${RESET}"
	@ln -s $(VOLUMES_DIR) $(VOLUME_REF)

cold_clean:
	@echo "${RED}${BOLD}Removing volumes...${RESET}"
	@sudo rm -rf ${VOLUMES_DIR}
	@sudo rm -rf ${VOLUME_REF}
	@sudo rm -rf ${ENVS}
	@echo "${YELLOW}Volumes removed${RESET}"
	@echo "${RED}${BOLD}Removing environment files...${RESET}"
	@sudo rm -rf ${ENVS}
	@echo "${YELLOW}Environment files removed${RESET}"
	@clear

.PHONY: all up down clean fclean logs re prune clear_term fre ps volrm cold_clean
