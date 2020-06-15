/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** inventory's logic file
*/

#include "character.h"
#include "operator_abstract.h"
#include <stdlib.h>
#include "game_data.h"

void item_interaction(game_data_t *game_data);
void stat_point_logic(game_data_t *game_data, sfRenderWindow *win);

int get_list_size(item_list_t *item_list)
{
    int size = 0;

    if (!item_list)
        return 0;
    for (; item_list->next != NULL; size++)
        item_list = item_list->next;
    return size;
}

void create_node(item_list_t *item_list, item_t *item)
{
    item_list_t *new_item_node = malloc(sizeof(item_list_t));

    new_item_node->item = item;
    new_item_node->next = NULL;
    while (item_list->next != NULL)
        item_list = item_list->next;
    item_list->next = new_item_node;
}

void get_slot_pos(inventory_t *inventory, sfRenderWindow *win)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);
    sfFloatRect bounds = sfSprite_getGlobalBounds(inventory->background);
    sfVector2i gap = {131620, 262350};
    sfVector2i tmp = {0, 0};

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y) is false)
        return;
    for (int i = 0; inventory->slots_pos[i].x != -1; i++) {
        tmp = (sfVector2i) {mouse_pos.x - inventory->slots_pos[i].x,
            mouse_pos.y - inventory->slots_pos[i].y};
        if (tmp.x < 0)
            tmp.x *= -1;
        if (tmp.y < 0)
            tmp.y *= -1;
        if (gap.x >= tmp.x && gap.y >= tmp.y) {
            gap.x = tmp.x;
            gap.y = tmp.y;
            inventory->pos = i;
        }
    }
}

void inventory_event(game_data_t *game_data, sfEvent event,
        sfRenderWindow *win)
{
    if (event.type is sfEvtKeyPressed and event.key.code is sfKeyE) {
        if (game_data->inventory->open is false)
            game_data->inventory->open = true;
        else
            game_data->inventory->open = false;
    }
    if (game_data->inventory->open is true and
            event.type is sfEvtMouseButtonPressed) {
        get_slot_pos(game_data->inventory, win);
        if (event.mouseButton.button is sfMouseRight)
            item_interaction(game_data);
        if (game_data->character->stat_point > 0)
            stat_point_logic(game_data, win);
    }
}
