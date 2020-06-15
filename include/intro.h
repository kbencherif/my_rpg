/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** intro header
*/

#ifndef INTRO_H
#define INTRO_H
#include <SFML/Graphics.h>
#include <stdbool.h>
#include "button.h"

typedef struct intro_s
{
    bool increase;
    char **intro_lines;
    char **end_lines;
    sfText *text;
    sfText *skip_text;
    sfClock *text_clock;
    sfClock *transparency_clock;
} intro_t;

intro_t *init_intro(void);
void intro_logic(intro_t *intro, int *transparency, int *i, int scene);

#endif
