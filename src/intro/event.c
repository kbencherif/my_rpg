/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** intro event file
*/

#include "game_data.h"
#include "operator_abstract.h"
#include "button.h"

void analyse_intro_events(sfEvent event, sfRenderWindow *win, menus_t *menus,
        game_data_t *game_data)
{
    if (event.type is sfEvtClosed)
        sfRenderWindow_close(win);
    if (event.type is sfEvtKeyPressed and event.key.code is sfKeySpace) {
        if (menus->scene is INTRO) {
            menus->scene = GAME;
            set_charac_position(game_data->character,
                    (sfVector2f) {1550, 1080 / 2 - 64});
            game_data->intro_line = 0;
            game_data->intro_first = true;
            game_data->intro_transparency = 0;
        }
        else if (menus->scene is END)
            sfRenderWindow_close(win);
    }
}
