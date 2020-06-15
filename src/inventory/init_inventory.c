/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create inventory file
*/

#include "inventory.h"
#include "game_data.h"
#include <stdlib.h>
#include "lib.h"
#include "setting.h"

void set_bg_pos(sfSprite *sprite, sfVector2f size)
{
    sfVector2f origin = {1920 / 2 - size.x / 2, 1080 / 2 - size.y / 2};
    sfSprite_setPosition(sprite, origin);
}

sfSprite *create_sprite(sfSprite *sprite, char *path)
{
    sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(sprite, texture, sfFalse);

    return sprite;
}

void init_slots_and_background(inventory_t *inventory)
{
    inventory->background = create_sprite(inventory->background,
            "./resources/inventory/texture/inventory.png");
    inventory->slot_boxes = malloc(sizeof(sfSprite *) * (4 + 1));

    inventory->slot_boxes[BLANK] = create_sprite(
            inventory->slot_boxes[BLANK],
            "./resources/inventory/texture/Blank.png");
    inventory->slot_boxes[EQUIPPED] = create_sprite(
            inventory->slot_boxes[EQUIPPED],
            "./resources/inventory/texture/Equiped.png");
    inventory->slot_boxes[SELECTED] = create_sprite(
            inventory->slot_boxes[SELECTED],
            "./resources/inventory/texture/Selected.png");
    inventory->slot_boxes[NORMAL] = create_sprite(
            inventory->slot_boxes[NORMAL],
            "./resources/inventory/texture/Normal.png");
    inventory->slot_boxes[4] = NULL;
}

inventory_t *init_inventory(void)
{
    sfVector2f bg_size = {0, 0};
    sfFloatRect bg_rect = {0, 0, 0, 0};
    inventory_t *inventory = malloc(sizeof(inventory_t));
    inventory->open = false;
    inventory->pos = -1;
    inventory->item_list = NULL;
    inventory->slots_pos = malloc(sizeof(sfVector2f) * (MAX_SLOTS + 1));

    init_slots_and_background(inventory);
    bg_rect = sfSprite_getGlobalBounds(inventory->background);
    bg_size = (sfVector2f) {bg_rect.width, bg_rect.height};
    set_bg_pos(inventory->background, bg_size);
    for (int i = 0; i < MAX_SLOTS; i++)
        inventory->slots_pos[i] = (sfVector2f) {0, 0};
    inventory->slots_pos[MAX_SLOTS] = (sfVector2f) {-1, -1};
    return inventory;
}
