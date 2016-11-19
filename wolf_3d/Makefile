NAME = Wolf3d
CC = gcc
SRCS = 	srcs/main.c \
		srcs/parse.c \
		srcs/raycast.c\
		srcs/event.c\
		srcs/draw.c

CFLAGS = -Wall -Wextra -Werror
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
	make clean -C libft/
	make clean -C minilibx_macos/
	rm -f $(OBJS)

fclean: clean
		make fclean -C libft/
		rm -f $(NAME)

re: fclean all
