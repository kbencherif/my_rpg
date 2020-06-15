/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** monster movement funcs
*/

#include <math.h>
#include "monsters.h"
#include "operator_abstract.h"

void actualize_monster_pos(monster_t *monster)
{
    sfVector2f sprite_pos;
    sfVector2f content_offset;

    sprite_pos = sfSprite_getPosition(
        monster->anims[monster->actual_state]->sprite);
    content_offset = monster->anims[monster->actual_state]->content_offset;
    monster->pos.x = sprite_pos.x + content_offset.x;
    monster->pos.y = sprite_pos.y + content_offset.y;
}

void move_monster(monster_t *monster, sfVector2f offset)
{
    sfVector2f pos = monster->pos;

    if (not monster or monster->actual_state is M_DEATH)
        return;
    for (int i = 0; i < NB_MONSTER_ANIM; i++)
        sfSprite_move(monster->anims[i]->sprite, offset);
    sfRectangleShape_move(monster->health_bar, offset);
    monster->hitbox.left = monster->pos.x;
    monster->hitbox.top = monster->pos.y;
    monster->walking_rect = monster->hitbox;
    monster->walking_rect.top += monster->walking_rect.height;
    monster->walking_rect.left += 2;
    monster->walking_rect.width -= 2;
    monster->walking_rect.height = 3;
    monster->attack->rect.left = monster->pos.x + monster->attack_offset.x;
    monster->attack->rect.top = monster->pos.y + monster->attack_offset.y;
    if (monster->on_fire)
        system_set_position(monster->fire, (sfVector2f)
            {pos.x + 5, pos.y + 10});
}

float get_norm(float x, float y)
{
    return (sqrt(x * x + y * y));
}

void get_movement_vector(monster_t *monster, sfIntRect char_hitbox)
{
    sfVector2f movement =
        {monster->pos.x - char_hitbox.left, monster->pos.y - char_hitbox.top};
    float norm = get_norm(movement.x, movement.y);

    if ((monster->actual_state is M_ATTACK
        and not monster->hitted) or monster->actual_state is M_DEATH) {
        monster->movement.x = 0;
        monster->movement.y = 0;
        return;
    }
    if (not monster->hitted) {
        monster->movement.x = -(movement.x / norm) * monster->speed_factor;
        monster->movement.y = -(movement.y / norm) * monster->speed_factor;
    } else if (monster->actual_state isnt M_DEATH) {
        monster->movement.x -= -(movement.x / norm) / 2;
        monster->movement.y -= -(movement.y / norm) / 2;
    }
}
