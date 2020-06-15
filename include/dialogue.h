/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** dialogue struct header
*/

#ifndef DIALOGUE_H
#define DIALOGUE_H
#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct dialogue_box_s
{
    sfRectangleShape *background;
    sfText *text;
    sfClock *dialog_clock;
    bool open;
} dialogue_box_t;

dialogue_box_t *init_dialogue_box(sfFont *font);
char **get_dialogues(char *dialogues_path);

#endif
