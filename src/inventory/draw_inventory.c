/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** item functions
*/

#include "inventory.h"
#include "game_data.h"

sfVector2f get_slots_pos(inventory_t *inventory)
{
    sfVector2f pos = sfSprite_getPosition(inventory->background);
    pos = (sfVector2f) {pos.x + 22, pos.y + 25};

    return pos;
}

void change_value(inventory_t *inventory, sfVector2f *origin)
{
    static int i = 0;

    inventory->slots_pos[i].x = (*origin).x + 32;
    inventory->slots_pos[i].y = (*origin).y + 32;
    (*origin).x += 65;
    if ((*origin).x >= 65 * 8 + get_slots_pos(inventory).x) {
        (*origin).x = get_slots_pos(inventory).x;
        (*origin).y += 65;
    }
    i++;
    if (i == MAX_SLOTS)
        i = 0;
}

void draw_inventory(sfRenderWindow *win, inventory_t *inventory)
{
    sfVector2f item_origin = get_slots_pos(inventory);
    item_list_t *first_node = inventory->item_list;

    sfRenderWindow_drawSprite(win, inventory->background, NULL);
    for (int i = 0; i < MAX_SLOTS; i++) {
        draw_sprite(win, inventory->slot_boxes[BLANK], item_origin);
        if (inventory->item_list != NULL) {
            draw_sprite(win, inventory->item_list->item->sprite, item_origin);
            draw_box(win, inventory->slot_boxes, item_origin,
                    inventory->item_list->item->equipped);
            inventory->item_list = inventory->item_list->next;
        }
        if (i == inventory->pos)
            draw_box(win, inventory->slot_boxes, item_origin, SELECTED);
        change_value(inventory, &item_origin);
    }
    inventory->item_list = first_node;
}
