##
## EPITECH PROJECT, 2020
## $MAKEFILE
## File description:
## makefile
##

SRC	=	my_printf.c	\
		my_putnbr.c	\
		my_putstr.c	\
		my_library.c	\
		my_special.c	\
		my_parser.c	\
		my_handler.c	\
		my_strmod.c 	\
		my_specifiers_library.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp my_lib.h ../../include
	@mv $(NAME) ../

clean:
	@rm -f ../$(NAME)

fclean:	clean
	@rm -f $(OBJ)
	@clear

re: fclean all

.PHONY:	all re fclean clean