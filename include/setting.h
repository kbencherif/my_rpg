/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** setting header
*/

#ifndef SETTING_H
#define SETTING_H
#include <SFML/Graphics.h>

typedef struct setting_s
{
    sfVector2f size;
    sfVector2f origin;
    sfColor outline_color;
    float thickness;
    sfColor within_color;
    sfTexture *texture;
    sfFont *font;
    sfColor text_color;
    sfColor outline_text_color;
    sfVector2f text_position;
} setting_t;


setting_t *set_background_setting(void);
setting_t *set_slot_setting(void);

#endif
