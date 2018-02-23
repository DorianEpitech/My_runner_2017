/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** game.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "runner.h"

void move_item(item_t **item)
{
	if ((*item)->type != OBSTACLE && (*item)->type != BONUS) {
		(*item)->vector.x = (*item)->vector.x - (*item)->type;
		if ((*item)->vector.x < -(*item)->rect.width)
			(*item)->vector.x = 0;
	} else {
		(*item)->vector.x = (*item)->vector.x - 10;
	}
}

void game(context_t *context, char **map)
{
	if (sfMusic_getStatus(context->music->game) == sfStopped)
		sfMusic_play(context->music->game);
	colision(context);
	for (int i = 0; i < 4; i++) {
		if (i == 2) {
			manage_matoi(context);
			manage_obstacle(context, map);
		} else {
			sfSprite_setPosition(context->items[i]->sprite,
			context->items[i]->vector);
			sfRenderWindow_drawSprite(context->window,
			context->items[i]->sprite, NULL);
			context->items[i]->ptr_move(&(context->items[i]));
		}
	}
	text_score(context, 90);
	sfText_setPosition(context->score, (sfVector2f){50, 925});
	sfRenderWindow_drawText(context->window, context->score, NULL);
	sfRenderWindow_drawSprite(context->window,
	context->menu->quit, NULL);
}
