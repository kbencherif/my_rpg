/*
** EPITECH PROJECT, 2019
** my_world
** File description:
** setting file
*/

#include <stdlib.h>
#include "setting.h"

setting_t *set_background_setting(void)
{
    setting_t *setting = malloc(sizeof(setting_t));
    sfVector2f size = {1920, 200};
    sfVector2f origin = {0, -1080 + size.y};
    setting->size = size;
    setting->origin = origin;
    setting->outline_color = sfWhite;
    setting->within_color = sfBlack;
    setting->thickness = 1.5;
    setting->texture = NULL;
    setting->font = sfFont_createFromFile("./resources/font/Windlass.ttf");
    setting->text_color = sfBlack;
    setting->outline_text_color = sfBlack;
    sfVector2f text_position = {origin.x - 10, origin.y - 10};
    setting->text_position = text_position;

    return setting;
}
