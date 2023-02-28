CFILES = ft_printf.c ft_hexadecimal.c ft_numbers.c ft_strings.c ft_itoa.c ft_utoa.c ft_strlen.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

ARCHIVER = ar rcs
NAME = libftprintf.a
OFILES = $(CFILES:.c=.o)
HEADER_FILE = ft_printf.h

RM = rm -f

all: $(NAME)

$(NAME): $(OFILES) $(HEADER_FILE)
	$(ARCHIVER) $(NAME) $(OFILES)

$(OFILES): $(CFILES)
	$(CC) $(CFLAGS) -c $(CFILES)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME) $(OFILES)

re: fclean all

.PHONY: clean fclean re