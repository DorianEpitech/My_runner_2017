/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** end.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "runner.h"

void replay(context_t *context)
{
	destroy_all_obstacle(context->items[2], 0);
	context->items[2] = NULL;
	context->matoi->pos = (sfVector2f){250, 788};
	context->matoi->rect = (sfIntRect){0, 0, 100, 100};
	context->matoi->second = 0;
	context->matoi->status = 0;
	context->matoi->shift = 13;
	context->matoi->score = 0;
	context->shift_map = 0;
	context->timer = 0;
	context->status = GAME;
	if (sfMusic_getStatus(context->music->lose) != sfStopped)
		sfMusic_stop(context->music->lose);
	if (sfMusic_getStatus(context->music->win) != sfStopped)
		sfMusic_stop(context->music->win);
}

void end(context_t *context)
{
	((sfMusic_getStatus(context->music->game) != sfStopped)
	? sfMusic_stop(context->music->game) : 0);
	((sfMusic_getStatus(context->music->run) != sfStopped)
	? sfMusic_stop(context->music->run) : 0);
	text_score(context, 90);
	if (context->status == ENDWIN) {
		((sfMusic_getStatus(context->music->win) == sfStopped)
		? sfMusic_play(context->music->win) : 0);
		sfRenderWindow_drawSprite(context->window,
		context->end->s_win, NULL);
		sfText_setPosition(context->score, (sfVector2f){140, 555});
	} else {
		((sfMusic_getStatus(context->music->lose) == sfStopped)
		? sfMusic_play(context->music->lose) : 0);
		sfRenderWindow_drawSprite(context->window,
		context->end->s_loose, NULL);
		sfText_setPosition(context->score, (sfVector2f){105, 485});
	}
	sfRenderWindow_drawText(context->window, context->score, NULL);
	sfRenderWindow_drawSprite(context->window, context->menu->quit, NULL);
}
