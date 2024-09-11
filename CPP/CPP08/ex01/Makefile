CNAMES = main Span

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = src/
OBJ = obj/

CFILES = $(addprefix $(SRC), $(addsuffix .cpp, $(CNAMES)))
OFILES = $(addprefix $(OBJ), $(addsuffix .o, $(CNAMES)))

NAME = span

all: $(NAME)

$(NAME): $(OFILES)
	@clang++ $(CFLAGS) $(OFILES) -o $(NAME)
	@echo "\033[1;32m$(NAME) \033[0;32mcompiled\033[;0m"

$(OFILES): $(CFILES)
	@mkdir -p $(OBJ)
	@clang++ $(CFLAGS) -c $(CFILES)
	@mv *.o $(OBJ)

debug:
	@clang++ $(CFLAGS) -g $(CFILES) -o $(NAME)
	@echo "\033[1;33m$(NAME) \033[0;33mcompiled in debug mode\033[;0m"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re