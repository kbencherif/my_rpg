/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** flip monster funcs
*/

#include <math.h>
#include "iterators_prototype.h"
#include "monsters.h"
#include "operator_abstract.h"

void flip_monster(monster_t *monster)
{
    sfFloatRect sprite_bounds;

    for (int i = 0; i < NB_MONSTER_ANIM; i++) {
        sprite_bounds = sfSprite_getGlobalBounds(
            monster->anims[i]->sprite);
        sfSprite_setOrigin(monster->anims[i]->sprite,
            (sfVector2f) {sprite_bounds.width, 0});
        sfSprite_setScale(monster->anims[i]->sprite,
            (sfVector2f) {-1, 1});
    }
    monster->attack_offset.x = -monster->attack_offset.x;
    monster->attack_offset.x += monster->hitbox.width;
    monster->attack->rect.width = -monster->attack->rect.width;
    monster->anim_flipped = true;
}

void unflip_monster(monster_t *monster)
{
    for (int i = 0; i < NB_MONSTER_ANIM; i++) {
        sfSprite_setOrigin(monster->anims[i]->sprite, (sfVector2f) {0, 0});
        sfSprite_setScale(monster->anims[i]->sprite, (sfVector2f) {1, 1});
    }
    monster->attack_offset.x = -monster->attack_offset.x;
    monster->attack_offset.x += monster->hitbox.width;
    monster->attack->rect.width = -monster->attack->rect.width;
    monster->anim_flipped = false;
}

void handle_monster_flip(monster_t *monster)
{

    if (monster->movement.x < 0 and not monster->anim_flipped
        and not monster->hitted) {
        flip_monster(monster);
    } else if (monster->movement.x > 0 and monster->anim_flipped
        and not monster->hitted) {
        unflip_monster(monster);
    }
}
