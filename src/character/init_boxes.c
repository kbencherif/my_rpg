/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** initialize char boxes
*/

#include <stdlib.h>
#include <stdio.h>
#include "character.h"
#include "resources.h"

sfIntRect create_box_from_file(char *path, sfVector2f box_pos)
{
    FILE *file = fopen(path, "r");
    size_t len = 0;
    char *line = NULL;
    sfIntRect rect;

    getline(&line, &len, file);
    rect.height = my_getnbr(line);
    getline(&line, &len, file);
    rect.width = my_getnbr(line);
    getline(&line, &len, file);
    rect.left = my_getnbr(line) + box_pos.x;
    getline(&line, &len, file);
    rect.top = my_getnbr(line) + box_pos.y;
    fclose(file);
    return rect;
}

void init_character_hit_boxes(character_t *character)
{
    character->attack_boxes = malloc(sizeof(sfIntRect) * 4);
    character->attack_boxes[UP] = create_box_from_file(
        "./config/charac/up_attack.box", character->pos);
    character->attack_boxes[DOWN] = create_box_from_file(
        "./config/charac/down_attack.box", character->pos);
    character->attack_boxes[RIGHT] = create_box_from_file(
        "./config/charac/right_attack.box", character->pos);
    character->attack_boxes[LEFT] = create_box_from_file(
        "./config/charac/left_attack.box", character->pos);
    character->hitbox = create_box_from_file(
        "./config/charac/hitbox.box", character->pos);
}
