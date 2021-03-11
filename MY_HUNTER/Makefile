##
## EPITECH PROJECT, 2020
## $MAKEFILE
## File description:
## makefile
##

SRC	=	src/my_hunter.c \
		src/mouse.c \
		src/main.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS  =	-I./include

LDFLAGS	=	-L./lib/ -lmy

GFLAGS  =	-lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -sC lib/my/
	@gcc -o $(NAME) $(SRC) $(CFLAGS) $(LDFLAGS) $(GFLAGS)

clean:
	@rm -f $(OBJ)
	@find . -name "*~" -type f -delete
	@find . -name "*.gcno" -type f -delete
	@find . -name "*.gcda" -type f -delete

fclean: clean
	@rm -f $(NAME)
	clear

re: fclean all

.PHONY:	clean fclean re all unit_tests
