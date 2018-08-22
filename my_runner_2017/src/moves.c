/*
** EPITECH PROJECT, 2018
** Runner
** File description:
** moves2
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"

int move_badend(obj_t *obj, window_t *win)
{
	sfTime time = sfClock_getElapsedTime(win->clock7);
	float seconds = time.microseconds / 1000000.0;

	obj->rect.top = 0;
	if (obj->type == FINALENM && seconds > 0.1) {
		if (obj->rect.left < 860)
			obj->rect.left += 107.5;
		if (obj->rect.left >= 760)
			obj->rect.left = 0;
		sfSprite_setTextureRect(obj->sprite, obj->rect);
		sfClock_restart(win->clock7);
		}
	return (0);
}

int move_bad(obj_t *obj, window_t *win)
{
	sfTime time = sfClock_getElapsedTime(win->clock4);
	float seconds = time.microseconds / 1000000.0;

	obj->rect.top = 0;
	if (obj->type == ENM && seconds > 0.1) {
		if (obj->rect.left < 748)
			obj->rect.left += 187;
		if (obj->rect.left >= 748)
			obj->rect.left = 0;
		sfSprite_setTextureRect(obj->sprite, obj->rect);
		sfClock_restart(win->clock4);
		}
	return (0);
}

int move_ball(obj_t *obj, window_t *win)
{
	sfTime time = sfClock_getElapsedTime(win->clock5);
	float seconds = time.microseconds / 1000000.0;

	obj->rect.top = 0;
	if (obj->type == ENMBALL && seconds > 0.1) {
		if (obj->rect.left < 500)
			obj->rect.left += 100;
		if (obj->rect.left >= 500)
			obj->rect.left = 0;
		sfSprite_setTextureRect(obj->sprite, obj->rect);
		sfClock_restart(win->clock5);
		}
	return (0);
}

int move_player_start(obj_t *obj, window_t *win)
{
	sfTime time = sfClock_getElapsedTime(win->clock6);
	float seconds = time.microseconds / 1000000.0;

	obj->rect.top = 0;
	if (obj->type == START && seconds > 0.1) {
		if (obj->rect.left < 784)
			obj->rect.left += 98;
		if (obj->rect.left >= 784)
			obj->rect.left = 0;
		sfSprite_setTextureRect(obj->sprite, obj->rect);
		sfClock_restart(win->clock6);
		}
	return (0);
}

int move_player(obj_t *obj, window_t *win)
{
	sfTime time = sfClock_getElapsedTime(win->clock);
	float seconds = time.microseconds / 1000000.0;

	obj->rect.top = 0;
	if (obj->type == PNJ && seconds > 0.1) {
		if (obj->rect.left < 742)
			obj->rect.left += 107;
		if (obj->rect.left > 742)
			obj->rect.left = 0;
		sfSprite_setTextureRect(obj->sprite, obj->rect);
		sfClock_restart(win->clock);
		}
	return (0);
}
