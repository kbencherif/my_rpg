/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** initialize monster health bar
*/

#include "monsters.h"

sfVector2f get_health_bar_pos(monster_t *monster)
{
    sfVector2f pos = sfSprite_getPosition(monster->anims[M_WALK]->sprite);

    pos.x += monster->anims[M_WALK]->content_offset.x -
        ((monster->health - 30) / 2);
    pos.y += monster->anims[M_WALK]->content_offset.y - 10;
    return pos;
}

void init_monster_health_bar(monster_t *monster)
{
    monster->health = 40;
    monster->health_bar = sfRectangleShape_create();
    sfRectangleShape_setFillColor(monster->health_bar, sfGreen);
    sfRectangleShape_setSize(monster->health_bar,
        (sfVector2f) {monster->health, 5});
    sfRectangleShape_setPosition(monster->health_bar,
        get_health_bar_pos(monster));
}
