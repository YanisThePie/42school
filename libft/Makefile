#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yismail <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 13:28:30 by yismail           #+#    #+#              #
#    Updated: 2015/12/02 16:39:57 by yismail          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCS = ft_itoa.c \
	ft_nbrlen.c \
	ft_putendl_fd.c \
    ft_putchar.c \
    ft_atoi.c \
	ft_memcmp.c \
	ft_bzero.c \
	ft_isdigit.c \
	ft_isalpha.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdup.c \
	ft_strlen.c \
	ft_strlcat.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strncpy.c \
	ft_memdel.c \
	ft_memalloc.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strsplit.c \
	ft_strtrim.c \
	ft_putstr.c \
	ft_putendl.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putnbr_fd.c \
	ft_putnbr.c

all: $(NAME)

$(NAME) :
	gcc -Wall -Wextra -Werror -c $(SRCS)
	ar rc $(NAME) *.o

clean :
	rm -f *.o
	rm -f *~

fclean : clean
	rm -f $(NAME)

re : fclean all
