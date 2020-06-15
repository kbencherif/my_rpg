/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** game intro logic file
*/

#include "intro.h"
#include "operator_abstract.h"
#include "game_data.h"

void set_text(sfText *text, char *line, int transparency)
{
    sfFloatRect rect = {0, 0, 0, 0};
    sfVector2f origins = {1920 / 2, 200};

    sfText_setString(text, line);
    rect = sfText_getGlobalBounds(text);
    origins.x -= rect.width / 2;
    sfText_setPosition(text, origins);
    sfText_setColor(text, (sfColor) {255, 255, 255, transparency});
}

void intro_logic(intro_t *intro, int *transparency, int *i, int scene)
{
    set_text(intro->text, intro->intro_lines[*i], *transparency);
    if (scene is END)
        set_text(intro->text, intro->end_lines[*i], *transparency);
    if (sfClock_getElapsedTime(intro->text_clock).microseconds > 4000000) {
        intro->increase = false;
        if (sfClock_getElapsedTime(intro->text_clock).microseconds
                > 5000000) {
            *i += 1;
            sfClock_restart(intro->text_clock);
            intro->increase = true;
        }
    }
    if (sfClock_getElapsedTime(intro->transparency_clock).
            microseconds > 250000) {
        if (intro->increase is true and *transparency < 100)
            *transparency += 25;
        else if (intro->increase is false and *transparency > 0)
            *transparency -= 25;
        sfClock_restart(intro->transparency_clock);
    }
}
