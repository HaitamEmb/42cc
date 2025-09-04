#Project
NAME = libftprintf.a

#Filepaths
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft
FT_PRINTF = ./ft_printf

#SRC
SRCS = ft_printf.c ft_phex.c ft_putptr.c\
								ft_punsigned.c ft_printf_utils.c

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJS = ${SRCS:.c=.o}
AR = ar rcs
RM = rm -rf
CP = cp

all: ${NAME}

$(NAME): $(LIBFT) $(OBJS)
		$(CP) $(LIBFT) $(NAME)
		@$(AR) $(NAME) $(OBJS)

$(LIBFT): $(LIBFT_PATH)
		@$(MAKE) -C $(LIBFT_PATH)

%.o: 		$(FT_PRINTF)/%.c
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(MAKE) clean -C $(LIBFT_PATH)
			@$(RM) $(OBJS)

fclean:		clean
				@$(MAKE) fclean -C $(LIBFT_PATH)
				@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re