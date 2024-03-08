# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabriciolopez <fabriciolopez@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 23:51:26 by fabriciolop       #+#    #+#              #
#    Updated: 2024/03/09 00:09:03 by fabriciolop      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

RED =			\033[0;91m
GREEN =			\033[0;92m
CYAN =			\033[0;96m
BLUE=			\033[0;34m
PURPLE=			\033[0;35m
YELLOW =		\033[0;93m
RESET=			\033[0m

SOURCE =	src/main.c \
			src/init_program.c \
			src/philo_actions.c \
			src/monitor.c \
			src/optional_meals.c \
			src/reaper.c \
			src/threads.c \

UTILS = utils/checkers.c \
		utils/error_utils.c \
		utils/init_mutex.c \
		utils/libft_utils.c \
		utils/print_utils.c \
 		utils/time_utils.c 

SRC = $(SOURCE) $(UTILS)

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -O3 -I includes -fsanitize=address -g3

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\n$(GREEN)Objects compiled successfuly ✅$(RESET)"
	@echo "$(GREEN)Program $(NAME) created ✅$(RESET)"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling ...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@echo "\n$(YELLOW)Creating object directories ...$(RESET)"
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/src
	@mkdir -p $(OBJ_DIR)/utils

clean:
	@echo "\n$(CYAN)Cleaning objects$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(CYAN)Objects cleaned successfuly ✅$(RESET)"

fclean: clean
	@echo "\n$(BLUE)Cleaning $(NAME)$(RESET)"
	@rm -rf $(NAME)
	@echo "$(BLUE)Program cleaned successfuly ✅$(RESET)"

re:	fclean all

.PHONY: all clean fclean re
