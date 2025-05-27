NAME = push_swap

SRC = src/algo/ft_radix.c \
	src/algo/sort_small.c \
	src/algo/ft_sort_utils.c \
	src/instructions/push.c \
	src/instructions/reverse_rotate.c \
	src/instructions/rotate.c \
	src/instructions/swap.c \
	src/ps_func/find_errors.c \
	src/ps_func/find_errors_utils.c \
	src/ps_func/ft_fill.c \
	src/ps_func/ft_fill_utils.c \
	src/ps_func/ft_fill_utils2.c \
	src/ps_func/ft_split.c \
	src/ps_func/ft_split_utils.c \
	src/ps_func/push_swap.c \
	src/ps_func/ft_ps_utils.c \
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

dev: fclean
	git add *; git commit -m "dev"; git push --force;

.PHONY: all clean fclean re dev