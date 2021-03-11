##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile task02
##

SRC	=	src/main.c \
		src/sokoban.c \
		src/map_handling.c \
		src/str_to_tab.c \
		src/analyze.c \
		src/move.c \
		src/win_loose.c \
		src/o_handling.c \
		src/error.c \
		src/win_bis.c \

SRC_CR	=	tests/sokoban.c \

OBJ	=	$(SRC:.c=.o)

NAME	=    my_sokoban

CLEAN_LIB	=	cd lib/my && make clean && cd ../../

CFLAGS	+= -I./include -L./lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my/
		gcc -g3 -o $(NAME) -Wall -Wextra -lncurses $(OBJ) $(CFLAGS)
		$(CLEAN_LIB)

tests_run:      $(OBJ_CR) $(OBJ)
	gcc -o unit_tests $(SRC) $(SRC_CR) $(CFLAGS) -lcriterion --coverage
	./unit_tests
	gcovr
	gcovr --branches


clean:
	rm -f $(OBJ)
	find . -name "*~" -type f -delete

fclean: clean
	rm -f $(NAME)
	rm -f $(OBJ_CR)
	rm -f unit_tests
	make fclean -sC lib/my
	clear


re:	clean all
