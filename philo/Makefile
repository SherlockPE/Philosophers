# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 18:08:53 by flopez-r          #+#    #+#              #
#    Updated: 2024/02/20 16:24:40 by fabriciolop      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
SRC =	src/main.c \
		src/deploy.c \
		src/utils.c \
		src/logs.c \
		src/deploy_utils.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -g3

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
