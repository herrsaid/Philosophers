# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salamane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 14:24:08 by salamane          #+#    #+#              #
#    Updated: 2022/03/31 14:24:14 by salamane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAG=-Wall -Wextra -Werror
NAME=philo
SRCS=main.c
OBJS=${SRCS:.c=.o}

$(NAME):
	$(CC) $(SRCS) -o $(NAME)

all:$(NAME)

fclean:
	rm -rf $(NAME)
re:fclean all