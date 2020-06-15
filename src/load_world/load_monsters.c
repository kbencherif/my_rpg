/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** load monster when changing map
*/

#include <stdio.h>
#include "monsters.h"
#include "lib.h"
#include "game_data.h"
#include "iterators_prototype.h"

define_prototype(monster_t);

sfVector2f get_pos(char *line)
{
    char **positions = my_str_to_word_array(line, ':');
    sfVector2f parsed_pos = {my_getnbr(positions[0]), my_getnbr(positions[1])};

    return parsed_pos;
}

int get_monster(char *line)
{
    if (my_strcmp(line, "mush"))
        return MUSH;
    if (my_strcmp(line, "skeleton"))
        return SKELETON;
    if (my_strcmp(line, "eye"))
        return EYE;
    if (my_strcmp(line, "goblin"))
        return GOBLIN;
    if (my_strcmp(line, "boss"))
        return BOSS;
    return SKELETON;
}

Iter(monster_t) *load_monsters(char *path, resources_t *res)
{

    FILE *fd = fopen(concate(path, ".monsters"), "r");
    Iter(monster_t) *monsters = new_iter(monster_t);
    size_t size = 0;
    char *lineptr = NULL;
    char **parsed_line = NULL;

    if (!fd)
        return monsters;
    while (getline(&lineptr, &size, fd) != -1) {
        parsed_line = my_str_to_word_array(lineptr, ' ');
        get_monster(parsed_line[0]);
        push_front(monsters, init_monster(res, get_monster(parsed_line[0]),
                                        get_pos(parsed_line[1])));
    }
    fclose(fd);
    return monsters;
}
