/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** init.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "runner.h"

item_t *create_item(const char *path_to_spritesheet, sfVector2f pos,
	sfIntRect rect, type_e type)
{
	item_t *item = malloc(sizeof(item_t));

	if (item == NULL)
		return (NULL);
	item->type = type;
	item->sprite = sfSprite_create();
	item->texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
	item->vector = pos;
	item->ptr_move = &move_item;
	item->rect = rect;
	sfSprite_setTexture(item->sprite, item->texture, sfTrue);
	return (item);
}

item_t **init_items(void)
{
	item_t **items = malloc(sizeof(item_t) * 4);

	items[0] = create_item("obj/background.png", (sfVector2f){0, 0},
	(sfIntRect){0, 0, 1920, 1080}, BACKGROUND);
	items[1] = create_item("obj/midground.png", (sfVector2f){0, 0},
	(sfIntRect){0, 0, 1920, 1080}, MIDGROUND);
	items[2] = NULL;
	items[3] = create_item("obj/foreground.png", (sfVector2f){0, 0},
	(sfIntRect){0, 0, 1920, 1080}, FOREGROUND);
	return (items);
}
