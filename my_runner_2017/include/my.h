/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** my
*/

#include <sys/stat.h>
#include <dirent.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Audio.h>

#ifndef MY_H_
#define MY_H_

typedef struct window_s {
	sfMusic *music;
	sfMusic *fire;
	sfMusic *dead;
	sfMusic *winning;
	sfMusic *boom;
	sfClock *clock;
	sfClock *clock2;
	sfClock *clock3;
	sfClock *clock4;
	sfClock *clock5;
	sfClock *clock6;
	sfClock *clock7;
	sfFont *font;
	sfText *mami;
	sfText *score;
	sfText *score2;
	sfText *you;
	sfText *start;
	sfText *start2;
	int jump;
	int kill;
	int fd;
	char *buffer;
	int up;
	int a;
	int b;
	int in;
	int end;
	float speed;
	int shot;


} window_t;

typedef enum type_s {
	BACKGROUND,
	PNJ,
	AURA,
	BULLET,
	ENM,
	FINALENM,
	ENMBALL,
	END,
	START,
} type_t;

typedef struct obj_s {

	type_t type;
	sfSprite *sprite;
	sfTexture* text;
	sfIntRect rect;
	sfVector2f pos;
	sfVector2f posback;
	sfVector2f speed;
	int (*ptr_move)(struct obj_s *, window_t *);
} obj_t;

int checkstart(int, char **);
void choose_display(sfRenderWindow *, obj_t *, window_t *);
int type(obj_t *, window_t *);
int aura(obj_t *, window_t *);
int collisions5(obj_t *, window_t *);
int collisions4(obj_t *, window_t *);
int collisions3(obj_t *, window_t *);
int collisions2(obj_t *, window_t *);
int collisions(obj_t *, window_t *);
void destroy_object(obj_t *, window_t *);
obj_t create_object(float, type_t, char *, sfVector2f, sfIntRect);
sfRenderWindow *my_window_create(void);
int create2(obj_t *, sfVector2f);
int create(obj_t *);
int draw_end(obj_t *, window_t *, sfRenderWindow *);
int draw_win(obj_t *, window_t *, sfRenderWindow *);
int draw_sprites2(obj_t *, window_t *, sfRenderWindow *);
int draw_sprites(obj_t *, window_t *, sfRenderWindow *);
int draw_start(obj_t *, window_t *, sfRenderWindow *);
int keyboard2(obj_t *, window_t *);
int keyboard(obj_t *, window_t *);
int retry(sfEvent *, window_t *, obj_t *);
int space(sfEvent *, window_t *, obj_t *, int *);
int events(sfRenderWindow *, sfEvent *, window_t *, obj_t *);
int move_back(obj_t *, window_t *);
int move_player(obj_t *, window_t *);
int jump_player(obj_t *, window_t *);
int moveaura(obj_t *, window_t *);
int map(obj_t *, window_t *, sfRenderWindow *);
int move_badend(obj_t *, window_t *);
int move_player_start(obj_t *, window_t *);
int shoot_player(obj_t *, window_t *);
int structset(window_t *, char **);
void movebackground(obj_t *, window_t *);
int move_ball(obj_t *, window_t *);
int move_bad(obj_t *, window_t *);
void my_putstr(char *);
char *my_itoa(int);
void setstart(window_t *);
void setscore(window_t *win);
#endif /* MY_H_ */
