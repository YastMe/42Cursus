LIBFT_NAMES = ft_atoi\
ft_bzero\
ft_calloc\
ft_isalnum\
ft_isalpha\
ft_isascii\
ft_isdigit\
ft_isprint\
ft_itoa\
ft_memchr\
ft_memcmp\
ft_memcpy\
ft_memmove\
ft_memset\
ft_putchar_fd\
ft_putendl_fd\
ft_putnbr_fd\
ft_putstr_fd\
ft_split\
ft_strchr\
ft_strdup\
ft_striteri\
ft_strjoin\
ft_strlcat\
ft_strlcpy\
ft_strlen\
ft_strmapi\
ft_strncmp\
ft_strnstr\
ft_strrchr\
ft_strtrim\
ft_substr\
ft_strcmp\
ft_tolower\
ft_toupper\
ft_lstadd_back\
ft_lstadd_front\
ft_lstclear\
ft_lstdelone\
ft_lstiter\
ft_lstlast\
ft_lstmap\
ft_lstnew\
ft_lstsize

PRINTF_NAMES = ft_printf\
ft_putstrn\
ft_putptrn\
ft_putnbrn\
ft_putunsignedn\
ft_puthexn\
ft_putpercentage

GET_NEXT_LINE_NAMES = get_next_line\
get_next_line_utils



LIBFT_SRC = src/libft/
LIBFT_OBJ = obj/libft/

PRINTF_SRC = src/printf/
PRINTF_OBJ = obj/printf/

GET_NEXT_LINE_SRC = src/get_next_line/
GET_NEXT_LINE_OBJ = obj/get_next_line/



LIBFT_FILES = $(addprefix $(LIBFT_SRC), $(addsuffix .c, $(LIBFT_NAMES)))
LIBFT_OBJECT = $(addprefix $(LIBFT_OBJ), $(addsuffix .o, $(LIBFT_NAMES)))

PRINTF_FILES = $(addprefix $(PRINTF_SRC), $(addsuffix .c, $(PRINTF_NAMES)))
PRINTF_OBJECT = $(addprefix $(PRINTF_OBJ), $(addsuffix .o, $(PRINTF_NAMES)))

GET_NEXT_LINE_FILES = $(addprefix $(GET_NEXT_LINE_SRC), $(addsuffix .c, $(GET_NEXT_LINE_NAMES)))
GET_NEXT_LINE_OBJECT = $(addprefix $(GET_NEXT_LINE_OBJ), $(addsuffix .o, $(GET_NEXT_LINE_NAMES)))



ARCHIVER = ar rcs
NAME = libft.a

#COLORS

GREEN = \033[;32m
RED = \033[1;31m
DEFAULT = \033[;0m

# COMPILATION

all: $(NAME)

$(NAME): $(LIBFT_OBJECT) $(PRINTF_OBJECT) $(GET_NEXT_LINE_OBJECT)
	@$(ARCHIVER) $(NAME) $(LIBFT_OBJECT) $(PRINTF_OBJECT) $(GET_NEXT_LINE_OBJECT)

$(LIBFT_OBJECT): $(LIBFT_FILES)
	@mkdir -p $(LIBFT_OBJ)
	@gcc -Wall -Wextra -Werror -c $(LIBFT_FILES)
	@mv $(addsuffix .o, $(LIBFT_NAMES)) $(LIBFT_OBJ)
	@echo "$(GREEN)✅ - LIBFT compiled$(DEFAULT)"

$(PRINTF_OBJECT): $(PRINTF_FILES)
	@mkdir -p $(PRINTF_OBJ)
	@gcc -Wall -Wextra -Werror -c $(PRINTF_FILES)
	@mv $(addsuffix .o, $(PRINTF_NAMES)) $(PRINTF_OBJ)
	@echo "$(GREEN)✅ - PRINTF compiled$(DEFAULT)"

$(GET_NEXT_LINE_OBJECT): $(GET_NEXT_LINE_FILES)
	@mkdir -p $(GET_NEXT_LINE_OBJ)
	@gcc -Wall -Wextra -Werror -c $(GET_NEXT_LINE_FILES)
	@mv $(addsuffix .o, $(GET_NEXT_LINE_NAMES)) $(GET_NEXT_LINE_OBJ)
	@echo "$(GREEN)✅ - GET_NEXT_LINE compiled$(DEFAULT)"

clean:
	@rm -rf obj/
	@echo "$(GREEN)✅ - OBJ files deleted successfully$(DEFAULT)"

fclean:
	@rm -rf $(NAME) obj/
	@echo "$(GREEN)✅ - OBJ and COMPILED files deleted successfully$(DEFAULT)"

re: fclean all

.PHONY : all clean fclean re
