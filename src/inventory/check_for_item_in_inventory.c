/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** check for item
*/

#include "anim.h"
#include "inventory.h"
#include "character.h"
#include "monsters.h"
#include "game_data.h"
#include "operator_abstract.h"

bool is_item_equipped(item_list_t *item_list, char *name)
{
    item_list_t *head = item_list;

    if (not head)
        return false;
    while (head and my_strcmp(name, head->item->name)
        == 0 && head != NULL) {
        head = head->next;
    }
    if (head and head->item->equipped)
        return true;
    return false;
}

bool is_item_in_inventory(item_list_t *item_list, char *name)
{
    item_list_t *head = item_list;

    if (not head)
        return false;
    while (head and my_strcmp(name, head->item->name)
            == 0 && head != NULL) {
        head = head->next;
    }
    if (head)
        return true;
    return false;
}
