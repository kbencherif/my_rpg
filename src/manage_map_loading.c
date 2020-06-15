/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** dungeon_logic file
*/

#include <stdbool.h>
#include "operator_abstract.h"
#include "lib.h"

bool is_locked_event(char *name)
{
    if (my_strcmp(name, "abandoned_house") or
            my_strcmp(name, "dungeon_corridor1") or
            my_strcmp(name, "chef_house") or my_strcmp(name, "basic_house") or
            my_strcmp(name, "donjon_room") or my_strcmp(name,
                "dungeon_corridor2"))
        return true;
    return false;
}
