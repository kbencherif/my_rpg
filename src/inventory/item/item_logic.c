/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** items' logic file
*/

#include "inventory.h"
#include "lib.h"
#include <stdlib.h>

int check_item_max_quantity(item_list_t *item_list, item_t *item)
{
    int node = 0;

    while (item_list) {
        if (my_strcmp(item->name, item_list->item->name) == 1)
            break;
        item_list = item_list->next;
        node++;
    }
    if (!item_list)
        return 0;
    while (item_list->next &&
            my_strcmp(item->name, item_list->next->item->name) == 1)
        node++;
    if (item_list->item->quantity + item->quantity > item->max_quantity)
        return 0;
    return node;
}

void add_quantity(item_list_t *item_list, int quantity, int node)
{
    for (int i = 0; i < node; i++)
        item_list = item_list->next;
    item_list->item->quantity += quantity;
}

void add_item(inventory_t *inventory, item_t *item)
{
    int node = 0;

    if (inventory->item_list == NULL) {
        inventory->item_list = malloc(sizeof(item_list_t));
        inventory->item_list->item = item;
        inventory->item_list->next = NULL;
    }
    else if (get_list_size(inventory->item_list) < MAX_SLOTS) {
        if ((node = check_item_max_quantity(inventory->item_list, item)) == 0) {
            create_node(inventory->item_list, item);
        }
        else
            add_quantity(inventory->item_list, item->quantity, node);
    }
}

void delete_item(item_list_t **item_list, char *item_name)
{
    item_list_t *head = *item_list;
    item_list_t *prev = NULL;

    while (my_strcmp(item_name, head->item->name)
            == 0 && head != NULL) {
        prev = head;
        head = head->next;
    }
    if (head) {
        if (head == prev || !prev) {
            *item_list = head->next;
            free(head);
        }
        else {
            prev->next = head->next;
            free(head);
        }
    }
}
