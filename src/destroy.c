/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** destroy.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "runner.h"

void destroy_items(item_t **items)
{
	int i = 0;

	while (i < 4) {
		if (i == 2) {
			destroy_all_obstacle(items[i], 0);
		} else {
			sfSprite_destroy(items[i]->sprite);
			sfTexture_destroy(items[i]->texture);
			free(items[i]);
		}
		i = i + 1;
	}
	free(items);
}

void destroy_music(music_t *music)
{
	sfMusic_destroy(music->game);
	sfMusic_destroy(music->menu);
	sfMusic_destroy(music->lose);
	sfMusic_destroy(music->win);
	sfMusic_destroy(music->jump);
	sfMusic_destroy(music->run);
	sfMusic_destroy(music->cinematic);
	free(music);
}

void destroy_matoi(matoi_t *matoi)
{
	sfSprite_destroy(matoi->sprite);
	sfTexture_destroy(matoi->texture);
	sfClock_destroy(matoi->clock);
	free(matoi);
}

void destroy_cinematic(cinematic_t *cinematic)
{
	sfSprite_destroy(cinematic->sprite1);
	sfTexture_destroy(cinematic->texture1);
	sfSprite_destroy(cinematic->sprite2);
	sfTexture_destroy(cinematic->texture2);
	sfSprite_destroy(cinematic->sprite3);
	sfTexture_destroy(cinematic->texture3);
	sfSprite_destroy(cinematic->sprite4);
	sfTexture_destroy(cinematic->texture4);
	sfSprite_destroy(cinematic->sprite5);
	sfTexture_destroy(cinematic->texture5);
	sfSprite_destroy(cinematic->sprite6);
	sfTexture_destroy(cinematic->texture6);
	free(cinematic);
}

void destroy_context(context_t *context, char **map)
{
	sfRenderWindow_destroy(context->window);
	destroy_items(context->items);
	destroy_music(context->music);
	destroy_matoi(context->matoi);
	destroy_cinematic(context->cinematic);
	sfSprite_destroy(context->menu->sprite);
	sfTexture_destroy(context->menu->texture);
	sfSprite_destroy(context->menu->quit);
	sfTexture_destroy(context->menu->texture_quit);
	sfSprite_destroy(context->end->s_win);
	sfTexture_destroy(context->end->t_win);
	sfSprite_destroy(context->end->s_loose);
	sfTexture_destroy(context->end->t_loose);
	sfText_destroy(context->score);
	sfFont_destroy(context->font);
	for (int i = 0; map != NULL && map[i] != NULL; i++)
		free(map[i]);
	free(context->end);
	free(context->menu);
	free(context);
}
