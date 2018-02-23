/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** colision.c
*/

#include <stdio.h>
#include "runner.h"

int colision_up(context_t *context, sfVector2f pos)
{
	int check = 0;
	item_t *tmp = context->items[2];
	sfVector2f save = {pos.x + 100, pos.y + 100};

	while (tmp != NULL) {
		NOT_BLOC;
		while (pos.x <= save.x && check != 1) {
			BLOC_UP;
			pos.x += 25;
		}
		check = 0;
		pos.x = save.x - 100;
		tmp = tmp->next;
	}
	return (0);
}

int colision_down(context_t *context, sfVector2f pos)
{
	int check = 0;
	item_t *tmp = context->items[2];
	sfVector2f save = {pos.x + 100, pos.y + 100};

	while (tmp != NULL) {
		NOT_BLOC;
		while (pos.x <= save.x && check != 1) {
			BLOC_DOWN;
			pos.x += 25;
		}
		check = 0;
		pos.x = save.x - 100;
		tmp = tmp->next;
	}
	return (0);
}

int colision_right(context_t *context, sfVector2f pos)
{
	int check = 0;
	item_t *tmp = context->items[2];
	sfVector2f save = {pos.x + 100, pos.y + 100};

	while (tmp != NULL) {
		NOT_BLOC;
		while (pos.y <= save.y && check != 1) {
			BLOC_RIGHT;
			pos.y += 25;
		}
		check = 0;
		pos.y = save.y - 100;
		tmp = tmp->next;
	}
	return (0);
}

void down_interaction(context_t *context)
{
	int check = 1;

	if (context->matoi->pos.y + 100 >= 888) {
		if (context->matoi->status == 2) {
			context->matoi->rect = (sfIntRect){0, 0, 100, 100};
			context->matoi->status = 1;
		}
		context->matoi->pos.y = 788;
		context->matoi->colision.x = 1;
	} else {
		check = colision_down(context, context->matoi->pos);
		if (context->matoi->status == 2 && check == 1) {
			context->matoi->rect = (sfIntRect){0, 0, 100, 100};
			context->matoi->status = 1;
		}
	}
	FALLING;
}
void colision(context_t *context)
{
	int check = 0;

	down_interaction(context);
	colision_up(context, context->matoi->pos);
	check = colision_right(context, context->matoi->pos);
	colision_bonus(context, context->matoi->pos);
	if (check == 0)
		context->matoi->colision.y = 0;
	if (context->matoi->pos.x <= -100) {
		context->status = ENDLOOSE;
		if (sfMusic_getStatus(context->music->game) != sfStopped)
			sfMusic_stop(context->music->game);
	}
}
