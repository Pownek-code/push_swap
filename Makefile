NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
src = push_swap.c stack_init.c errors.c stack_utils.c swap.c push.c rotate.c rev_rotate.c sort_tiny.c sort_stacks.c init_nodes.c split.c stack_find.c algo_moves.c libft_utils.c
OBJ		= $(src:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
