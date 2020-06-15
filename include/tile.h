/*
** EPITECH PROJECT, 2020
** tile
** File description:
** .h
*/

#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct tile
{
    sfRectangleShape *rect;
    sfVector2f pos;
    int texture_nb;
    bool blocked;
} tile_t;

#endif
