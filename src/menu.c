/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** menu.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Time.h>
#include <time.h>
#include "runner.h"

void secondpart_cinematic(context_t *context, float second)
{
	if (sfMusic_getStatus(context->music->cinematic) == sfStopped)
		sfMusic_play(context->music->cinematic);
	sfRenderWindow_clear(context->window, sfBlack);
	if (second < 7) {
		sfRenderWindow_drawSprite(context->window,
		context->cinematic->sprite4, NULL);
	} else if (second < 7.5) {
		sfRenderWindow_drawSprite(context->window,
		context->cinematic->sprite5, NULL);
	} else if (second < 9.5) {
		sfRenderWindow_drawSprite(context->window,
		context->cinematic->sprite6, NULL);
	}
	sfRenderWindow_display(context->window);
}

void firstpart_cinematic(context_t *context, float second)
{
	sfRenderWindow_clear(context->window, sfBlack);
	if (second < 1.5) {
		sfRenderWindow_drawSprite(context->window,
		context->cinematic->sprite1, NULL);
	} else if (second < 3.5) {
		sfRenderWindow_drawSprite(context->window,
		context->cinematic->sprite2, NULL);
	} else if (second < 5.5) {
		sfRenderWindow_drawSprite(context->window,
		context->cinematic->sprite3, NULL);
	}
	sfRenderWindow_display(context->window);
}

void cinematic(context_t *context)
{
	sfClock *clock_cine = sfClock_create();
	sfTime time_cine;
	int check = 0;
	float second = 0;

	while (check != 1) {
		time_cine = sfClock_getElapsedTime(clock_cine);
		second = time_cine.microseconds/1000000.0;
		if (second < 6.5) {
			firstpart_cinematic(context, second);
		} else if (second < 9.5){
			secondpart_cinematic(context, second);
		} else {
			check = 1;
		}
	}
	sfClock_destroy(clock_cine);
}

void menu(context_t *context)
{
	if (sfMusic_getStatus(context->music->menu) == sfStopped)
		sfMusic_play(context->music->menu);
	sfRenderWindow_drawSprite(context->window, context->menu->sprite, NULL);
}
