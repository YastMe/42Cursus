# Files Setup
NAME = ircserv

SRC_DIR = src
OBJ_DIR = obj

CFILES = $(shell find $(SRC_DIR) -type f -name '*.cpp')
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CFILES))

# Compiler Commands
CC = clang++
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

# Colors

GRE = \033[;32m
DEF = \033[;0m

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
$(warning Linux detected! Changing flags...)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@clear

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)
	@clear

fclean: clean
	@rm $(NAME)
	@clear

re: fclean all

.PHONY : all clean fclean re
