/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** draw info box
*/

#include "info.h"

void draw_info_box(info_t *info_box, sfRenderWindow *win)
{
    sfRenderWindow_drawRectangleShape(win, info_box->box, NULL);
    sfRenderWindow_drawText(win, info_box->text, NULL);
}
