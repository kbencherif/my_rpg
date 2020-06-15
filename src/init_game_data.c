/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init game data
*/

#include <SFML/Graphics.h>
#include "game_data.h"
#include "iterators_prototype.h"

define_prototype(quest_t);

map_t *load_map(sfTexture **tile_tex, char *map_name,
                        game_data_t *game_data);
info_t *init_info_box(sfFont *font);

void init_ui(game_data_t *game_data, sfRenderWindow *win,
            sfVector2f char_pos)
{
    game_data->view = sfView_createFromRect((sfFloatRect) {0, 0, 1920, 1080});
    game_data->inventory = init_inventory();
    game_data->stat_point_ui = init_stat_point_ui(game_data->resources->
            fantasy_font, game_data->inventory->background);
    game_data->dialogue_box = init_dialogue_box(game_data->
            resources->fantasy_font);
    game_data->info_box = init_info_box(game_data->resources->fantasy_font);
    sfView_setCenter(game_data->view, char_pos);
    sfRenderWindow_setView(win, game_data->view);
}

game_data_t *init_game_data(sfRenderWindow *win, char *class_name,
                            char *map_name, sfVector2f char_pos)
{
    game_data_t *game_data = malloc(sizeof(game_data_t));

    game_data->rain_particle_system = init_rain_particle_sys();
    game_data->resources = init_resources();
    game_data->quests = new_iter(quest_t);
    game_data->sounds_volume = 50;
    game_data->music_volume = 50;
    game_data->intro_transparency = 0;
    game_data->intro_line = 0;
    game_data->intro_first = true;
    game_data->character = init_character(game_data->resources, char_pos,
                                        class_name);
    game_data->map = load_map(game_data->resources->tile_tex,
                                    map_name, game_data);
    init_ui(game_data, win, char_pos);
    game_data->npcs = init_npcs("./config/npc/");
    return game_data;
}
