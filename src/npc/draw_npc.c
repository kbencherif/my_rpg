/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** draw npc
*/

#include "npc.h"
#include "inventory.h"
#include "operator_abstract.h"
#include "lib.h"

void draw_npcs(sfRenderWindow *win, npc_t **npcs, char *map_name)
{
    for (int i = 0; npcs[i]; i++) {
        if (my_strcmp(npcs[i]->map, map_name) is 1) {
            draw_sprite(win, npcs[i]->sprite, npcs[i]->pos);
        }
    }
}
