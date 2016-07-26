NAME = Wolf3d
CC = gcc
SRCS = 	main.c \
		parse.c \
		raycast.c

CFLAGS = -Wall -Wextra -Werror -Ofast -march=native
FLAGS = -framework OpenGL -framework AppKit -L ./libft -lft -L minilibx_macos -lmlx
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	make -C minilibx_macos
	$(CC) $(FLAGS) -o  $(NAME) $^ ./libft/libft.a
	gcc $(FLAGS) -o $(NAME) $(OBJS)  -L./libft -lft -framework OpenGL -framework AppKit -L ./libft -lft -L minilibx_macos -lmlx

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
