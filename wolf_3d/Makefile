NAME = Wolf3d
CC = gcc -Wall -Wextra -Werror 
SRCS = 	srcs/main.c \
		srcs/parse.c \
		srcs/raycast.c\
		srcs/event.c\
		srcs/draw.c

FLAGS = -framework OpenGL -framework AppKit -L./libft -lft -L minilibx_macos -lmlx
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	make -C minilibx_macos
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	make clean -C libft/
	make clean -C minilibx_macos/
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean all
