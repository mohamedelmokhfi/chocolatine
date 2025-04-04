##
## EPITECH PROJECT, 2025
## my sudo
## File description:
## my sudo
##

.PHONY: all clean fclean re

CC = gcc

SRC =	./src/main.c \
		./src/my_sudo.c \
		./src/my.c \
		./src/help.c \
		./src/verifypsswd.c \

CFLAGS = -Wall -Werror -lcrypt -g

OBJ = $(SRC:.c=.o)

NAME = my_sudo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -I../includes

perms:
	sudo chown root:root $(NAME)
	sudo chmod u+s $(NAME)

clean:
	rm -f $(OBJ)
tests_run:

fclean: clean
	rm -f $(NAME)

re: fclean clean all
