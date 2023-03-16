CFILES = src/main.c\
		 src/movement.c\
		 src/read_map.c\
		 src/render/render_map.c\
		 src/render/render.c\
		 src/start.c\
		 src/finish.c\
		 src/collectibles.c\
		 src/validate_map.c

CBONUS = src_bonus/main.c\
		 src_bonus/movement.c\
		 src_bonus/read_map.c\
		 src_bonus/render/render_map.c\
		 src_bonus/render/render.c\
		 src_bonus/start.c\
		 src_bonus/finish.c\
		 src_bonus/collectibles.c\
		 src_bonus/validate_map.c\
		 src_bonus/traps.c\
		 src_bonus/load_animations.c\
		 src_bonus/render/render_moves.c

LIBFT = Libft/libft.a
MLX42 = MLX42/libmlx42.a

NAME = so_long

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42)
#	MACOS
	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) $(MLX42) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/abeltran/.brew/opt/glfw/lib/" -o $(NAME)
#	Linux
#	@gcc -Wall -Wextra -Werror $(CFILES) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME) -g

bonus: $(LIBFT) $(MLX42)
#	MACOS
	@gcc -Wall -Wextra -Werror $(CBONUS) $(LIBFT) $(MLX42) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/abeltran/.brew/opt/glfw/lib/" -o $(NAME)
#	Linux
#	@gcc -Wall -Wextra -Werror $(CBONUS) $(LIBFT) $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME) -g

$(LIBFT):
	@make -C Libft

$(MLX42):
	@make -C MLX42/

clean:
	@rm -rf $(NAME)

fclean: clean
	@make fclean -C Libft
	@make clean -C MLX42/

re: fclean all

.PHONY: all clean fclean re