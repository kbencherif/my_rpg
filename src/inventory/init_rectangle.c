/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** rectangle creation file
*/

#include <SFML/Graphics.h>
#include "setting.h"

void set_rectangle_border(setting_t *setting, sfRectangleShape *rectangle)
{
    sfRectangleShape_setOutlineThickness(rectangle, setting->thickness);
    sfRectangleShape_setOutlineColor(rectangle, setting->outline_color);
}

void set_rectangle_within(setting_t *setting, sfRectangleShape *rectangle)
{
    sfRectangleShape_setFillColor(rectangle, setting->within_color);
    sfRectangleShape_setOrigin(rectangle, setting->origin);
    sfRectangleShape_setSize(rectangle, setting->size);
    if (setting->texture != NULL)
        sfRectangleShape_setTexture(rectangle, setting->texture, sfFalse);
}

sfRectangleShape *create_rectangle_shape(setting_t *setting)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    set_rectangle_within(setting, rectangle);
    set_rectangle_border(setting, rectangle);
    return rectangle;
}
