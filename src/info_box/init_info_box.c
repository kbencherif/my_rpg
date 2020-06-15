/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init box info
*/

#include <stdlib.h>
#include "info.h"

info_t *init_info_box(sfFont *font)
{
    info_t *info_box = malloc(sizeof(info_t));

    info_box->open = false;
    info_box->text = sfText_create();
    info_box->box = sfRectangleShape_create();
    sfText_setFont(info_box->text, font);
    sfText_setColor(info_box->text, sfWhite);
    sfRectangleShape_setFillColor(info_box->box, sfBlack);
    sfRectangleShape_setOutlineColor(info_box->box, sfWhite);
    sfRectangleShape_setOutlineThickness(info_box->box, 2);
    return info_box;
}
