/*
** EPITECH PROJECT, 2018
** Runner
** File description:
** print
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

void my_putstr(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		write(1, &str[i], 1);
		i++;
	}
}

char *my_itoa(int nb)
{
	int len = 0;
	char *str;
	int tmp = nb;

	while (tmp > 0) {
		tmp /= 10;
		len++;
	}
	str = malloc(sizeof(*str) * (len + 1));
	str[len] = '\0';
	while (len--) {
		str[len] = nb % 10  + '0';
		nb /= 10;
	}
	return (str);
}

void setstart(window_t *win)
{
	char *play = "Press ENTER";
	char *play2 = "To Start";

	sfText_setString(win->start, play);
	sfText_setFont(win->start, win->font);
	sfText_setCharacterSize(win->start, 150);
	sfText_setString(win->start2, play2);
	sfText_setFont(win->start2, win->font);
	sfText_setCharacterSize(win->start2, 150);
}

void setscore(window_t *win)
{
	char *score_str;
	char *first = "Score: ";
	char *youwin = "YOU WIN !";

	win->up++;
	score_str = my_itoa(win->up);
	sfText_setString(win->you, youwin);
	sfText_setFont(win->you, win->font);
	sfText_setCharacterSize(win->score2, 50);
	sfText_setString(win->score2, first);
	sfText_setFont(win->score2, win->font);
	sfText_setCharacterSize(win->score2, 50);
	sfText_setString(win->score, score_str);
	sfText_setFont(win->score, win->font);
	sfText_setCharacterSize(win->score, 50);
}
