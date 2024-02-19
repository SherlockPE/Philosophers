# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 18:08:53 by flopez-r          #+#    #+#              #
#    Updated: 2024/02/19 14:45:28 by flopez-r         ###   ########.fr        #
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
CFLAGS = -Wall -Wextra -Werror -I includes

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
