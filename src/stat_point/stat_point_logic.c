/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** stat point logic
*/

#include "game_data.h"
#include "operator_abstract.h"

int get_icons(stat_point_ui_t *stat_points_ui, sfRenderWindow *win)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);
    sfFloatRect mouse_rect = {mouse_pos.x, mouse_pos.y, 20, 20};
    sfFloatRect icon_rect = {0, 0, 0, 0};
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(
            stat_points_ui->background);

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y) is false)
        return -1;
    for (int i = 0; stat_points_ui->icons[i]; i++) {
        icon_rect = sfSprite_getGlobalBounds(stat_points_ui->icons[i]);
        if (sfFloatRect_intersects(&mouse_rect, &icon_rect, NULL) is true)
            return i;
    }
    return -1;
}

void increase_stat(stat_bar_t *stat, int value)
{
    stat->stat += value;
    stat->max_stat = concate("/", my_itoa(
        my_getnbr(stat->max_stat + 1) + value));
    sfText_setString(stat->bar_text, stat->max_stat);
    sfRectangleShape_setSize(stat->stat_bar,
        (sfVector2f) {stat->stat, 20});
    sfRectangleShape_setSize(stat->borders,
        (sfVector2f) {my_getnbr(stat->max_stat + 1), 20});
}

void stat_point_logic(game_data_t *game_data, sfRenderWindow *win)
{
    int check = 0;

    switch ((check = get_icons(game_data->stat_point_ui, win))) {
        case HEALTH:
            game_data->character->stats->max_health_points += 100;
            increase_stat(game_data->character->health_bar, 100);
            break;
        case MANA:
            game_data->character->stats->max_mana_points += 100;
            increase_stat(game_data->character->mana_bar, 100);
            break;
        case SPELL:
            game_data->character->stats->spell_dmg += 5;
            break;
        case SWORD:
            game_data->character->stats->attack_dmg += 3;
            break;
    }
    if (check isnt -1)
        game_data->character->stat_point--;
}
