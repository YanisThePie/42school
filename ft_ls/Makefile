# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaustry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/22 22:12:34 by jaustry           #+#    #+#              #
#    Updated: 2016/06/07 15:55:14 by yismail          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	ft_ls
CC = gcc
SRCS =	open.c \
		usestat.c

CFLAGS = -Wall -Wextra -Werror -ggdb
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o  $(NAME) $^ ./libft/libft.a

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
