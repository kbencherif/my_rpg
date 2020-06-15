/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init items file
*/

#include "inventory.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include "anim.h"
#include "lib.h"

int get_item_type(char *line)
{
    int i = 0;

    if (line == NULL)
        return -1;
    for (; line[i] != '\n'; i++);
    line[i] = '\0';
    if (my_strcmp(line, "ARMOR") == 1)
        return ARMOR;
    if (my_strcmp(line, "QUEST") == 1)
        return QUEST;
    if (my_strcmp(line, "CONSUMABLE_HEAL") == 1)
        return CONSUMABLE_HEAL;
    if (my_strcmp(line, "CONSUMABLE_XP") == 1)
        return CONSUMABLE_XP;
    if (my_strcmp(line, "CONSUMABLE_MANA") == 1)
        return CONSUMABLE_MANA;
    return -1;
}

void read_item_config_file2(item_t *item, FILE *file)
{
    size_t size = 0;
    char *line = NULL;

    getline(&line, &size, file);
    item->max_quantity = my_getnbr(line);
    getline(&line, &size, file);
    item->value = my_getnbr(line);
    getline(&line, &size, file);
    item->stat = my_getnbr(line);
    fclose(file);
}

void read_item_config_file(item_t *item, char *path)
{
    FILE *file = fopen(path, "r");
    size_t size = 0;
    char *line = NULL;
    int i = 0;

    getline(&line, &size, file);
    for (; line[i] != '\n'; i++);
    line[i] = '\0';
    item->name = my_strdup(line + 7);
    getline(&line, &size, file);
    item->rect.left = my_getnbr(line);
    getline(&line, &size, file);
    item->rect.top = my_getnbr(line);
    getline(&line, &size, file);
    item->rect.width = my_getnbr(line);
    getline(&line, &size, file);
    item->rect.height = my_getnbr(line);
    getline(&line, &size, file);
    item->type = get_item_type(line + 7);
    read_item_config_file2(item, file);
}

item_t *create_item_from_config(char *config_file_path, sfTexture *texture,
        int quantity)
{
    item_t *item = malloc(sizeof(item_t));
    item->equipped = false;
    item->texture = texture;
    item->sprite = sfSprite_create();

    read_item_config_file(item, config_file_path);
    item->quantity = quantity;
    sfSprite_setTexture(item->sprite, texture, sfFalse);
    sfSprite_setTextureRect(item->sprite, item->rect);
    return item;
}
