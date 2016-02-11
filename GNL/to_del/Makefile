# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaustry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/22 22:12:34 by jaustry           #+#    #+#              #
#    Updated: 2016/02/11 19:18:29 by yismail          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = execut
CC = gcc
SRCS = main.c ../get_next_line.c
CFLAGS = -Wall -Wextra -Werror -ggdb -g
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o  $(NAME) $^ ../libft/libft.a

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
