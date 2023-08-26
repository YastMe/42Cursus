CNAMES = philosophers\
		ft_atoi\
		checks\
		init_data\
		utils\
		time\
		philo_life\
		clean

OBJ = obj/

CFILES = $(addprefix $(SRC), $(addsuffix .c, $(CNAMES)))
OFILES = $(addprefix $(OBJ), $(addsuffix .o, $(CNAMES)))

LIBFT = Libft/libft.a

NAME = philo

all: $(NAME)

$(NAME): $(OFILES)
	@gcc -Wall -Wextra -Werror $(OFILES) -o $(NAME)

$(OFILES): $(CFILES)
	@mkdir -p $(OBJ)
	@gcc -Wall -Wextra -Werror -c $(CFILES)
	@mv *.o $(OBJ)

debug:
	@gcc -Wall -Wextra -Werror $(CFILES) -g -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re debug