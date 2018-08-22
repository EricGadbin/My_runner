/*
** EPITECH PROJECT, 2018
** Runner
** File description:
** arguments
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

int checkstart(int argc, char **argv)
{
	if (argc != 2) {
		write(2, "You have to select a map in argument.\n \
		\nTry '-h' for help\n", 60);
		return (1);
	}
	if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
		my_putstr("USAGE\n ./my_runner maps/map.txt\n \
		\n\nOPTIONS\n -h	print the usage and quit.\n \
		\n\nUSER INTERACTIONS\n SPACE_KEY	shoot.\
		\n ARROW KEYS	running and flying.\n");
		return (2);
	}
	if (argv[1][0] == '-' && argv[1][1] == 'i' && argv[1][2] == '\0') {
		my_putstr("Sorry, i didn't make it. \n \
		\nBut if you want i can show you a little cat: \n \
		\n  	 /\\_/\\\n 	(>^.^<)\n\n");
		return (2);
	}
	return (0);
}

void choose_display(sfRenderWindow *window, obj_t *obj, window_t *win)
{
	if ((win->a != 1 && win->a != 3) && win->b == 1) {
		setscore(win);
		keyboard(obj, win);
		draw_sprites(obj, win, window);
	}
	if (win->a == 1 && win->b == 1) {
		sfMusic_play(win->music);
		draw_end(obj, win, window);
	}
	if (win->a == 3 && win->b == 1) {
		sfMusic_play(win->music);
		draw_win(obj, win, window);
	}
}
