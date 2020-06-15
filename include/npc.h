/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** npc struct
*/

#ifndef NPC_H
#define NPC_H
#include "inventory.h"
#include "dialogue.h"

typedef struct npc_s
{
    char *name;
    char **dialogues;
    sfSprite *sprite;
    sfIntRect interaction_box;
    sfVector2f pos;
    char *map;
} npc_t;

enum {
    QUEST_DIA,
    COMPLETED,
    NOT_COMPLETED,
    REWARDED,
    BLOCKED
};

npc_t **init_npcs(char *npcs_dr);
void draw_npcs(sfRenderWindow *win, npc_t **npcs, char *map_name);

#define NPC_NB 11

#endif
