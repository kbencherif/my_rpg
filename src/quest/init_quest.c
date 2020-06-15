/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** load_quest
*/

#include <stdlib.h>
#include "lib.h"
#include "quests.h"
#include "game_data.h"

quest_t *init_sword_quest(sfTexture *item_texture)
{
    quest_t *quest = malloc(sizeof(quest_t));
    int *talked_to_chief = malloc(sizeof(int));

    *talked_to_chief = 0;
    quest->item = create_item_from_config("./config/item/sword.item",
        item_texture, 1);
    quest->state = COMPLETED;
    quest->data = talked_to_chief;
    quest->name = my_strdup("get_sword");
    return quest;
}

quest_t *init_heal_jhon_quest(sfTexture *item_texture)
{
    quest_t *quest = malloc(sizeof(quest_t));
    int *unused = malloc(sizeof(int));

    *unused = 0;
    quest->item = create_item_from_config("./config/item/healing_potion.item",
        item_texture, 1);
    quest->state = NOT_COMPLETED;
    quest->data = unused;
    quest->name = my_strdup("get_heal_from_jhon");
    return quest;
}

quest_t *init_kill_monsters_plain(sfTexture *item_texture)
{
    quest_t *quest = malloc(sizeof(quest_t));
    int *unused = malloc(sizeof(int));

    *unused = 0;
    quest->item = create_item_from_config("./config/item/abandoned_house_key"
        ".item", item_texture, 1);
    quest->state = NOT_COMPLETED;
    quest->data = unused;
    quest->name = my_strdup("kill_monsters_in_plain");
    return quest;
}

quest_t *init_get_fire_ring(sfTexture *item_texture)
{
    quest_t *quest = malloc(sizeof(quest_t));
    int *unused = malloc(sizeof(int));

    *unused = 0;
    quest->item = create_item_from_config("./config/item/fire_ring.item",
        item_texture, 1);
    quest->state = COMPLETED;
    quest->data = unused;
    quest->name = my_strdup("get_fire_ring");
    return quest;
}

quest_t *init_quest(game_data_t *game_data, char *name)
{
    if (my_strcmp(name, "get_sword") == 1)
        return init_sword_quest(game_data->resources->item_texture);
    if (my_strcmp(name, "get_heal_from_jhon") == 1)
        return init_heal_jhon_quest(game_data->resources->item_texture);
    if (my_strcmp(name, "kill_monsters_in_plain") == 1)
        return init_kill_monsters_plain(game_data->resources->item_texture);
    if (my_strcmp(name, "get_fire_ring") == 1)
        return init_get_fire_ring(game_data->resources->item_texture);
    if (my_strcmp(name, "find_my_son") == 1)
        return init_find_my_son(game_data->resources->item_texture);
    return NULL;
}
