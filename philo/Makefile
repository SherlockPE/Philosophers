# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 18:08:53 by flopez-r          #+#    #+#              #
#    Updated: 2024/02/28 19:06:15 by flopez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
SRC =	src/main.c \
		src/set_philos.c \
		src/deploy_philos.c \
		src/philo_actions.c \
		src/utils_libft.c \
		src/utils.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -g3 -fsanitize=thread

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
