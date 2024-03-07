# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 15:00:46 by flopez-r       #+#    #+#              #
#    Updated: 2024/03/07 15:00:47 by fabriciolop      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SOURCE =	src/main.c \
			src/init_program.c \
			src/philo_actions.c \
			src/monitor.c \
			src/reaper.c \
			src/threads.c \

UTILS = utils/checkers.c \
		utils/error_utils.c \
		utils/init_mutex.c \
		utils/libft_utils.c \
		utils/print_utils.c \
 		utils/time_utils.c 

SRC = $(SOURCE) $(UTILS)

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -O3 -fsanitize=address -g3

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
