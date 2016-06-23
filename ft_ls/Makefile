# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaustry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/22 22:12:34 by jaustry           #+#    #+#              #
#    Updated: 2016/06/23 18:18:09 by yismail          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	ft_ls
CC = gcc
SRCS =	open.c \
		usestat.c \
		options.c

CFLAGS = -Wall -Wextra -Werror -ggdb
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -o  $(NAME) $^ ./libft/libft.a
	gcc $(FLAGS) -o $(NAME) $(OBJS)  -L./libft -lft

clean:
	rm $(OBJS)
	make -C libft/ clean

fclean: clean
	rm $(NAME)
	make -C libft/ fclean

re: fclean all
