/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** collisions logic file
*/

#include "monsters.h"
#include "character.h"
#include "operator_abstract.h"

void charac_attack_monster_collision(monster_t *monster, attack_t *attack)
{
    if (not monster->hitted and attack
        and monster->actual_state isnt M_DEATH
        and sfIntRect_intersects(&monster->hitbox, &attack->rect, NULL))
        apply_monster_damage(monster, attack->damages);
}

void monster_body_character_body_collision(character_t *character,
        monster_t *monster, resources_t *res)
{
    if (not character->hitted and character->actual_state isnt P_DEATH
        and sfIntRect_intersects(
        &character->walking_rect, &monster->hitbox, NULL))
        apply_character_damage(character, monster->body_damages, res);
}

void monster_attack_and_charac(character_t *character, monster_t *monster,
                                resources_t *res)
{
    if (not character->hitted and character->actual_state isnt P_DEATH
        and monster->actual_state is M_ATTACK and
        sfIntRect_intersects(&monster->attack->rect,
        &character->hitbox, NULL) and
        monster->anims[M_ATTACK]->actual_frame is 7) {
        apply_character_damage(character, monster->attack->damages, res);
    }
}

void collisions_logic(character_t *character, monster_t *monster,
        attack_t *attack, resources_t *res)
{
    charac_attack_monster_collision(monster, attack);
    monster_body_character_body_collision(character, monster, res);
    monster_attack_and_charac(character, monster, res);
}
