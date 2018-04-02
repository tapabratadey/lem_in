# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tadey <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/13 15:16:41 by tadey             #+#    #+#              #
#    Updated: 2018/03/13 15:39:27 by tadey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -Wall -Wextra -Werror
LIBFT = -L libft/ -lft
CC = gcc
SRC = *.c

all: $(NAME)

$(NAME):
	$(CC) -g $(FLAGS) $(LIBFT) $(SRC) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all