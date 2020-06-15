/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** check quests file
*/

#include <stdlib.h>
#include "iterators_prototype.h"
#include "game_data.h"
#include "operator_abstract.h"
#include "quests.h"
#include "npc.h"
#include "lib.h"

define_prototype(quest_t);
#define struct iter_quest_t quest_inlist
void set_dialogue_box(npc_t *npc, dialogue_box_t *dialogue_box, int choice);
char *clean_name(char *name);

quest_t *search_for_quest(Iter(quest_t) *quest_list, char *quest_name)
{
    quest_t *quest = NULL;

    while ((quest = next(quest_list))) {
        if (my_strcmp(quest->name, quest_name)) {
            reset(quest_list);
            return quest;
        }
    }
    reset(quest_list);
    return NULL;
}

void check_completed(npc_t *npc, game_data_t *game_data, quest_t *quest)
{
    set_dialogue_box(npc, game_data->dialogue_box, quest->state);
    if (quest->state is COMPLETED) {
        add_item(game_data->inventory, quest->item);
        set_info(concate("You've got : ", clean_name(quest->item->name)),
                game_data->info_box);
        if (my_strcmp(npc->name, "find_my_son") is 1)
            delete_item(&game_data->inventory->item_list, "son_ring");
        quest->state = REWARDED;
    }
}

void block_quest(Iter(quest_t) *quest_list, quest_t *quest,
        npc_t *npc, dialogue_box_t *dialogue_box)
{
    quest_t *find_my_son_quest = search_for_quest(quest_list, "find_my_son");

    if (my_strcmp(quest->name, "find_my_son") is 0) {
        if (find_my_son_quest and find_my_son_quest->state is REWARDED) {
            push_front(quest_list, quest);
            set_dialogue_box(npc, dialogue_box, QUEST_DIA);
        }
        else
            set_dialogue_box(npc, dialogue_box, BLOCKED);
    }
    else {
        push_front(quest_list, quest);
        set_dialogue_box(npc, dialogue_box, QUEST_DIA);
    }
}

void check_quests(game_data_t *game_data, char *quest_name, npc_t *npc)
{
    int i = 0;
    quest_t *quest = NULL;

    while ((quest = next(game_data->quests))) {
        if (my_strcmp(quest->name, quest_name) is 1) {
            check_completed(npc, game_data, quest);
            break;
        }
    }
    for (; QUESTS[i].name and
        my_strcmp(QUESTS[i].name, quest_name) is 0; i++);
    if (not QUESTS[i].name)
        set_dialogue_box(npc, game_data->dialogue_box, QUEST_DIA);
    else if (not quest)
        if (QUESTS[i].name) {
            quest = QUESTS[i].func(game_data->resources->item_texture);
            block_quest(game_data->quests, quest,
                    npc, game_data->dialogue_box);
        }
    reset(game_data->quests);
}
