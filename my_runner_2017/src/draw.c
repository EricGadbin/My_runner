/*
** EPITECH PROJECT, 2018
** Runner
** File description:
** draw
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

int draw_end(obj_t *obj, window_t *win, sfRenderWindow *window)
{
	for (int i = 8; i != 10; i++) {
		obj[i].ptr_move(&(obj[i]), &(*win));
		sfSprite_setPosition(obj[i].sprite, obj[i].pos);
		sfRenderWindow_drawSprite(window, obj[i].sprite, NULL);
		sfSprite_setPosition(obj[i].sprite, \
		(sfVector2f){obj[i].pos.x - 1275, obj[i].pos.y});
		sfRenderWindow_drawSprite(window, obj[i].sprite, NULL);
	}
	sfText_setCharacterSize(win->score, 100);
	sfText_setCharacterSize(win->score2, 100);
	sfText_setPosition(win->score, (sfVector2f){740, 400});
	sfText_setPosition(win->score2, (sfVector2f){440, 400});
	sfRenderWindow_drawText(window, win->score, NULL);
	sfRenderWindow_drawText(window, win->score2, NULL);
	return (0);
}

int draw_win(obj_t *obj, window_t *win, sfRenderWindow *window)
{
	for (int i = 8; i != 10; i++) {
		obj[i].ptr_move(&(obj[i]), &(*win));
		sfSprite_setPosition(obj[i].sprite, obj[i].pos);
		sfRenderWindow_drawSprite(window, obj[i].sprite, NULL);
		sfSprite_setPosition(obj[i].sprite, \
		(sfVector2f){obj[i].pos.x - 1275, obj[i].pos.y});
		sfRenderWindow_drawSprite(window, obj[i].sprite, NULL);
	}
	sfText_setCharacterSize(win->you, 100);
	sfText_setPosition(win->you, (sfVector2f){440, 0});
	sfRenderWindow_drawText(window, win->you, NULL);
	sfText_setCharacterSize(win->score, 100);
	sfText_setCharacterSize(win->score2, 100);
	sfText_setPosition(win->score, (sfVector2f){740, 400});
	sfText_setPosition(win->score2, (sfVector2f){440, 400});
	sfRenderWindow_drawText(window, win->score, NULL);
	sfRenderWindow_drawText(window, win->score2, NULL);
	return (0);
}

int draw_sprites2(obj_t *obj, window_t *win, sfRenderWindow *window)
{
	if (obj[5].pos.x > 1000) {
		win->shot = 0;
		obj[5].pos.x = 0;
	}
	sfText_setColor(win->score, sfRed);
	sfText_setPosition(win->score, (sfVector2f){1150, 0});
	sfText_setPosition(win->score2, (sfVector2f){1000, 0});
	sfRenderWindow_drawText(window, win->score, NULL);
	sfRenderWindow_drawText(window, win->score2, NULL);
	map(obj, win, window);
	return (0);
}

int draw_sprites(obj_t *obj, window_t *win, sfRenderWindow *window)
{
	for (int i = 0; i != 5; i++) {
		obj[i].ptr_move(&(obj[i]), &(*win));
		sfSprite_setPosition(obj[i].sprite, obj[i].pos);
		sfRenderWindow_drawSprite(window, obj[i].sprite, NULL);
		sfSprite_setPosition(obj[i].sprite, \
		(sfVector2f){obj[i].pos.x - 1275, obj[i].pos.y});
		sfRenderWindow_drawSprite(window, obj[i].sprite, NULL);
	}
	if (win->shot == 1 && obj[5].pos.x < 1000) {
		obj[5].ptr_move(&(obj[5]), &(*win));
		sfSprite_setPosition(obj[5].sprite, obj[5].pos);
		sfRenderWindow_drawSprite(window, obj[5].sprite, NULL);
		sfSprite_setPosition(obj[5].sprite, \
		(sfVector2f){obj[5].pos.x - 1275, obj[5].pos.y});
		sfRenderWindow_drawSprite(window, obj[5].sprite, NULL);
	}
	draw_sprites2(obj, win, window);
	return (0);
}

int draw_start(obj_t *obj, window_t *win, sfRenderWindow *window)
{
	for (int i = 11; i != 15; i++) {
		obj[i].ptr_move(&(obj[i]), &(*win));
		sfSprite_setPosition(obj[i].sprite, obj[i].pos);
		sfRenderWindow_drawSprite(window, obj[i].sprite, NULL);
		sfSprite_setPosition(obj[i].sprite, \
		(sfVector2f){obj[i].pos.x - 1275, obj[i].pos.y});
		sfRenderWindow_drawSprite(window, obj[i].sprite, NULL);
	}
	sfText_setColor(win->start, sfRed);
	sfText_setPosition(win->start, (sfVector2f){240, 150});
	sfText_setPosition(win->start2, (sfVector2f){340, 300});
	sfRenderWindow_drawText(window, win->start, NULL);
	sfRenderWindow_drawText(window, win->start2, NULL);
	return (0);
}
