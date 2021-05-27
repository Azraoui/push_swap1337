
NAME = checker

NAME2 = push_swap

CHECKER = checker.c
PUSH_SWAP = push_swap.c

FLAG =	-Wall -Wextra -Werror

SRC =	./src/libftt/libft.a \
		./src/gnl/gnl.c \
		actions_2.c actions.c checker_helper.c \
		fill_stack.c stack.c sorting.c quick_sorte.c new_algo.c\

all:	$(NAME)

$(NAME):
		make re -C ./src/libftt/
		gcc $(FLAG) $(SRC) $(CHECKER) -o $(NAME) -g
		gcc $(FLAG) $(SRC) $(PUSH_SWAP) -o $(NAME2) -g
		# gcc $(FLAG) $(SRC) new_algo.c -o test

clean:
		make clean -C ./src/libftt/

fclean: clean
		make fclean -C ./src/libftt/
		rm -f $(NAME) $(NAME2)

re: fclean all

.PHONY: all clean fclean re

