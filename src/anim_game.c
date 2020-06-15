/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** anim game
*/

#include "game_data.h"
#include "particle_system.h"
#include "iterators_prototype.h"

define_prototype(monster_t);

void animate_character(character_t *character)
{
    if (character->to_animate)
        animate(character->anims[character->actual_state]);
}

void anim_game(game_data_t *game_data)
{
    monster_t *next = NULL;

    reset(game_data->map->monsters);
    while ((next = next(game_data->map->monsters)))
        animate(next->anims[next->actual_state]);
    if (sfClock_getElapsedTime(game_data->rain_particle_system->update_clock)
        .microseconds > 5000 && !game_data->map->interior)
        update_rain_particle_sys(game_data->rain_particle_system);
    animate_character(game_data->character);
}
