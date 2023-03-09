CFILES = src/main.c\
		 src/movement.c\
		 src/read_map.c\
		 src/render/render_map.c\
		 src/render/render.c\
		 src/start.c\
		 src/finish.c\
		 src/collectibles.c\
		 src/validate_map.c

LIBFT = libft/libft.a
MLX42 = MLX42/libmlx42.a

NAME = so_long

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42)
#	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) $(MLX42) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/abeltran/.brew/opt/glfw/lib/" -o $(NAME) -g
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME) -g

$(LIBFT):
	@make -C libft

$(MLX42):
	@make -C MLX42/

clean:
	@rm -rf $(NAME)

fclean: clean
	@make fclean -C Libft
	@make clean -C MLX42/

re: fclean all

.PHONY: all clean fclean re