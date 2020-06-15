/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** game intro file
*/

#include "game_data.h"
#include "intro.h"
#include "operator_abstract.h"

void animate_character(character_t *character);

void set_0_for_beginning(bool *first, intro_t *intro, int *transparency)
{
    if (*first is true) {
        sfClock_restart(intro->transparency_clock);
        sfClock_restart(intro->text_clock);
        *first = false;
        *transparency = 0;
    }
}

void reset_everything(game_data_t *game_data, menus_t *menus,
        int *i, bool *first)
{
    game_data->character->to_animate = false;
    menus->scene = GAME;
    set_charac_position(game_data->character,
            (sfVector2f) {1550, 1080 / 2 - 64});
    *i = 0;
    *first = true;
}

void game_intro(sfRenderWindow *win, game_data_t *game_data, menus_t *menus,
        intro_t *intro)
{
    sfEvent event;
    sfVector2f char_pos = {1920 / 2 - 64 / 2, 1080 / 2 - 64 / 2};

    set_0_for_beginning(&game_data->intro_first, intro,
            &game_data->intro_transparency);
    set_charac_position(game_data->character, char_pos);
    while (sfRenderWindow_pollEvent(win, &event))
        analyse_intro_events(event, win, menus, game_data);
    sfRenderWindow_clear(win, sfBlack);
    game_data->character->to_animate = true;
    intro_logic(intro, &game_data->intro_transparency, &game_data->intro_line,
            menus->scene);
    animate_character(game_data->character);
    draw_intro(win, game_data, intro);
    if (menus->scene is INTRO and
            not intro->intro_lines[game_data->intro_line])
            reset_everything(game_data, menus, &game_data->intro_line,
                    &game_data->intro_first);
    if (menus->scene is END)
        if (not intro->end_lines[game_data->intro_line])
        sfRenderWindow_close(win);
}
