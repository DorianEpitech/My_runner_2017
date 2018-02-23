/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** cinematic.c
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "runner.h"

void init_sprite_cinematic(cinematic_t *cinematic)
{
	sfSprite_setTexture(cinematic->sprite1, cinematic->texture1, sfTrue);
	sfSprite_setTexture(cinematic->sprite2, cinematic->texture2, sfTrue);
	sfSprite_setTexture(cinematic->sprite3, cinematic->texture3, sfTrue);
	sfSprite_setTexture(cinematic->sprite4, cinematic->texture4, sfTrue);
	sfSprite_setTexture(cinematic->sprite5, cinematic->texture5, sfTrue);
	sfSprite_setTexture(cinematic->sprite6, cinematic->texture6, sfTrue);
}

cinematic_t *init_cinematic(void)
{
	cinematic_t *cinematic = malloc(sizeof(cinematic_t));

	cinematic->sprite1 = sfSprite_create();
	cinematic->texture1 = sfTexture_createFromFile("obj/cine7.png", NULL);
	cinematic->sprite2 = sfSprite_create();
	cinematic->texture2 = sfTexture_createFromFile("obj/cine6.png", NULL);
	cinematic->sprite3 = sfSprite_create();
	cinematic->texture3 = sfTexture_createFromFile("obj/cine5.png", NULL);
	cinematic->sprite4 = sfSprite_create();
	cinematic->texture4 = sfTexture_createFromFile("obj/cine3.png", NULL);
	cinematic->sprite5 = sfSprite_create();
	cinematic->texture5 = sfTexture_createFromFile("obj/cine2.png", NULL);
	cinematic->sprite6= sfSprite_create();
	cinematic->texture6 = sfTexture_createFromFile("obj/cine.png", NULL);
	init_sprite_cinematic(cinematic);
	return (cinematic);
}
