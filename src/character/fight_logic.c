/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** char fight logic
*/

#include "character.h"
#include "monsters.h"
#include "operator_abstract.h"
#include "iterators_prototype.h"
#include <SFML/Audio.h>

define_prototype(monster_t);

void apply_fire_to_monsters(Iter(monster_t) *monsters);

void apply_character_damage(character_t *character, int attack_value,
                            resources_t *res)
{
    if (character->health_bar->stat > attack_value) {
        character->health_bar->stat -= attack_value;
        if (sfSound_getStatus(res->tab_sound[4]) != sfPlaying)
            sfSound_play(res->tab_sound[4]);
    }
    else
        character->health_bar->stat = 0;
    character->hitted = true;
    if (character->casting) {
        character->casting = false;
        character->actual_state = DOWN;
    }
    sfClock_restart(character->blink_clock);
    sfClock_restart(character->hit_clock);
}

void handle_character_hit(character_t *character)
{
    if (character->hitted and sfClock_getElapsedTime(character->hit_clock)
        .microseconds > 1500000)
        character->hitted = false;
    if (sfClock_getElapsedTime(character->blink_clock).microseconds > 300000)
        sfClock_restart(character->blink_clock);
}

void handle_character_death(character_t *character)
{
    if (character->health_bar->stat is 0
        and character->actual_state isnt P_DEATH) {
        character->to_animate = true;
        character->actual_state = P_DEATH;
        sfClock_restart(character->death_clock);
    }
    if (character->actual_state is P_DEATH
        and sfClock_getElapsedTime(character->death_clock)
        .microseconds > character->anims[P_DEATH]->ms_per_frame * 5)
        character->to_animate = false;
}

void reset_state_after_attack(character_t *character)
{
    if (character->attacking and character->actual_state isnt P_DEATH
        and sfClock_getElapsedTime(character->attack_clock)
        .microseconds > 60000 * 4) {
        reset_anim(character->anims[character->actual_state]);
        character->actual_state -= 4;
        character->to_animate = false;
        character->attacking = false;
    }
}

void handle_casting_spell(character_t *character, Iter(monster_t) *monsters)
{
    if (character->casting and sfClock_getElapsedTime(
        character->fire->update_clock).microseconds > 10000)
        update_fire_particle_sys(character->fire);
    if (character->casting and sfClock_getElapsedTime(
        character->cast_clock).microseconds > 100000) {
        character->to_animate = false;
    }
    if (character->casting and sfClock_getElapsedTime(
        character->cast_clock).microseconds > 750000)
        character->to_animate = true;
    if (character->casting and sfClock_getElapsedTime(
        character->cast_clock).microseconds > 1100000) {
        character->casting = false;
        character->to_animate = false;
        character->actual_state = DOWN;
        apply_fire_to_monsters(monsters);
    }
}
