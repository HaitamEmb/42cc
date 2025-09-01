CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iincludes -g
NAME = push_swap

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

SRC =	main.c input_check.c init_stack.c stack.c sorted_stack.c \
					swap.c push.c rotate.c \
					reverse_rotate.c sort.c tiny_sort.c pos.c cost.c \
					moves.c push_swap_utils.c					

OBJS = ${SRC:.c=.o}
RM = rm -rf
all: ${NAME}
${NAME}: ${OBJS}
				@${MAKE} -C ${LIBFT_PATH}
				@${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}
clean:
			@${MAKE} -C ${LIBFT_PATH} fclean
			@${RM} ${OBJS}
fclean: clean
			@${RM} ${NAME}
re:	fclean all
.PHONY: all clean fclean re