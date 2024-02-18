NAME = philo
# SRC =	main.c 
SRC =	return_threads.c 

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread


all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: all fclean

run: all
	@./$(NAME)



.PHONY: all clean fclean re run
