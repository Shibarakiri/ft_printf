CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_var.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: all clean fclean re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all