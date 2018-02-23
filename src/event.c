/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** event.c
*/

#include <SFML/Graphics.h>
#include "runner.h"

void event_end_win(sfEvent event, context_t *context)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(context->window);

	if (event.mouseButton.type == sfEvtMouseButtonPressed
	&& event.mouseButton.button == sfMouseLeft) {
		if (mouse.y > 20 && mouse.y < 120
		&& mouse.x > 20 && mouse.x < 120) {
			sfRenderWindow_close(context->window);
		} else if (mouse.y > 760 && mouse.y < 920
		&& mouse.x > 310 && mouse.x < 778) {
			replay(context);
		}
	}
}

void event_end_loose(sfEvent event, context_t *context)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(context->window);

	if (event.mouseButton.type == sfEvtMouseButtonPressed
	&& event.mouseButton.button == sfMouseLeft) {
		if (mouse.y > 20 && mouse.y < 120
		&& mouse.x > 20 && mouse.x < 120) {
			sfRenderWindow_close(context->window);
		} else if (mouse.y > 734 && mouse.y < 917
		&& mouse.x > 183 && mouse.x < 728) {
			replay(context);
		}
	}
}

void event_end(sfEvent event, context_t *context)
{
	if (context->status == ENDWIN) {
		event_end_win(event, context);
	} else if (context->status == ENDLOOSE) {
		event_end_loose(event, context);
	}
}

void event_game(sfEvent event, context_t *context)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(context->window);

	if (event.mouseButton.type == sfEvtMouseButtonPressed
	&& event.mouseButton.button == sfMouseLeft)
		if (mouse.y > 20 && mouse.y < 120
		&& mouse.x > 20 && mouse.x < 120)
			sfRenderWindow_close(context->window);
	if (event.key.type == sfEvtKeyPressed
	&& event.key.code == sfKeySpace) {
		if (context->matoi->status != 1) {
			((sfMusic_getStatus(context->music->jump) == sfStopped)
			? sfMusic_play(context->music->jump) : 0);
			context->matoi->pos.y -= 1;
			context->matoi->status = 1;
			context->matoi->colision.x = 0;
			sfClock_restart(context->matoi->clock);
			context->matoi->rect = (sfIntRect){0, 100, 100, 100};
		}
	}
}

void event_menu(sfEvent event, context_t *context)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(context->window);

	if (event.mouseButton.type == sfEvtMouseButtonPressed
	&& event.mouseButton.button == sfMouseLeft) {
		if (mouse.y > 324 && mouse.y < 476
		&& mouse.x > 626 && mouse.x < 1193) {
			context->status = GAME;
			cinematic(context);
			sfMusic_stop(context->music->menu);
		} else if (mouse.y > 596 && mouse.y < 746
		&& mouse.x > 626 && mouse.x < 1193) {
			sfRenderWindow_close(context->window);
		}
	}
}
