# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 14:58:11 by efarhat           #+#    #+#              #
#    Updated: 2023/06/22 17:21:34 by efarhat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

FALGS = -Wall -Wextra -Werror

SRC = philo.c ft_atoi.c check_args.c init_utils.c utils.c threads.c philos_routine.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) philo.h
	$(CC) $(FALGS) $(OBJ) -o $@

%.o : %.c
	$(CC) -c $(FALGS) $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.phony : all clean fclean re
