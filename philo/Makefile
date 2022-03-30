# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburri <rburri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 10:48:44 by rburri            #+#    #+#              #
#    Updated: 2022/03/28 09:40:41 by rburri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC = gcc 

NAME = philo

FLAGS = -Wall -Wextra -Werror -g3

LIB = -lpthread


SOURCE =  	main.c\
			utils.c\
			init.c\
			activities.c\
			supervise.c\
			
		
		
OBJS = $(SOURCE:.c=.o)

%.o : %.c
				$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)


${NAME}:	${OBJS}
			$(CC)  ${OBJS} $(LIB) -o $(NAME)
			@echo "$(GREEN)$(NAME) sucessfully created$(RESET)"

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)
	
re: fclean all

.PHONY: fclean re all clean bonus
