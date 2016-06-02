CC = gcc
CFLAG = -Wall -Wextra -Werror
SRC = check_trio.c gt_sample.c add_tet_list.c add_tet_tab.c \
check_place.c  init_list.c put_dbtab.c putlist.c tet_new.c db_tabnew.c \
del_tet_tab.c db_tabfree.c lst_free.c fillit.c main.c
SRC_DIR = ./src
SRC_C = $(patsubst %, $(SRC_DIR)/%, $(SRC))
OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_DIR = ./obj
OBJ_O = $(patsubst %, $(OBJ_DIR)/%, $(OBJ))
HDIR = include
LDIR = libft
LIB = ft
FILE = fichier_test1.txt
NAME = fillit
.PHONY: re run rr clean fclean all $(NAME)

all: libft.a $(NAME)

libft.a:
	@make re -C ./libft

$(NAME): $(OBJ_O)
	@$(CC) -o $@ -I $(HDIR) -l $(LIB) -L $(LDIR) $(OBJ_O) $(CFLAG)
	@echo "\033[32mfillit done\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@ -I $(HDIR) $(CFLAG)

clean:
	@rm -rf $(OBJ_O)
	@echo "\033[31mobject files removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mfillit removed\033[0m"

re: fclean all

run:
	@./$(NAME) $(FILE) | cat -e

rr: re run
