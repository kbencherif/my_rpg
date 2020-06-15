/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** dialogue box initialisation file
*/

#include "dialogue.h"
#include <stdlib.h>

dialogue_box_t *init_dialogue_box(sfFont *font)
{
    sfVector2f box_size = {1920, 200};
    dialogue_box_t *dialogue_box = malloc(sizeof(dialogue_box_t));
    dialogue_box->text = sfText_create();
    dialogue_box->background = sfRectangleShape_create();
    dialogue_box->open = false;

    sfText_setFont(dialogue_box->text, font);
    sfText_setFillColor(dialogue_box->text, sfWhite);
    sfText_setCharacterSize(dialogue_box->text, 23);
    sfRectangleShape_setFillColor(dialogue_box->background, sfBlack);
    sfRectangleShape_setSize(dialogue_box->background, box_size);
    sfRectangleShape_setOutlineColor(dialogue_box->background, sfWhite);
    sfRectangleShape_setOutlineThickness(dialogue_box->background, 1.5);
    return dialogue_box;
}
