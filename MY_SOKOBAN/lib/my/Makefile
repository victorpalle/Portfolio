##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

SRC	=	my_putstr.c	\
		my_putchar.c    \
		my_strlen.c \
		my_getnbr.c \
		my_strcat.c \
		my_strcpy.c \
		my_revstr.c \
		my_strcmp.c \
		my_strncat.c \
		my_putnbr.c \
		my_strdup.c \
		my_strncmp.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+= -Wall -Wextra -I./include -L./lib/my

NAME	=	libmy.a

libmy:	$(OBJ)
	ar rc libmy.a *.o
	cp libmy.a ../libmy.a

includemy:
		cp my.h ../../include/my.h

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
