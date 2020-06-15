/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** fight logic
*/

#include <math.h>
#include "iterators_prototype.h"
#include "monsters.h"
#include "operator_abstract.h"

define_prototype(monster_t);

void remove_invincibility(monster_t *monster)
{
    if (monster->hitted and sfClock_getElapsedTime(monster->hit_clock)
        .microseconds > 300000) {
        monster->hitted = false;
        change_monster_state(monster, M_WALK);
    }
}

void apply_monster_damage(monster_t *monster, int attack_value)
{
    if (monster->health > attack_value)
        monster->health -= attack_value;
    else
        monster->health = 0;
    monster->hitted = true;
    change_monster_state(monster, M_HIT);
    sfClock_restart(monster->hit_clock);
}

void handle_attacking(monster_t *monster, sfIntRect char_hitbox)
{
    int actual_state = monster->actual_state;

    if (sfIntRect_intersects(&monster->attack->rect, &char_hitbox, NULL)
        and actual_state isnt M_DEATH
        and actual_state isnt M_ATTACK) {
        change_monster_state(monster, M_ATTACK);
    } else if (not sfIntRect_intersects(
        &monster->attack->rect, &char_hitbox, NULL)
        and actual_state isnt M_DEATH
        and actual_state is M_ATTACK
        and monster->anims[M_ATTACK]->actual_frame is
        monster->anims[M_ATTACK]->nb_frames) {
        change_monster_state(monster, M_WALK);
    }
}

void handle_death(monster_t *monster, character_t *character)
{
    if (monster->health is 0 and monster->actual_state isnt M_DEATH) {
        change_monster_state(monster, M_DEATH);
        monster->on_fire = false;
        character->xp_bar->stat += 5;
    }
}

void delete_dead_monster(Iter(monster_t) *monsters, monster_t *monster)
{
    if (monster->health is 0
        and monster->anims[M_DEATH]->actual_frame
        is monster->anims[M_DEATH]->nb_frames - 1) {
        delete(monsters, monster);
    }
}
