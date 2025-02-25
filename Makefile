NAME = push_swap

SRC = src/algo/ft_radix.c \
	src/algo/sort_small.c \
	src/instructions/push.c \
	src/instructions/reverse_rotate.c \
	src/instructions/rotate.c \
	src/instructions/swap.c \
	src/ps_func/find_errors.c \
	src/ps_func/ft_fill.c \
	src/ps_func/ft_fill_utils.c \
	src/ps_func/ft_split.c \
	src/ps_func/push_swap.c \
	src/main.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -g

clean:
	@true

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re