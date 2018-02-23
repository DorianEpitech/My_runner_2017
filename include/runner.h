/*
** EPITECH PROJECT, 2017
** my_runner_2017
** File description:
** runner.h
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#define BLOC_DOWN if (pos.x >= tmp->vector.x + 15\
	&& pos.x <= tmp->vector.x + 100 && pos.y + 100 >= tmp->vector.y\
	&& pos.y + 100 < tmp->vector.y + 30) {\
		context->matoi->pos.y = tmp->vector.y - 100;\
		context->matoi->colision.x = 1;\
		return (1);\
	}
#define BLOC_UP if (pos.x >= tmp->vector.x && pos.x <= tmp->vector.x + 100\
	&& pos.y >= tmp->vector.y + 85 && pos.y < tmp->vector.y + 100) {\
		context->matoi->pos.y = tmp->vector.y + 100;\
		context->matoi->colision.z = 1;\
		return (1);\
	}
#define FALLING if (context->matoi->status == 0 && check == 0) {\
		sfMusic_stop(context->music->run);\
		context->matoi->colision.x = 0;\
		context->matoi->status = 2;\
		context->matoi->rect = (sfIntRect){300, 100, 100, 100};\
	}
#define BLOC_RIGHT if (pos.y >= tmp->vector.y + 15 &&\
	pos.y <= tmp->vector.y + 85 && pos.x + 100 >= tmp->vector.x &&\
	pos.x + 100 < tmp->vector.x + 20) {\
		context->matoi->pos.x = tmp->vector.x - 100;\
		context->matoi->colision.y = 1;\
		return (1);\
	}
#define COLISION_BONUS if (pos.y >= tmp->vector.y + 20 &&\
	pos.y <= tmp->vector.y + 85 && pos.x >= tmp->vector.x + 10 &&\
	pos.x < tmp->vector.x + 80) {\
		destroy_bonus(place, context);\
		context->matoi->score += 5;\
		return (1);\
	}
#define NOT_BLOC if (tmp->type != OBSTACLE) {\
		check = 1;\
	}
#define NOT_BONUS if (tmp->type != BONUS) {\
		check = 1;\
	}
#define CHECK_MAP if (map[0][context->shift_map] == '#'\
	&& context->game_mode == 0) {\
		context->status = ENDWIN;\
	} else if (map[0][context->shift_map] == '/'\
	&& context->game_mode == 1) {\
		context->shift_map = 0;\
	}
#define INIT if (ac == 2 && my_strlen(av[1]) == 2 && av[1][0] == '-'\
	&& av[1][1] == 'h')\
		rules();\
	if ((map = load_2d_arr_from_file(av[1], 0, 0, 0)) == NULL) {\
		destroy_context(context, map);\
		return (84);\
	}

typedef enum type {
	BACKGROUND = 3,
	MIDGROUND = 7,
	FOREGROUND = 10,
	OBSTACLE = 9,
	BONUS = 1,
} type_e;

typedef enum status {
	MENU,
	GAME,
	ENDWIN,
	ENDLOOSE,
} status_e;

typedef struct matoi_s {
	int score;
	sfSprite *sprite;
	sfTexture *texture;
	sfClock *clock;
	sfTime time;
	sfVector2f pos;
	sfVector3f colision;
	sfIntRect rect;
	float second;
	int status;
	float shift;
} matoi_t;

typedef struct cinematic_s {
	sfSprite *sprite1;
	sfTexture *texture1;
	sfSprite *sprite2;
	sfTexture *texture2;
	sfSprite *sprite3;
	sfTexture *texture3;
	sfSprite *sprite4;
	sfTexture *texture4;
	sfSprite *sprite5;
	sfTexture *texture5;
	sfSprite *sprite6;
	sfTexture *texture6;
} cinematic_t;

typedef struct menu_s {
	sfSprite *sprite;
	sfTexture *texture;
	sfSprite *quit;
	sfTexture *texture_quit;
} menu_t;

typedef struct item_s {
	type_e type;
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f vector;
	sfIntRect rect;
	void (*ptr_move)(struct item_s **obj);
	struct item_s *next;
} item_t;

typedef struct music_s {
	sfMusic *run;
	sfMusic *jump;
	sfMusic *game;
	sfMusic *menu;
	sfMusic *lose;
	sfMusic *win;
	sfMusic *cinematic;
} music_t;

typedef struct end_s {
	sfSprite *s_win;
	sfTexture *t_win;
	sfSprite *s_loose;
	sfTexture *t_loose;
} end_t;

typedef struct context_s {
	sfText *score;
	sfFont *font;
	int game_mode;
	int shift_map;
	int timer;
	sfRenderWindow *window;
	sfVideoMode mode;
	status_e status;
	item_t **items;
	music_t *music;
	menu_t *menu;
	end_t *end;
	matoi_t *matoi;
	cinematic_t *cinematic;
} context_t;

void move_item(item_t **);
void replay(context_t *);
context_t *init_context(void);
int colision_bonus(context_t *, sfVector2f);
void destroy_context(context_t *, char **);
void cinematic(context_t *);
void game(context_t *, char **);
void menu(context_t *);
void end(context_t *);
void destroy_obstacle(item_t *, int);
void destroy_all_obstacle(item_t *, int);
void event_menu(sfEvent, context_t *);
void event_game(sfEvent, context_t *);
void event_end(sfEvent, context_t *);
void manage_matoi(context_t *);
void colision(context_t *);
void text_score(context_t *, int);
item_t *create_item(const char *path_to_spritesheet, sfVector2f pos,
	sfIntRect rect, type_e type);
void manage_obstacle(context_t *, char **map);
int my_strlen(char *);
char **load_2d_arr_from_file(char *, int, int, int);
cinematic_t *init_cinematic(void);
item_t **init_items(void);
item_t *add_bonus(context_t *, int, char **);
