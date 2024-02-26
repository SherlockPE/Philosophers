# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 18:08:53 by flopez-r          #+#    #+#              #
#    Updated: 2024/02/26 12:40:50 by flopez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
SRC =	src/main.c \
		src/initiliase_death.c \
		src/libft_utils.c \
		src/deploy_death.c \
		src/utils.c \
		src/logs.c \
		src/philo_actions.c
# src/deploy.c \
# src/utils.c \
# src/logs.c \
# src/deploy_utils.c \
# src/start_thread.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -g3 -fsanitize=address

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
