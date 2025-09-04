CLIENT_NAME = client
SERVER_NAME = server

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

S_SRC = server.c
C_SRC = client.c
S_OBJ = $(S_SRC:.c=.o)
C_OBJ = $(C_SRC:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ 

all: client server

server: $(S_OBJ) | libft
	@ $(CC) $(FLAGS) -o $(SERVER_NAME) $(S_OBJ) libft/*.o

client: $(C_OBJ) | libft 
	@ $(CC) $(FLAGS) -o $(CLIENT_NAME) $(C_OBJ) libft/*.o

libft: 
	@ make -C libft/
clean:
	@ $(RM) $(S_OBJ) $(C_OBJ)
	@ make -C libft/ clean

fclean: clean
	@ $(RM) $(SERVER_NAME) $(CLIENT_NAME)
	@ make -C libft/ fclean

re: fclean all

.PHONY: all libft clean fclean re