CNAMES = Account tests

CFLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = obj/

CFILES = $(addsuffix .cpp, $(CNAMES))
OFILES = $(addprefix $(OBJ), $(addsuffix .o, $(CNAMES)))

NAME = accounts

all: $(NAME)

$(NAME): $(OFILES)
	@c++ $(CFLAGS) $(OFILES) -o $(NAME)
	@echo "Accounts compiled"

$(OFILES): $(CFILES)
	@mkdir -p $(OBJ)
	@c++ $(CFLAGS) -c $(CFILES)
	@mv *.o $(OBJ)

debug: fclean
	@c++ $(CFLAGS) -g $(CFILES) -o $(NAME)
	@echo "Accounts compiled in debug mode"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re