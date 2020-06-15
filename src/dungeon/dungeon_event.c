/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** dungeon_logic file
*/

#include <math.h>
#include "monsters.h"
#include "game_data.h"
#include "character.h"
#include "iterators_prototype.h"
#include "operator_abstract.h"

define_prototype(monster_t);
define_prototype(event_t);

map_t *load_map(sfTexture **tile_tex, char *map_name, game_data_t *game_data);
void village_houses_management(game_data_t *game_data, event_t *next);

void set_map(game_data_t *game_data, event_t *next)
{
    game_data->map = load_map(game_data->resources->tile_tex,
            next->new_map_name, game_data);
    set_charac_position(game_data->character, next->new_char_pos);
    game_data->character->checkpoint_pos = next->new_char_pos;
}

void dungeon_logic(game_data_t *game_data, event_t *next)
{
    quest_t *quest = search_for_quest(game_data->quests, "get_fire_ring");

    if (quest->state is REWARDED and sfIntRect_intersects(
            &next->event_rect, &game_data->character->walking_rect, NULL) and
            quest and my_strcmp(next->new_map_name, "dungeon_corridor1"))
            set_map(game_data, next);
    if (is_item_in_inventory(game_data->inventory->item_list, "boss_key")
            and sfIntRect_intersects(&next->event_rect, &game_data->character
            ->walking_rect, NULL) and my_strcmp(next->new_map_name,
                "donjon_room"))
        set_map(game_data, next);
    if (sfIntRect_intersects(&next->event_rect, &game_data->character->
            walking_rect, NULL) and my_strcmp(next->new_map_name,
            "dungeon_pre_boss3-1") and is_empty(game_data->map->monsters))
        set_map(game_data, next);
    if (sfIntRect_intersects(&next->event_rect, &game_data->character->
            walking_rect, NULL) and my_strcmp(next->new_map_name,
            "dungeon_corridor2") and is_empty(game_data->map->monsters))
        set_map(game_data, next);
}
