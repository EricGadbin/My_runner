/*
** EPITECH PROJECT, 2018
** Runner
** File description:
** collisions
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

int collisions5(obj_t *obj, window_t *win)
{
	if (((obj[4].pos.x > obj[10].pos.x) && \
	(obj[4].pos.x < obj[10].pos.x + 80)) && \
	(obj[4].pos.y + 70 > obj[10].pos.y + 30) && \
	(obj[4].pos.y < obj[10].pos.y + 100))
	win->a = 2;
	if (((obj[4].pos.x + 30 > obj[10].pos.x) && \
	(obj[4].pos.x < obj[10].pos.x + 80)) && \
	(obj[4].pos.y + 70 > obj[10].pos.y + 30) && \
	(obj[4].pos.y < obj[10].pos.y + 100))
	win->a = 2;
	if (((obj[4].pos.x + 30 > obj[10].pos.x) && \
	(obj[4].pos.x < obj[10].pos.x + 80)) && \
	(obj[4].pos.y + 70 > obj[10].pos.y + 30) && \
	(obj[4].pos.y < obj[10].pos.y + 100))
	win->a = 2;
	return (0);
}

int collisions4(obj_t *obj, window_t *win)
{
	if (((obj[4].pos.x + 30 > obj[7].pos.x) && \
	(obj[4].pos.x < obj[7].pos.x + 80)) && \
	(obj[4].pos.y + 20 > obj[7].pos.y) && \
	(obj[4].pos.y < obj[7].pos.y + 60))
	win->a = 1;
	if (((obj[4].pos.x + 30 > obj[7].pos.x) && \
	(obj[4].pos.x < obj[7].pos.x + 80)) && \
	(obj[4].pos.y + 20 > obj[7].pos.y) && \
	(obj[4].pos.y < obj[7].pos.y + 60))
	win->a = 1;
	if (((obj[4].pos.x > obj[10].pos.x) && \
	(obj[4].pos.x < obj[10].pos.x + 80)) && \
	(obj[4].pos.y > obj[10].pos.y + 30) && \
	(obj[4].pos.y < obj[10].pos.y + 100))
	win->a = 2;
	return (0);
}

int collisions3(obj_t *obj, window_t *win)
{
	if (((obj[4].pos.x + 30 > obj[6].pos.x) && \
	(obj[4].pos.x < obj[6].pos.x + 150)) && \
	(obj[4].pos.y + 90 > obj[6].pos.y) && \
	(obj[4].pos.y < obj[6].pos.y + 187))
	win->a = 1;
	if (((obj[4].pos.x > obj[7].pos.x) && \
	(obj[4].pos.x < obj[7].pos.x + 80)) && \
	(obj[4].pos.y > obj[7].pos.y) && \
	(obj[4].pos.y < obj[7].pos.y + 60))
	win->a = 1;
	if (((obj[4].pos.x > obj[7].pos.x) && \
	(obj[4].pos.x < obj[7].pos.x + 80)) && \
	(obj[4].pos.y + 40 > obj[7].pos.y) && \
	(obj[4].pos.y < obj[7].pos.y + 60))
	win->a = 1;
	return (0);
}

int collisions2(obj_t *obj, window_t *win)
{
	if (((obj[4].pos.x > obj[6].pos.x) && \
	(obj[4].pos.x < obj[6].pos.x + 150)) && \
	(obj[4].pos.y > obj[6].pos.y) && \
	(obj[4].pos.y < obj[6].pos.y + 187))
	win->a = 1;
	if (((obj[4].pos.x > obj[6].pos.x) && \
	(obj[4].pos.x < obj[6].pos.x + 150)) && \
	(obj[4].pos.y + 90 > obj[6].pos.y) && \
	(obj[4].pos.y < obj[6].pos.y + 187))
	win->a = 1;
	if (((obj[4].pos.x + 30 > obj[6].pos.x) && \
	(obj[4].pos.x < obj[6].pos.x + 150)) && \
	(obj[4].pos.y + 90 > obj[6].pos.y) && \
	(obj[4].pos.y < obj[6].pos.y + 187))
	win->a = 1;
	return (0);
}

int collisions(obj_t *obj, window_t *win)
{

	if (((obj[5].pos.x + 150  > obj[15].pos.x) && \
	(obj[5].pos.x + 150 < obj[15].pos.x + 150)) && \
	(obj[5].pos.y + 80 > obj[15].pos.y + 30) && \
	(obj[5].pos.y + 100 < obj[15].pos.y + 187))
		win->a = 3;
	collisions2(obj, win);
	collisions3(obj, win);
	collisions4(obj, win);
	collisions5(obj, win);
	if (win->a == 1)
		sfMusic_play(win->dead);
	if (win->a == 3)
		sfMusic_play(win->winning);

	return (0);
}
