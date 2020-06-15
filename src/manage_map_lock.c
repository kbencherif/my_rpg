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

void dungeon_logic(game_data_t *game_data, event_t *next);
void set_map(game_data_t *game_data, event_t *next);
void village_houses_management(game_data_t *game_data, event_t *next);

define_prototype(monster_t);
define_prototype(event_t);

void manage_lock_map(game_data_t *game_data, event_t *next)
{
    if (my_strcmp(next->new_map_name, "abandoned_house") and
            sfIntRect_intersects(&next->event_rect,
            &game_data->character->walking_rect, NULL) and
            is_item_in_inventory(game_data->inventory->item_list,
                "abandoned_house_key"))
        set_map(game_data, next);
    dungeon_logic(game_data, next);
    village_houses_management(game_data, next);
}
