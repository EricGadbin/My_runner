/*
** EPITECH PROJECT, 2018
** Runner
** File description:
** map
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

void last(window_t *win, sfRenderWindow *window)
{
	char *last = "SHOOT HER !";

	sfText_setColor(win->mami, sfRed);
	sfText_setString(win->mami, last);
	sfText_setFont(win->mami, win->font);
	sfText_setCharacterSize(win->mami, 100);
	sfText_setPosition(win->mami, (sfVector2f){350, 0});
	sfRenderWindow_drawText(window, win->mami, NULL);
}

int map3(obj_t *obj, window_t *win, sfRenderWindow *window)
{
	if (win->buffer[win->in] == '1') {
		obj[6].ptr_move(&(obj[6]), &(*win));
		sfSprite_setPosition(obj[6].sprite, obj[6].pos);
		sfRenderWindow_drawSprite(window, obj[6].sprite, NULL);
	}
	collisions(obj, win);
	return (0);
}

int map2(obj_t *obj, window_t *win, sfRenderWindow *window)
{
	if (win->buffer[win->in] == '2') {
		obj[7].ptr_move(&(obj[7]), &(*win));
		sfSprite_setPosition(obj[7].sprite, obj[7].pos);
		sfRenderWindow_drawSprite(window, obj[7].sprite, NULL);
	}
	if (win->buffer[win->in] == '1' || win->buffer[win->in] == '2') {
		obj[10].ptr_move(&(obj[10]), &(*win));
		sfSprite_setPosition(obj[10].sprite, obj[10].pos);
		sfRenderWindow_drawSprite(window, obj[10].sprite, NULL);
	}
	if (win->buffer[win->in] == '3') {
		obj[10].pos.x = 1270;
		win->up--;
		last(win, window);
		win->end = 1;
		obj[15].ptr_move(&(obj[15]), &(*win));
		sfSprite_setPosition(obj[15].sprite, obj[15].pos);
		sfRenderWindow_drawSprite(window, obj[15].sprite, NULL);
	}
	return (0);
}

int map(obj_t *obj, window_t *win, sfRenderWindow *window)
{
	sfTime time = sfClock_getElapsedTime(win->clock3);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > 0 && (obj[6].pos.x < 40 || obj[7].pos.x < 40)) {
		win->in++;
		obj[7].pos.y = rand()%400;
		obj[6].pos.x = 1200;
		obj[7].pos.x = 1200;
		sfClock_restart(win->clock3);
	}
	if (obj[10].pos.x < 40) {
		sfMusic_play(win->fire);
		obj[10].pos.x = 1200;
		obj[10].pos.y = rand()%400;
	}
	map2(obj, win, window);
	map3(obj, win, window);
	return (0);
}
