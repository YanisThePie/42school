# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaustry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/22 22:12:34 by jaustry           #+#    #+#              #
#    Updated: 2016/01/11 07:09:36 by yismail          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = execut
CC = gcc
SRCS = algo_yanis.c\
	create_tab.c\
	main.c 
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
