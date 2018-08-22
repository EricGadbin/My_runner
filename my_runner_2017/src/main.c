/*
** EPITECH PROJECT, 2018
** Runner
** File description:
** main
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

int program(char **argv)
{
	obj_t obj[17];
	window_t *win = malloc(sizeof(window_t));
	sfRenderWindow *window = my_window_create();
	sfEvent event;

	create(obj);
	structset(win, argv);
	sfMusic_play(win->music);
	sfMusic_setLoop(win->music, sfTrue);
	while (sfRenderWindow_isOpen(window))
	{
		events(window, &event, win, obj);
		setstart(win);
		draw_start(obj, win, window);
		choose_display(window, obj, win);
		sfRenderWindow_display(window);
	}
	destroy_object(obj, win);
	sfRenderWindow_destroy(window);
	return (0);
}

int main(int argc, char **argv)
{
	int a = checkstart(argc, argv);

	if (a == 1)
		return (84);
	else if (a == 2)
		return (0);
	program(argv);
	return (0);
}
