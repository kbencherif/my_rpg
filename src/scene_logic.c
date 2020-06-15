/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** scene logic
*/

#include "game_data.h"
#include "operator_abstract.h"
#include "inventory.h"
#include "character.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>

void scene_logic(game_data_t *game_data, int *scene)
{
    character_t *character = game_data->character;

    if (character->actual_state is P_DEATH
        and sfClock_getElapsedTime(character->death_clock)
        .microseconds > character->anims[P_DEATH]->ms_per_frame * 5) {
        *scene = DEAD;
    }
}

void continue_playing_after_dying(game_data_t *game_data)
{
    character_t *character = game_data->character;

    set_charac_position(character, character->checkpoint_pos);
    character->attacking = false;
    character->casting = false;
    character->to_animate = false;
    character->health_bar->stat = my_getnbr(
        character->health_bar->max_stat + 1);
    if (character->xp_bar->stat < 10)
        character->xp_bar->stat = 0;
    else
        character->xp_bar->stat -= 10;
    character->actual_state = DOWN;
}

