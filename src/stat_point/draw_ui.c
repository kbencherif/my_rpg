/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** draw stat point ui
*/

#include "game_data.h"

void draw_stat_point_ui(sfRenderWindow *win, game_data_t *game_data)
{
    sfRenderWindow_drawRectangleShape(
            win, game_data->stat_point_ui->background, sfFalse);
    sfText_setString(game_data->stat_point_ui->text, concate("SKILL PTS: ",
                my_itoa(game_data->character->stat_point)));
    sfRenderWindow_drawText(win, game_data->stat_point_ui->text, sfFalse);
    for (int i = 0; game_data->stat_point_ui->icons[i]; i++)
        sfRenderWindow_drawSprite(win,
                game_data->stat_point_ui->icons[i], sfFalse);
}
