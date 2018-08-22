/*
** EPITECH PROJECT, 2018
** Runner
** File description:
** choose_moves
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

int type(obj_t *obj, window_t *win)
{
	if (obj->type == FINALENM)
		move_badend(obj, win);
	if (obj->type == ENMBALL)
		move_ball(obj, win);
	if (obj->type == START)
		move_player_start(obj, win);
	return (0);
}

int aura(obj_t *obj, window_t *win)
{
	if (obj->pos.y == 410 || obj->pos.y == 390) {
		if (obj->type == AURA) {
			obj->rect.height = 0;
			obj->rect.top = 200;
			sfSprite_setTextureRect(obj->sprite, obj->rect);
		}
		else if (obj->pos.y == 410)
			move_player(obj, win);
	} else {
		jump_player(obj, win);
		moveaura(obj, win);
	}
	return (0);
}

int move_back(obj_t *obj, window_t *win)
{
	movebackground(obj, win);
	if (obj->pos.x < 0)
		obj->pos.x = 1275;
	if (win->kill == 1 && win->end == 1)
		shoot_player(obj, win);
	if (obj->type == ENM)
		move_bad(obj, win);
	aura(obj, win);
	type(obj, win);
	return (0);
}
