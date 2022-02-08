# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburri <rburri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 10:48:44 by rburri            #+#    #+#              #
#    Updated: 2022/02/08 11:00:34 by rburri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################################################################
# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
####################################################################
CC = gcc 

NAME = philo

FLAGS = -Wall -Wextra -Werror

SRC = src

BIN = bin

$(shell mkdir -p $(BIN))

SOURCE =  $(SRC)/main.c\
		
		
OBJS = $(patsubst %,$(BIN)/%,$(notdir $(SOURCE:.c=.o)))

$(BIN)/%.o : $(SRC)/%.c
				$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)


${NAME}:	${OBJS}
			$(CC)  ${OBJS} $(LIBFT) -o $(NAME)
			@echo "$(GREEN)$(NAME) sucessfully created$(RESET)"

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)
	
re: fclean all

.PHONY: fclean re all clean bonus
