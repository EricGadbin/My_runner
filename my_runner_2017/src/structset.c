/*
** EPITECH PROJECT, 2018
** Runner
** File description:
** structset
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

int structset3(window_t *win)
{
	win->score = sfText_create();
	win->score2 = sfText_create();
	win->start = sfText_create();
	win->start2 = sfText_create();
	win->you = sfText_create();
	win->mami = sfText_create();
	win->font = sfFont_createFromFile("./im/ok2.ttf");
	win->music = sfMusic_createFromFile("./im/music.ogg");
	win->fire = sfMusic_createFromFile("./im/fire.ogg");
	win->dead = sfMusic_createFromFile("./im/dead.ogg");
	win->winning = sfMusic_createFromFile("./im/win.ogg");
	win->boom = sfMusic_createFromFile("./im/bullet.wav");
	return (0);
}

int structset2(window_t *win)
{
	win->jump = 0;
	win->up = 0;
	win->a = 0;
	win->b = 0;
	win->in = 0;
	win->speed = 0;
	win->end = 0;
	win->kill = 0;
	win[0].clock = sfClock_create();
	win[0].clock2 = sfClock_create();
	win[0].clock3 = sfClock_create();
	win[0].clock4 = sfClock_create();
	win[0].clock5 = sfClock_create();
	win[0].clock6 = sfClock_create();
	win[0].clock7 = sfClock_create();
	structset3(win);
	return (0);
}

int structset(window_t *win, char **argv)
{
	char *str = malloc(sizeof(char) * 4096);
	int j = 0;

	win->fd = open(argv[1], O_RDONLY);
	win->buffer = malloc(sizeof(char) * 4096);
	for (int j = 0; j != 4096; j++)
		str[j] = '0';
	read(win->fd, str, 4095);
	while (str[j] == '1' || str[j] == '2' || str[j] == '3') {
			win->buffer[j] = str[j];
			j++;
		}
	win->buffer[j] = '\0';
	free(str);
	structset2(win);
	return (0);
}
