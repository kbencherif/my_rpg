/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** intro initialisation
*/

#include <stdlib.h>
#include "button.h"
#include "game_data.h"
#include "intro.h"

char **get_dialogues(char *dialogues_path);

intro_t *init_intro(void)
{
    intro_t *intro = malloc(sizeof(intro_t));
    sfFont *font = sfFont_createFromFile("./resources/font/Windlass.ttf");

    intro->increase = true;
    intro->skip_text = sfText_create();
    intro->transparency_clock = sfClock_create();
    intro->text_clock = sfClock_create();
    intro->intro_lines = get_dialogues("./config/intro.txt");
    intro->end_lines = get_dialogues("./config/end.txt");
    intro->text = sfText_create();
    sfText_setFont(intro->text, font);
    sfText_setFont(intro->skip_text, font);
    sfText_setColor(intro->skip_text, sfWhite);
    sfText_setString(intro->skip_text, "Press space key to skip");
    sfText_setPosition(intro->skip_text, (sfVector2f) {100, 1000});
    return intro;
}
