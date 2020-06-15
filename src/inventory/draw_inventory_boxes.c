/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** item functions
*/

#include "inventory.h"

void draw_sprite(sfRenderWindow *win, sfSprite *sprite, sfVector2f origin)
{
    sfSprite_setPosition(sprite, origin);
    sfRenderWindow_drawSprite(win, sprite, NULL);
}

void draw_box(sfRenderWindow *win, sfSprite **slot_boxes,
        sfVector2f origin, int option)
{
    if (option == EQUIPPED) {
        sfSprite_setPosition(slot_boxes[EQUIPPED], origin);
        sfRenderWindow_drawSprite(win, slot_boxes[EQUIPPED], NULL);
    }
    else {
        sfSprite_setPosition(slot_boxes[NORMAL], origin);
        sfRenderWindow_drawSprite(win, slot_boxes[NORMAL], NULL);
    }
    if (option == SELECTED) {
        sfSprite_setPosition(slot_boxes[SELECTED], origin);
        sfRenderWindow_drawSprite(win, slot_boxes[SELECTED], NULL);
    }
}
