/*
** EPITECH PROJECT, 2018
** Runner
** File description:
** events
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

int keyboard2(obj_t *obj, window_t *win)
{
	if (sfKeyboard_isKeyPressed(sfKeyRight) && \
	obj[4].pos.x < 1170 && win->a == 0) {
		(obj[3].pos.x += 20);
		(obj[4].pos.x += 20);
	}
	if (obj[3].pos.y > 0 && win->a == 0) {
		if (sfKeyboard_isKeyPressed(sfKeyUp)) {
			(obj[3].pos.y -= 20);
			(obj[4].pos.y -= 20);
		}
	}
	if (obj[4].pos.y < 410 && obj[3].pos.y < 410 && win->a == 0) {
		if (sfKeyboard_isKeyPressed(sfKeyDown)) {
			(obj[3].pos.y += 20);
			(obj[4].pos.y += 20);
		}
	}
	return (0);
}

int keyboard(obj_t *obj, window_t *win)
{
	if (win->a == 2 && obj[4].pos.y != 410) {
		obj[4].pos.y += 10;
		obj[3].pos.y += 10;
		if (obj[4].pos.y == 410)
			win->a = 0;
	}
	if (win->a == 2 && obj[4].pos.y == 410)
		win->a = 0;
	if (sfKeyboard_isKeyPressed(sfKeyLeft) && \
	obj[4].pos.x > 10 && win->a == 0) {
		(obj[3].pos.x -= 20);
		(obj[4].pos.x -= 20);
	}
	keyboard2(obj, win);
	return (0);
}

int retry(sfEvent *event, window_t *win, obj_t *obj)
{
	if (event->type == sfEvtMouseButtonPressed && \
	(win->a == 1 || win->a == 3)) {
		obj[3].pos.x = 0;
		obj[5].pos.y = 0;
		obj[5].pos.x = 1270;
		obj[3].pos.y = 390;
		obj[4].pos.x = 10;
		obj[4].pos.y = 410;
		obj[6].pos.x = 1270;
		obj[7].pos.x = 1270;
		obj[10].pos.x = 1270;
		obj[15].pos.x = 1270;
		win->end = 0;
		win->in = 0;
		win->a = 0;
		win->up = 0;
		win->speed = 0;
	}
	return (0);
}

int space(sfEvent *event, window_t *win, obj_t *obj, int *a)
{
	if (event->key.code == sfKeySpace && win->end == 1) {
		sfMusic_play(win->boom);
		win->kill = 1;
		win->shot = 1;
		obj[5].pos = obj[4].pos;
		*a+= 1;
	}
	return (0);
}

int events(sfRenderWindow *window, sfEvent *event, window_t *win, obj_t *obj)
{
	static int a = 0;

	while (sfRenderWindow_pollEvent(window, event)) {
		if (event->type == sfEvtClosed) {
			sfRenderWindow_close(window);
		}
		if (event->type == sfEvtKeyPressed) {
			space(event, win, obj, &a);
		if (event->key.code == sfKeyReturn)
			win->b = 1;
		}
		retry(event, win, obj);
	}
	return (0);
}
