/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** info header
*/

#ifndef INFO_H
#define INFO_H
#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct info_s
{
    sfRectangleShape *box;
    sfText *text;
    bool open;
} info_t;

void set_info(char *line, info_t *info_box);
void draw_info_box(info_t *info_box, sfRenderWindow *win);
#endif
