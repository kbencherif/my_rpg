/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** main file
*/

#include "game_data.h"
#include "operator_abstract.h"
#include <SFML/Graphics/Rect.h>
#include <SFML/Audio.h>

char *clean_name(char *name);

void set_dialogue_box(npc_t *npc, dialogue_box_t *dialogue_box, int choice)
{
    dialogue_box->open = true;
    sfText_setString(dialogue_box->text, npc->dialogues[choice]);
}

void give_locket(game_data_t *game_data, quest_t *quest)
{
    item_t *ring = create_item_from_config("./config/item/son_ring.item",
            game_data->resources->item_texture, 1);

    add_item(game_data->inventory, ring);
    quest->state = COMPLETED;
    set_info(concate("You've got : ", clean_name(ring->name)),
            game_data->info_box);
}

void give_second_floor_key(game_data_t *game_data)
{
    item_t *key = create_item_from_config(
            "./config/item/boss_key.item",
            game_data->resources->item_texture, 1);

    add_item(game_data->inventory, key);
    set_info("You've got : the first boss key", game_data->info_box);
}

void special_quest(game_data_t *game_data, int i)
{
    quest_t *quest = NULL;

    if ((quest = search_for_quest(game_data->quests,
            "get_heal_from_jhon")) and my_strcmp(
            game_data->npcs[i]->name, "get_sword") is 1)
        quest->state = COMPLETED;
    if ((quest = search_for_quest(game_data->quests,
            "find_my_son")) and quest->state is NOT_COMPLETED and my_strcmp(
                game_data->npcs[i]->name, "son") is 1)
            give_locket(game_data, quest);
    if (my_strcmp(game_data->map->map_name, "dungeon_fight_zone") and
            my_strcmp(game_data->npcs[i]->name, "zz_laprod") and not
            is_item_in_inventory(game_data->inventory->item_list,
                "boss_key"))
        give_second_floor_key(game_data);
}

void search_npc(game_data_t *game_data)
{
    sfFloatRect npc_rect = {0, 0, 0, 0};
    sfFloatRect player_rect = {0, 0, 0, 0};

    for (int i = 0; game_data->npcs[i]; i++) {
        npc_rect = sfSprite_getGlobalBounds(game_data->npcs[i]->sprite);
        player_rect = sfSprite_getGlobalBounds(
                game_data->character->anims[0]->sprite);
        if (sfFloatRect_intersects(&npc_rect, &player_rect, NULL) == sfTrue
                and my_strcmp(game_data->npcs[i]->map,
                    game_data->map->map_name) is 1) {
            special_quest(game_data, i);
            check_quests(game_data,
                    game_data->npcs[i]->name, game_data->npcs[i]);
            sfSound_play(game_data->resources->tab_sound[3]);
        }
    }
}
