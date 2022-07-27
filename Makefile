##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for my_defender.c
##

SRC =			src/*.c \
				src/create_all/*.c \
				src/destroy_all/*.c \
				src/draw_game/*.c \
				src/gameplay/*.c \
				src/manage_buttons/*.c \
				src/manage_enemies/*.c \
				src/manage_perso/*.c \
				src/quests/*.c \
				lib/*.c \

OBJ =			$(SRC:.c=.o)

NAME =			my_rpg

LCSFML =		-lcsfml-window -lcsfml-audio -lcsfml-system -lcsfml-graphics

all:
	gcc -o $(NAME) $(SRC) $(LCSFML) -lm

clean :
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
