/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** check quests file
*/

#include "info.h"
#include "lib.h"

char *clean_name(char *name)
{
    char *clean_name = my_strdup(name);

    for (int i = 0; clean_name[i]; i++)
        if (clean_name[i] == '_')
            clean_name[i] = ' ';
    return clean_name;
}

void set_info(char *line, info_t *info_box)
{
    sfFloatRect rect = {0, 0, 0, 0};
    sfVector2f origin = {1920 / 2, 800};
    info_box->open = true;

    sfText_setString(info_box->text, line);
    rect = sfText_getGlobalBounds(info_box->text);
    sfRectangleShape_setSize(info_box->box, (sfVector2f)
            {rect.width + 30, rect.height + 30});
    rect = sfRectangleShape_getGlobalBounds(info_box->box);
    origin = (sfVector2f) {origin.x - rect.width / 2,
        origin.y - rect.height / 2};
    sfRectangleShape_setPosition(info_box->box, origin);
    sfText_setPosition(info_box->text, (sfVector2f) {origin.x + 15,
            origin.y + 15});
}
