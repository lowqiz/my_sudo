##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile lib_ls
##

NAME	= 		libmy.a 

SRC 	=		my_putchar.c	\
				my_isneg.c	\
				my_put_nbr.c	\
				my_swap.c		\
				my_putstr.c	\
				my_strlen.c	\
				my_getnbr.c	\
				my_putnbr_base.c	\
				my_str_to_word_array.c	\
				my_revstr.c	\
				my_str_isalpha.c	\
				my_str_islower.c	\
				my_str_isupper.c	\
				my_str_isnum.c	\
				my_str_isprintable.c	\
				my_strcapitalize.c	\
				my_strcat.c	\
				my_strcmp.c	\
				my_strcpy.c	\
				my_strdup.c	\
				my_strncat.c	\
				my_strncmp.c	\
				my_strncpy.c	\
				my_strstr.c	\
				my_swap.c	\
				my_miniprintf.c 	\
				free_array.c 	\
				my_show_word_array.c

OBJ 	= 		$(SRC:.c=.o)

CFLAGS    =    -Wextra -Wall -pedantic -Wshadow -I./ -Wundef -Wpointer-arith -Wfloat-equal -Winit-self -Waggregate-return -Wwrite-strings -Wcast-align -Wmissing-field-initializers -g

all: 	$(NAME)

$(NAME): 		$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: 	fclean all