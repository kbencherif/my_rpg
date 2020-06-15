/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** load_quest2
*/

#include <stdlib.h>
#include "lib.h"
#include "quests.h"
#include "game_data.h"

quest_t *init_find_my_son(sfTexture *item_texture)
{
    quest_t *quest = malloc(sizeof(quest_t));
    int *unused = malloc(sizeof(int));

    *unused = 0;
    quest->item = create_item_from_config("./config/item/healing_potion.item",
        item_texture, 1);
    quest->state = NOT_COMPLETED;
    quest->data = unused;
    quest->name = my_strdup("find_my_son");
    return quest;
}
