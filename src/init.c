/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** item.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "runner.h"

matoi_t *init_matoi(void)
{
	matoi_t *matoi = malloc(sizeof(matoi_t));

	matoi->sprite = sfSprite_create();
	matoi->texture = sfTexture_createFromFile("obj/matoi.png", NULL);
	matoi->pos = (sfVector2f){250, 788};
	matoi->colision = (sfVector3f){1, 0, 0};
	matoi->rect = (sfIntRect){0, 0, 100, 100};
	matoi->clock = sfClock_create();
	matoi->second = 0;
	matoi->status = 0;
	matoi->shift = 13;
	matoi->score = 0;
	sfSprite_setTexture(matoi->sprite, matoi->texture, sfTrue);
	sfSprite_setPosition(matoi->sprite, matoi->pos);
	return (matoi);
}

end_t *init_end(void)
{
	end_t *end = malloc(sizeof(end_t));

	end->s_win = sfSprite_create();
	end->t_win = sfTexture_createFromFile("obj/win.png", NULL);
	sfSprite_setTexture(end->s_win, end->t_win, sfTrue);
	end->s_loose = sfSprite_create();
	end->t_loose = sfTexture_createFromFile("obj/loose.png", NULL);
	sfSprite_setTexture(end->s_loose, end->t_loose, sfTrue);
	return (end);
}

menu_t *init_menu(void)
{
	menu_t *menu = malloc(sizeof(menu_t));

	menu->sprite = sfSprite_create();
	menu->texture = sfTexture_createFromFile("obj/menu.png", NULL);
	menu->quit = sfSprite_create();
	menu->texture_quit = sfTexture_createFromFile("obj/cross.png", NULL);
	sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
	sfSprite_setTexture(menu->quit, menu->texture_quit, sfTrue);
	sfSprite_setPosition(menu->quit, (sfVector2f){20, 20});
	return (menu);
}

music_t *init_music(void)
{
	music_t *music = malloc(sizeof(music_t));

	music->game = sfMusic_createFromFile("obj/kill_wa_ill.ogg");
	music->menu = sfMusic_createFromFile("obj/menu.ogg");
	music->lose = sfMusic_createFromFile("obj/lose.ogg");
	music->win = sfMusic_createFromFile("obj/matoi.ogg");
	music->cinematic = sfMusic_createFromFile("obj/cinematic.ogg");
	music->run = sfMusic_createFromFile("obj/run.ogg");
	music->jump = sfMusic_createFromFile("obj/jump.ogg");
	return (music);
}

context_t *init_context(void)
{
	context_t *context = malloc(sizeof(context_t));
	sfVideoMode mode = {1920, 1080, 32};

	context->mode = mode;
	context->game_mode = 0;
	context->shift_map = 0;
	context->timer = 0;
	context->window = sfRenderWindow_create(mode, "My Runner", sfFullscreen | sfResize, NULL);
	context->status = MENU;
	context->menu = init_menu();
	context->end = init_end();
	context->items = init_items();
	context->music = init_music();
	context->cinematic = init_cinematic();
	context->matoi = init_matoi();
	context->score = sfText_create();
	context->font = sfFont_createFromFile("obj/score.TTF");
	return (context);
}
