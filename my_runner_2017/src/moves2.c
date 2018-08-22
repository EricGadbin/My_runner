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

int jump_player(obj_t *obj, window_t *win)
{
	sfTime time = sfClock_getElapsedTime(win->clock);
	float seconds = time.microseconds / 1000000.0;

	obj[4].rect.top = 140;
	if (obj->type == PNJ && seconds > 0.2) {
		if (obj->rect.left < 107)
			obj->rect.left += 107;
		if (obj->rect.left > 107)
			obj->rect.left = 0;
		sfSprite_setTextureRect(obj->sprite, obj->rect);
		sfClock_restart(win->clock);
	}
	return (0);
}

int moveaura(obj_t *obj, window_t *win)
{
	sfTime time2 = sfClock_getElapsedTime(win->clock2);
	float seconds2 = time2.microseconds / 1000000.0;

	if (obj->type == AURA && seconds2 > 0.08) {
		obj->rect.top = 0;
		obj->rect.height = 140;
		if (obj->rect.left < 510)
		obj->rect.left += 104;
		if (obj->rect.left >= 510)
		obj->rect.left = 8.5;
		sfSprite_setTextureRect(obj->sprite, obj->rect);
		sfClock_restart(win->clock2);
	}
	return (0);
}

int shoot_player(obj_t *obj, window_t *win)
{
	sfTime time = sfClock_getElapsedTime(win->clock);
	float seconds = time.microseconds / 1000000.0;

	obj->rect.top = 140;
	if (obj->type == PNJ && seconds > 0.1) {
		if (obj->rect.left < 842)
			obj->rect.left += 107;
		if (obj->rect.left > 842) {
			obj->rect.left = 0;
			win->kill = 0;
		}
		sfSprite_setTextureRect(obj->sprite, obj->rect);
		sfClock_restart(win[0].clock);
		}
	return (0);
}

void movebackground(obj_t *obj, window_t *win)
{
	static float i = 0;

	if (obj->type == BACKGROUND || obj->type == ENM) {
		obj->pos.x -= obj->speed.x - i - win->speed;
		obj->posback.x -= obj->speed.x -i - win->speed;
		if (win->speed > -40 && win->b == 1)
			win->speed -= 0.005;
	} else {
		obj->pos.x -= obj->speed.x;
		obj->posback.x -= obj->speed.x;
	}
}
