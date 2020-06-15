/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** quest header
*/

#ifndef QUEST_H_
#define QUEST_H_
#define UNUSED __attribute__((unused))
#include <stdbool.h>
#include "inventory.h"

typedef struct quest {
    char *name;
    int state;
    void *data;
    item_t *item;
} quest_t;

typedef quest_t *(*ptrf)(sfTexture *item_texture);
typedef struct iter_quest_t Iter_quest_t;

quest_t *init_sword_quest(sfTexture *item_texture);
quest_t *init_heal_jhon_quest(sfTexture *item_texture);
quest_t *search_for_quest(Iter_quest_t *quest_list, char *quest_name);
quest_t *init_kill_monsters_plain(sfTexture *item_texture);
quest_t *init_get_fire_ring(sfTexture *item_texture);
quest_t *init_find_my_son(sfTexture *item_texture);

typedef struct init_quest
{
    char *name;
    ptrf func;
} init_quest_t;

static init_quest_t UNUSED QUESTS[] = {
    {"get_sword", init_sword_quest},
    {"get_heal_from_jhon", init_heal_jhon_quest},
    {"kill_monsters_in_plain", init_kill_monsters_plain},
    {"get_fire_ring", init_get_fire_ring},
    {"find_my_son", init_find_my_son},
    {NULL, NULL}
};

#endif /* ifndef QUEST_H_ */
