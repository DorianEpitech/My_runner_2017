/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** obstacle.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "runner.h"

void destroy_all_obstacle(item_t *item, int i)
{
	int ct = 0;
	item_t *save = item;
	item_t *tmp = item;

	while (item != NULL) {
		item = item->next;
		i = i + 1;
	}
	while (i > 0) {
		while (ct < i - 1) {
			ct = ct + 1;
			tmp = tmp->next;
		}
		sfSprite_destroy(tmp->sprite);
		sfTexture_destroy(tmp->texture);
		free(tmp);
		tmp = save;
		ct = 0;
		i = i - 1;
	}
}

void destroy_obstacle(item_t *item, int check)
{
	if (check == 1) {
		sfSprite_destroy(item->sprite);
		sfTexture_destroy(item->texture);
	} else {
		sfSprite_destroy(item->sprite);
		sfTexture_destroy(item->texture);
		free(item);
	}
}

item_t *add_obstacle(context_t *context, int i, char **map)
{
	item_t *tmp = context->items[2];

	if (map[i][context->shift_map] != 'O')
		return (context->items[2]);
	if (tmp == NULL) {
		tmp = create_item("obj/obstacle.png",
		(sfVector2f){1920, i * 100 + 88},
		(sfIntRect){0, 0, 10000, 10000}, OBSTACLE);
		tmp->next = NULL;
		return (tmp);
	} else {
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = create_item("obj/obstacle.png",
		(sfVector2f){1920, i * 100 + 88},
		(sfIntRect){0, 0, 10000, 10000}, OBSTACLE);
		tmp->next->next = NULL;
	}
	return (context->items[2]);
}

item_t *delete_obstacle(context_t *context)
{
	item_t *tmp = context->items[2];

	if (tmp == NULL) {
		return (NULL);
	} else if (tmp->next == NULL && tmp->vector.x < -100) {
		destroy_obstacle(tmp, 0);
		return (NULL);
	}
	while (tmp->next != NULL) {
		if (tmp->next->vector.x < -100) {
			destroy_obstacle(tmp->next, 1);
			tmp->next = tmp->next->next;
		}
		if (tmp != NULL && tmp->next != NULL)
			tmp = tmp->next;
	}
	return (context->items[2]);
}

void manage_obstacle(context_t *context, char **map)
{
	item_t *tmp;

	context->timer += 10;
	if (context->timer == 100){
		for (int i = 0; i < 8; i = i + 1) {
			context->items[2] = add_obstacle(context, i, map);
			context->items[2] = add_bonus(context, i, map);
		}
		context->items[2] = delete_obstacle(context);
		context->shift_map = context->shift_map + 1;
		CHECK_MAP;
		context->timer = 0;
	}
	tmp = context->items[2];
	while (tmp != NULL) {
		sfSprite_setPosition(tmp->sprite, tmp->vector);
		sfRenderWindow_drawSprite(context->window, tmp->sprite, NULL);
		tmp->ptr_move(&(tmp));
		tmp = tmp->next;
	}
}
