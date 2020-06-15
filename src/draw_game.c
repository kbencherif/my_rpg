/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** draw game
*/

#include "monsters.h"
#include "game_data.h"
#include "character.h"
#include "iterators_prototype.h"
#include "operator_abstract.h"
#include "inventory.h"
#include "tile.h"
#include "button.h"

define_prototype(monster_t);
define_prototype(event_t);

void draw_monster(monster_t *monster, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, monster->anims
            [monster->actual_state]->sprite, NULL);
    if (monster->on_fire)
        draw_fire_particle_sys(monster->fire, win);
}

void draw_map(sfRenderWindow *win, tile_t **tile_map)
{
    for (int i = 0; tile_map[i]; i++) {
        sfRenderWindow_drawRectangleShape(win, tile_map[i]->rect, NULL);
    }
}

void draw_ui(game_data_t *game_data, sfRenderWindow *win)
{
    const sfView *ig_view = sfRenderWindow_getView(win);
    sfRenderWindow_setView(win, sfRenderWindow_getDefaultView(win));
    character_t *character = game_data->character;

    if (not game_data->map->interior)
        draw_rain_particle_sys(game_data->rain_particle_system, win);
    draw_character_bars(win, character);
    draw_dialogue_box(win, game_data);
    if (game_data->character->stat_point > 0 and
            game_data->inventory->open is true)
        draw_stat_point_ui(win, game_data);
    if (game_data->inventory->open is true) {
        draw_inventory(win, game_data->inventory);
        game_data->info_box->open = false;
    }
    if (game_data->info_box->open is true)
        draw_info_box(game_data->info_box, win);
    sfRenderWindow_setView(win, ig_view);
}

void draw_game(game_data_t *game_data, sfRenderWindow *win)
{
    monster_t *next = NULL;

    draw_map(win, game_data->map->tile_map);
    draw_npcs(win, game_data->npcs, game_data->map->map_name);
    draw_character(game_data->character, win);
    reset(game_data->map->monsters);
    while ((next = next(game_data->map->monsters)))
        draw_monster(next, win);
    reset(game_data->map->monsters);
    while ((next = next(game_data->map->monsters)))
        if (next->health > 0)
            sfRenderWindow_drawRectangleShape(win, next->health_bar, NULL);
    draw_ui(game_data, win);
}
