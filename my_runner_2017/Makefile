##
## EPITECH PROJECT, 2018
## Project my_runner
## File description:
## Build my_runner binary.
##

MAIN_SRC	=	src/main.c

SRC	=	src/moves.c \
		src/print.c \
		src/arguments.c \
		src/choose_moves.c \
		src/collisions.c \
		src/create.c \
		src/draw.c \
		src/events.c \
		src/map.c \
		src/moves2.c \
		src/structset.c \

UT_SRC	=	tests/main_test.c

OBJ	=	$(MAIN_SRC:.c=.o) $(SRC:.c=.o)

UT_OBJ	=	$(SRC:.c=.o) $(UT_SRC:.c=.o)

CFLAGS	=	-Wextra -W -Wall -I ./include/ -lc_graph_prog

MFLAGS	=	-Wextra -W -Wall -I ./include/ -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

LDFLAGS	=

NAME	=	my_runner

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(UT_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f units
	rm -f *.html
	find . -name "*.gcda" -type f -delete
	find . -name "*.gcno" -type f -delete

re: fclean all

test_run:	CFLAGS += --coverage

test_run:	$(UT_OBJ)
		$(CC) -o units $(UT_OBJ) $(LDFLAGS) -lcriterion --coverage
		./units

cov:	test_run
	gcovr -r . --html -o coverage.html --html-details -e ".*tests/.*"
