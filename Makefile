##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile ls
##

SRC 	=		src/my_sudo_start.c		\

OBJ 	= 		$(SRC:.c=.o)

NAME	= 		my_sudo

CFLAGS    =    -Wextra -Wall -pedantic -Wshadow -I./ -Wundef -Wpointer-arith -Wfloat-equal -Winit-self -Waggregate-return -Wwrite-strings -Wcast-align -Wmissing-field-initializers

all:
	make -C lib/my/ all
	epiclang -o my_sudo src/handle_flag.c src/verif_password.c src/search_in_group.c src/my_sudo_start.c -lmy -lcrypt -L./lib/my/ -g
	chown root:root my_sudo
	chmod +s my_sudo

$(NAME): 		$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f my_sudo

fclean: clean
		make -C lib/my/ fclean

re: 	fclean all
