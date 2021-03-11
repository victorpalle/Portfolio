##
## EPITECH PROJECT, 2020
## $MAKEFILE
## File description:
## makefile
##

SRC	=	main.c \
		event.c \
		run_window.c \
		init_struct.c \
		print.c \
		move.c \
		time.c \
		win.c \
		score.c \
		menu_colors.c \
		map.c \
		enemy.c \
		destroy.c \
		hit.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

CFLAGS  =	-I./include

LDFLAGS	=	-L./lib/ -lmy

GFLAGS  =	-lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -sC lib/my/
	@gcc -o $(NAME) -g3 $(SRC) $(CFLAGS) $(LDFLAGS) $(GFLAGS)

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
