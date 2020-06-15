/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** dungeon_logic file
*/

#include "monsters.h"
#include "game_data.h"
#include "character.h"
#include "iterators_prototype.h"
#include "operator_abstract.h"

void set_map(game_data_t *game_data, event_t *next);

void village_houses_management(game_data_t *game_data, event_t *next)
{
    quest_t *quest = search_for_quest(game_data->quests, "find_my_son");

    if (quest and my_strcmp(next->new_map_name, "basic_house"))
        if (quest->state is REWARDED and sfIntRect_intersects(
            &next->event_rect, &game_data->character->walking_rect, NULL))
            set_map(game_data, next);
    quest = search_for_quest(game_data->quests, "get_heal_from_jhon");
    if (quest and my_strcmp(next->new_map_name, "chef_house"))
        if (sfIntRect_intersects(&next->event_rect,
                    &game_data->character->walking_rect, NULL))
            set_map(game_data, next);
}
