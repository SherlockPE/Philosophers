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

SRC_DIR := src
UTILS_DIR := utils
OBJ_DIR := obj
RM = rm -rf
CREAT_DIR = mkdir -p

SOURCE =	main.c \
			init_program.c \
			philo_actions.c \
			monitor.c \
			optional_meals.c \
			reaper.c \
			threads.c \

UTILS = checkers.c \
		error_utils.c \
		init_mutex.c \
		libft_utils.c \
		print_utils.c \
 		time_utils.c 

# SRCS = $(SOURCE)
SOURCE := $(SOURCE:%=$(SRC_DIR)/%)
UTILS := $(UTILS:%=$(UTILS_DIR)/%)
SRCS = $(SOURCE) $(UTILS)

# OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -O3 -fsanitize=address -g3

# all:
# 	@echo "SOURCES\n"$(SRCS)
# 	@echo "OBJECTS\n"$(OBJ)


all: $(OBJ_DIR) $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	$(CREAT_DIR) $(OBJ_DIR)
	$(CREAT_DIR) $(SRC_DIR:%=$(OBJ_DIR)/%)
	$(CREAT_DIR) $(UTILS_DIR:%=$(OBJ_DIR)/%)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
