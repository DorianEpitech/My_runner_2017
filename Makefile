##
## EPITECH PROJECT, 2017
## my_runner_2017
## File description:
## Makefile
##

SRC	=	src/destroy.c	\
		src/game.c	\
		src/init.c	\
		src/main.c	\
		src/menu.c	\
		src/event.c	\
		src/cinematic.c	\
		src/init_items.c	\
		src/move_player.c	\
		src/colision.c	\
		src/recup_map.c	\
		src/my_strlen.c	\
		src/obstacle.c	\
		src/end.c	\
		src/bonus.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra -Werror -I./include -g3

LDFLAGS	=	-L. -lc_graph_prog

PERSO	=	-L. -lcsfml-graphics -lcsfml-audio -lcsfml-system

NAME	=	my_runner

all:	compil

compil:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

my:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(PERSO)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
