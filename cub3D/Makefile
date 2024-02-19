# Files Setup
NAME = cub3D

SRC_DIR = src
OBJ_DIR = obj

MLX = MLX42/libmlx42.a
LIBFT = libft/libft.a

CFILES = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(CFILES))

# Compiler Commands
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

# Colors

GRE = \033[;32m
DEF = \033[;0m

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
MLXFLAGS = -Iinclude -ldl -lglfw -pthread -lm
$(warning Linux detected! Changing MLX flags...)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES) | $(MLX) $(LIBFT)
	@echo "$(GRE)Linking object files and creating binary($(NAME))...$(DEF)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(MLX) $(LIBFT) $(MLXFLAGS) -o $(NAME)
	@clear

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(GRE)Compiling $<\t>> $@$(DEF)"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(MLX):
	@make -C MLX42

$(LIBFT):
	@make -C libft

clean:
	@rm -rf $(OBJ_DIR)
	@make fclean -C MLX42
	@make fclean -C libft
	@clear

fclean: clean
	@rm $(NAME)
	@clear

full: re
	@clear
	@./$(NAME) scenes/sphere.rt

re: fclean all

.PHONY : all clean fclean full re
