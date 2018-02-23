/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "runner.h"

void my_putstr(char *str)
{
	for (size_t i = 0; str[i] != '\0'; i++)
		write(1, &str[i], 1);
}

void rules()
{
	my_putstr("A Runner is a game where you have to cross a map by avoidi");
	my_putstr("ng the obstacle.\nIn this runner you have to recup the pie");
	my_putstr("ce of a blade whithout being bloc by the obstacle.\n\n USA");
	my_putstr("GE:\n./my_runner map.txt\n\nOPTIONS:\n-i\tlauch the game i");
	my_putstr("n infinite mode.\n-h\tprint the usage and quit.\n\nCOMMAND");
	my_putstr("S:\nSpace\t:JUMP\n\t(You can jump when you are falling)\n");
	my_putstr("\nIf you want to create your own map go ");
	my_putstr("check the file '.legend', you will find a tutoriel\n");
}

void analyse_event(sfEvent event, context_t *context)
{
	while (sfRenderWindow_pollEvent(context->window, &event)) {
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(context->window);
		if (context->status == 0) {
			event_menu(event, context);
		} else if (context->status == 1) {
			event_game(event, context);
		} else {
			event_end(event, context);
		}
	}
}

int game_loop(context_t *context, char **map)
{
	sfEvent event;

	while (sfRenderWindow_isOpen(context->window)) {
		analyse_event(event, context);
		sfRenderWindow_clear(context->window, sfBlack);
		if (context->status == MENU) {
			menu(context);
		} else if (context->status == GAME) {
			game(context, map);
		} else {
			end(context);
		}
		sfRenderWindow_display(context->window);
	}
	return (0);
}

int main(int ac, char **av)
{
	context_t *context = init_context();
	char **map;

	INIT;
	sfRenderWindow_setFramerateLimit(context->window, 90);
	if (ac >= 2) {
		if (ac == 2) {
			game_loop(context, map);
		} else if (ac == 3 && my_strlen(av[2]) == 2 && av[2][0] == '-'
		&& av[2][1] == 'i') {
			context->game_mode = 1;
			game_loop(context, map);
		}
	}
	destroy_context(context, map);
	return (84);
}
