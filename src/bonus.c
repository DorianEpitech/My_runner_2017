/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** bonus.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "runner.h"

char *manage_score(context_t *context)
{
	char *result = malloc(13);
	int tmp = context->matoi->score;

	result[0] = 'S';
	result[1] = 'c';
	result[2] = 'o';
	result[3] = 'r';
	result[4] = 'e';
	result[5] = ' ';
	result[6] = ':';
	result[7] = ' ';
	for (int i = 3; i >= 0; i--) {
		result[i + 8] = tmp % 10 + 48;
		tmp = tmp / 10;
	}
	result[12] = '\0';
	return (result);
}

void text_score(context_t *context, int size)
{
	char *number = manage_score(context);

	sfText_setString(context->score, number);
	sfText_setColor(context->score, (sfColor){139, 0, 0, 255});
	sfText_setFont(context->score, context->font);
	sfText_setCharacterSize(context->score, size);
	if (context->matoi->colision.x == 1
	&& sfMusic_getStatus(context->music->run) == sfStopped
	&& context->status != ENDWIN && context->status != ENDLOOSE) {
		sfMusic_play(context->music->run);
	} else if (context->matoi->colision.x != 1
	&& context->status != ENDWIN && context->status != ENDLOOSE) {
		sfMusic_stop(context->music->run);
	}
	free(number);
}

void destroy_bonus(int place, context_t *context)
{
	item_t *tmp = context->items[2];

	if (place == 0) {
		destroy_obstacle(tmp, 0);
		context->items[2] = context->items[2]->next;
	} else {
		for (; place > 1; place--)
			tmp = tmp->next;
		if (tmp->next != NULL) {
			destroy_obstacle(tmp->next, 1);
			tmp->next = tmp->next->next;
		} else {
			destroy_obstacle(tmp->next, 0);
			tmp->next = NULL;
		}
	}
}

int colision_bonus(context_t *context, sfVector2f pos)
{
	int check = 0;
	int place = 0;
	item_t *tmp = context->items[2];
	sfVector2f save = {pos.x + 100, pos.y + 100};

	while (tmp != NULL) {
		NOT_BONUS;
		while (pos.y <= save.y && check != 1) {
			COLISION_BONUS;
			pos.y += 25;
		}
		place = place + 1;
		check = 0;
		pos.y = save.y - 100;
		tmp = tmp->next;
	}
	return (0);
}

item_t *add_bonus(context_t *context, int i, char **map)
{
	item_t *tmp = context->items[2];

	if (map[i][context->shift_map] != 'B')
		return (context->items[2]);
	if (tmp == NULL) {
		tmp = create_item("obj/bonus.png",
		(sfVector2f){1920, i * 100 + 88},
		(sfIntRect){0, 0, 10000, 10000}, BONUS);
		tmp->next = NULL;
		return (tmp);
	} else {
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = create_item("obj/bonus.png",
		(sfVector2f){1920, i * 100 + 88},
		(sfIntRect){0, 0, 10000, 10000}, BONUS);
		tmp->next->next = NULL;
	}
	return (context->items[2]);
}
