##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile to compile the project
##

CC	=	gcc -Wuninitialized

RM	=	rm -f

SRC	=	src/main.c	\
		$(wildcard src/all/*.c) \
		$(wildcard src/game/*.c) \
		$(wildcard src/map/*.c) \
		$(wildcard src/menu_main/*.c) \
		$(wildcard src/menu_option/*.c) \
		$(wildcard src/player/*.c) \
		$(wildcard src/help/*.c) \
		$(wildcard src/inventory/*.c) \
		$(wildcard src/joystick/*.c) \
		$(wildcard src/pause/*.c) \
		$(wildcard src/pnj/*.c) \
		$(wildcard src/mobs/*.c) \
		$(wildcard src/cinématique/*.c) \
		$(wildcard src/loading/*.c)		\
		$(wildcard src/particle/*.c)	\
		$(wildcard src/win/*.c)	\
		$(wildcard src/lose/*.c)	\
		$(wildcard src/save/*.c)	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-W -Wall -Wextra

LINKFLAGS	=	-L./lib -lmy -I./include -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./lib
	$(CC) $(OBJ) ${LINKFLAGS} -o $(NAME)
	@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> compile -> OK\033[0m"

clean:
	$(RM) *~
	$(RM) \#*#
	$(RM) $(OBJ)
	@make clean -C ./lib
	@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> clean -> OK\033[0m"

fclean: clean
	@make fclean -C ./lib
	$(RM) $(NAME)
	@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> fclean -> OK\033[0m"

re:	fclean all
