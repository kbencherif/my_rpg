/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** inventory's header
*/

#ifndef INVENTORY_H
#define INVENTORY_H
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "setting.h"

enum {
    ARMOR,
    CONSUMABLE_HEAL,
    CONSUMABLE_MANA,
    CONSUMABLE_XP,
    QUEST
};

enum {
    BLANK,
    EQUIPPED,
    SELECTED,
    NORMAL
};

typedef struct item_s
{
    sfTexture *texture;
    sfSprite *sprite;
    bool equipped;
    char *name;
    sfIntRect rect;
    int quantity;
    int max_quantity;
    int value;
    int type;
    int stat;
} item_t;

typedef struct item_list_s
{
    item_t *item;
    struct item_list_s *next;
} item_list_t;

typedef struct inventory_s
{
    sfSprite **slot_boxes;
    sfVector2f *slots_pos;
    sfSprite *background;
    bool open;
    item_list_t *item_list;
    int pos;
} inventory_t;

sfRectangleShape *create_rectangle_shape(setting_t *setting);
void delete_item(item_list_t **item_list, char *item_name);
item_t *create_item_from_config(char *config_file_path, sfTexture *texture,
        int quantity);
inventory_t *init_inventory(void);
void add_item(inventory_t *inventory, item_t *item);
void draw_sprite(sfRenderWindow *win, sfSprite *sprite, sfVector2f origin);
void create_node(item_list_t *item_list, item_t *item);
int get_list_size(item_list_t *item_list);
void draw_box(sfRenderWindow *win, sfSprite **slot_boxes,
        sfVector2f origin, int option);
bool is_item_equipped(item_list_t *item_list, char *name);
bool is_item_in_inventory(item_list_t *item_list, char *name);

#define MAX_SLOTS 32

#endif
