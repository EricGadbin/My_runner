/*
** EPITECH PROJECT, 2018
** Runner
** File description:
** create
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

void destroy_object(obj_t *obj, window_t *win)
{
	for (int i = 0; i != 16; i++) {
		sfTexture_destroy(obj[i].text);
		sfSprite_destroy(obj[i].sprite);
	}
	sfMusic_destroy(win->music);
	sfMusic_destroy(win->fire);
	sfMusic_destroy(win->dead);
	sfMusic_destroy(win->winning);
	sfMusic_destroy(win->boom);
	sfText_destroy(win->score);
	sfText_destroy(win->score2);
	sfText_destroy(win->start);
	sfText_destroy(win->start2);
	sfText_destroy(win->you);
	sfClock_destroy(win->clock);
	sfClock_destroy(win->clock2);
	sfClock_destroy(win->clock3);
	sfClock_destroy(win->clock4);
	sfClock_destroy(win->clock5);
	sfClock_destroy(win->clock6);
}

obj_t create_object(float s, type_t t, char *p, sfVector2f o, sfIntRect r)
{
	sfColor color = {255, 255, 255, 190};
	obj_t obj;
	obj.type = t;
	obj.speed.x = s;
	obj.ptr_move = &move_back;
	obj.pos = o;
	obj.rect = r;
	obj.text = sfTexture_createFromFile(p, NULL);
	obj.sprite = sfSprite_create();
	sfSprite_setTexture(obj.sprite, obj.text, sfTrue);
	sfSprite_setTextureRect(obj.sprite, obj.rect);
	if (obj.type == AURA)
		sfSprite_setColor(obj.sprite, color);
	return (obj);
}

sfRenderWindow *my_window_create(void)
{
	sfRenderWindow *window;
	sfVideoMode mode;

	mode.width = 1275;
	mode.height = 600;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "My Runner", sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	return (window);
}

int create2(obj_t *obj, sfVector2f posflybad)
{
	sfVector2f posbad = {1200, 350};
	sfVector2f pos = {0, 0};
	sfVector2f posaura = {0, 390};
	sfIntRect rectaura = {8.5, 300, 104, 0};
	sfIntRect rect = {0, 0, 1275, 600};
	sfIntRect rectbad = {0, 0, 187, 203};

	obj[0] = create_object(0, BACKGROUND, "./im/sky.png", pos, rect);
	obj[1] = create_object(2, BACKGROUND, "./im/city2.png", pos, rect);
	obj[2] = create_object(5, BACKGROUND, "./im/ground.png", pos, rect);
	obj[3] = create_object(0, AURA, "./im/fly2.png", posaura, rectaura);
	obj[6] = create_object(7, ENM, "./im/bad.png", posbad, rectbad);
	obj[7] = create_object(8, ENM, "./im/badfly.png", posflybad, rectbad);
	obj[8] = create_object(0, END, "./im/end.png", pos, rect);
	obj[11] = create_object(0, BACKGROUND, "./im/sky.png", pos, rect);
	obj[12] = create_object(0, BACKGROUND, "./im/city2.png", pos, rect);
	obj[13] = create_object(0, BACKGROUND, "./im/ground.png", pos, rect);
	return (0);
}

int create(obj_t *obj)
{
	sfVector2f posplay = {10, 410};
	sfIntRect rectplay = {0, 0, 107, 140};
	sfIntRect rectstart = {0, 0, 107, 140};
	sfVector2f posflybad = {1200, 20};
	sfVector2f posbed = {1200, 410};
	sfIntRect rectbed = {0, 0, 107.5, 203};
	sfVector2f posend = {520, 150};
	sfIntRect rectend = {0, 0, 247, 246};
	sfIntRect rectb = {0, 0, 100, 150};
	sfIntRect rectbul = {20, 60, 250, 170};

	obj[4] = create_object(0, PNJ, "./im/sprite.png", posplay, rectplay);
	obj[5] = create_object(-40, BULLET, "./im/bul.png", posplay, rectbul);
	obj[9] = create_object(0, END, "./im/restart.png", posend, rectend);
	obj[10] = create_object(18, ENMBALL, "./im/fire.png", posflybad, rectb);
	obj[14] = create_object(0, START, "./im/start.png", posplay, rectstart);
	obj[15] = create_object(2, FINALENM, "./im/mami.png", posbed, rectbed);
	create2(obj, posflybad);
	return (0);
}
