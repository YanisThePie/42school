# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaustry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/22 22:12:34 by jaustry           #+#    #+#              #
#    Updated: 2016/01/02 20:11:59 by yismail          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = execut
CC = gcc
SRCS = create_chain.c
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)
	
$(NAME): $(OBJS)
	$(CC) -o $(NAME) $^ ../libft/libft.a

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all