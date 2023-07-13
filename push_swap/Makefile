SRC = src/
SRCCHK = src_checker/
OBJ = obj/push_swap/
CHECKOBJ = obj/checker/

CNAMES = main \
		 fill \
		 ft_atol \
		 clean \
		 move_push \
		 move_swap \
		 move_rotate \
		 move_reverse_rotate \
		 stack_utils \
		 prerequisites \
		 sorting_small \
		 sorting_full \
		 positions \
		 cost

CHECKNAMES = main \
			 fill \
			 stack_utils \
		 	 move_push \
			 move_swap \
			 move_rotate \
		 	 move_reverse_rotate \
			 clean \
			 prerequisites \
			 ft_atol

CFILES = $(addprefix $(SRC), $(addsuffix .c, $(CNAMES)))
OFILES = $(addprefix $(OBJ), $(addsuffix .o, $(CNAMES)))
CHECKFILES = $(addprefix $(SRCCHK), $(addsuffix .c, $(CHECKNAMES)))
OCHECK = $(addprefix $(CHECKOBJ), $(addsuffix .o, $(CHECKNAMES)))

LIBFT = Libft/libft.a

NAME = push_swap

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT)
	@gcc -Wall -Wextra -Werror $(OFILES) $(LIBFT) -o $(NAME)

$(OFILES): $(CFILES)
	@mkdir -p $(OBJ)
	@gcc -Wall -Wextra -Werror -c $(CFILES)
	@mv *.o $(OBJ)

$(LIBFT):
	@make -C Libft

checker: $(OCHECK) $(LIBFT)
	@gcc -Wall -Wextra -Werror $(OCHECK) $(LIBFT) -o checker

$(OCHECK): $(CHECKFILES)
	@mkdir -p $(CHECKOBJ)
	@gcc -Wall -Wextra -Werror -c $(CHECKFILES)
	@mv *.o $(CHECKOBJ)

debug: $(LIBFT)
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) -o $(NAME) -g

clean:
	@rm -rf $(NAME)
	@rm -rf obj/
	@rm checker

fclean: clean
	@make fclean -C Libft

re: fclean all

py:	all
	python3 python_visualizer.py `ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`

.PHONY: all clean fclean re debug py