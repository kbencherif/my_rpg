/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** draw game intro file
*/

#include "game_data.h"

void draw_map(sfRenderWindow *win, tile_t **tile_map);

void draw_intro(sfRenderWindow *win, game_data_t *game_data, intro_t *intro)
{
    const sfView *ig_view = sfRenderWindow_getView(win);

    sfRenderWindow_setView(win, sfRenderWindow_getDefaultView(win));
    sfRenderWindow_drawText(win, intro->text, NULL);
    sfRenderWindow_drawText(win, intro->skip_text, NULL);
    sfRenderWindow_setView(win, ig_view);
    draw_character(game_data->character, win);
    sfRenderWindow_display(win);
}
