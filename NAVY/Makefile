##
## EPITECH PROJECT, 2020
## $MAKEFILE
## File description:
## makefile
##

SRC	=	src/main.c 			\
		src/parser.c 		\
		src/helper.c 		\
		src/handle_struct.c 	\
		src/handle_signals.c	\
		src/handle_response.c	\
		src/handle_map.c 	\
		src/player_one.c 	\
		src/player_two.c 	\
		src/read_and_send.c \
		src/print_map.c 	\
		src/modif_map.c 	\
		src/modif_map_adv.c \
		src/error_file.c 	\
		src/error_syntax.c 	\

SRC_UT=	src/parser.c 		\
		src/helper.c 		\
		src/handle_struct.c \
		src/handle_map.c 	\
		src/player_one.c 	\
		src/player_two.c 	\
		src/read_and_send.c \
		src/print_map.c 	\
		src/modif_map.c 	\
		src/modif_map_adv.c \
		tests/navy_tests.c		\
		src/handle_signals.c	\
		src/handle_response.c	\
		src/error_file.c 	\
		src/error_syntax.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	navy

UNIT_NAME	=	unit_tests

CFLAGS	=	-I include/

LDFLAGS	=	-L lib/ -lmy

GFLAGS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio

TFLAGS	=	-lcriterion --coverage

all:	$(NAME)

$(NAME): $(OBJ)
	@make -sC lib/my/
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(GFLAGS)
	@rm -f $(OBJ)

clean:
	@make -sC lib/my/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -sC lib/my/ fclean
	@rm -f $(NAME)
	@rm -f $(UNIT_NAME)
	@find . -name "*~" -type f -delete
	@find . -name "*.gcno" -type f -delete
	@find . -name "*.gcda" -type f -delete
	@clear

unit_test:	re
	@gcc -o $(UNIT_NAME) $(SRC_UT) $(CFLAGS) $(LDFLAGS) $(TFLAGS)

tests_run:	unit_test
	@./$(UNIT_NAME)
	@gcovr
	@gcovr --branches

re:	fclean all

.PHONY : all clean fclean unit_test tests_run re