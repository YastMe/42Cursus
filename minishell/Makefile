NAME = minishell

# Colors
GREEN = \033[;32m
RED = \033[1;31m
DEFAULT = \033[;0m

# GCC Compiler variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Folders
SRC = src
OBJ = obj

# Files
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

LIBFT = Libft/libft.a

READLINE_BREW_COMP = -lreadline -L${HOME}/.brew/opt/readline/lib
READLINE_BREW_OBJS = -I${HOME}/.brew/opt/readline/include

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE_BREW_COMP) -o $@
	@echo "$(GREEN)✅ - MINISHELL compiled$(DEFAULT)"

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	@$(CC) $(CFLAGS) $(READLINE_BREW_OBJS) -c $< -o $@

$(OBJ):
	@mkdir obj

$(LIBFT):
	@make -C Libft

clean:
	@make clean -C Libft
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C Libft
	@rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
