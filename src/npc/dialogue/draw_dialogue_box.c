/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** draw box
*/

#include "game_data.h"
#include <SFML/Audio.h>

void draw_dialogue_box(sfRenderWindow *win, game_data_t *game_data)
{
    sfVector2f pos = {0, 880};

    sfRectangleShape_setPosition(game_data->dialogue_box->background, pos);
    sfText_setPosition(game_data->dialogue_box->text,
            (sfVector2f) {pos.x + 10, pos.y + 10});
    if (game_data->dialogue_box->open == true) {
        sfRenderWindow_drawRectangleShape(
                win, game_data->dialogue_box->background, NULL);
        sfRenderWindow_drawText(win, game_data->dialogue_box->text, NULL);
    }
}
