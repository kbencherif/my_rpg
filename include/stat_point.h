/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** stat_point ui
*/

#ifndef STAT_POINT_H
#define STAT_POINT_H
#include <SFML/Graphics.h>

typedef struct stat_point_ui
{
    sfRectangleShape *background;
    sfSprite **icons;
    sfText *text;
} stat_point_ui_t;

enum {
    HEALTH,
    MANA,
    SWORD,
    SPELL,
    LEN
};

stat_point_ui_t *init_stat_point_ui(sfFont *font, sfSprite *inventory);
#endif
