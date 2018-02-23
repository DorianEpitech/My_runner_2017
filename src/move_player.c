/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** move_player.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include "runner.h"

void jump_up(matoi_t *matoi)
{
	if (matoi->second < 0.05) {
		matoi->rect = (sfIntRect){0, 100, 100, 100};
	} else if (matoi->second < 0.25){
		matoi->rect = (sfIntRect){100, 100, 100, 100};
		matoi->pos.y -= matoi->shift;
		matoi->shift -= 0.29;
	} else {
		matoi->rect = (sfIntRect){200, 100, 100, 100};
		matoi->pos.y -= matoi->shift;
		matoi->shift -= 0.29;
	}
}

void jump_down(matoi_t *matoi)
{
	if (matoi->second < 1) {
		matoi->rect = (sfIntRect){300, 100, 100, 100};
		matoi->pos.y += matoi->shift;
		matoi->shift += 0.29;
	} else {
		matoi->rect = (sfIntRect){400, 100, 100, 100};
		matoi->pos.y += matoi->shift;
		matoi->shift += 0.29;
	}
}

void jump_matoi(matoi_t *matoi)
{
	matoi->time = sfClock_getElapsedTime(matoi->clock);
	matoi->second = matoi->time.microseconds / 1000000.0;
	if (matoi->colision.x != 1 && matoi->second <= 0.5
	&& matoi->colision.z != 1) {
		jump_up(matoi);
	} else if (matoi->colision.x != 1) {
		jump_down(matoi);
	} else if (matoi->colision.x == 1) {
		matoi->colision.z = 0;
		matoi->status = 0;
		matoi->second = 0;
		sfClock_restart(matoi->clock);
		matoi->rect = (sfIntRect){0, 0, 100, 100};
		matoi->shift = 13;
	}

}

void move_matoi(matoi_t *matoi)
{
	matoi->time = sfClock_getElapsedTime(matoi->clock);
	matoi->second = matoi->time.microseconds / 1000000.0;
	if (matoi->colision.x == 1 && matoi->colision.y != 1
	&& matoi->pos.x != 250)
		matoi->pos.x += 1;
	while (matoi->second > 0.09) {
		matoi->second = 0;
		sfClock_restart(matoi->clock);
		if (matoi->rect.left != 700)
			matoi->rect.left += 100;
		else
			matoi->rect.left = 0;
	}
}

void manage_matoi(context_t *context)
{
	if (context->matoi->colision.y == 1)
		context->matoi->pos.x = context->matoi->pos.x - 10;
	if (context->matoi->status == 0) {
		move_matoi(context->matoi);
	} else if (context->matoi->status == 1){
		jump_matoi(context->matoi);
	} else {
		context->matoi->pos.y += 7.5;
	}
	sfSprite_setPosition(context->matoi->sprite, context->matoi->pos);
	sfRenderWindow_drawSprite(context->window,
	context->matoi->sprite, NULL);
	sfSprite_setTextureRect(context->matoi->sprite, context->matoi->rect);
}
