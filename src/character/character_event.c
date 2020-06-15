/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** character event
*/

#include "anim.h"
#include "inventory.h"
#include <SFML/Audio.h>
#include "character.h"
#include "monsters.h"
#include "game_data.h"
#include "operator_abstract.h"
#include <SFML/Audio.h>
#include <SFML/Audio/Sound.h>

void cast_event(character_t *character, sfEvent event, game_data_t *game_data)
{
    sfVector2f fire_pos  = character->pos;

    if (not character->attacking and not character->casting and
            event.type is sfEvtKeyPressed and
            event.key.code is sfKeyF and character->actual_state isnt P_DEATH
            and character->mana_bar->stat > 300 and
            is_item_equipped(game_data->inventory->item_list, "fire_ring")) {
        reset_anim(character->anims[character->actual_state]);
        character->actual_state = CAST;
        if (sfSound_getStatus(game_data->resources->tab_sound[2]) != sfPlaying)
            sfSound_play (game_data->resources->tab_sound[2]);
        character->mana_bar->stat -= 300;
        character->fire = init_fire_particle_sys((sfVector2f)
                {fire_pos.x + 10, fire_pos.y + 35});
        sfClock_restart(character->cast_clock);
        reset_anim(character->anims[CAST]);
        sfSprite_setTextureRect(character->anims[CAST]->sprite,
                character->anims[CAST]->rect);
        character->to_animate = true;
        character->casting = true;
    }
}

void character_event(sfEvent event, character_t *character,
        game_data_t *game_data)
{
    anim_t *character_anim = character->anims[character->actual_state];

    if (event.type is sfEvtMouseButtonPressed and
            event.mouseButton.button is sfMouseLeft and not character->attacking
            and character->actual_state isnt P_DEATH and not character->casting
            and is_item_equipped(game_data->inventory->item_list, "sword")) {
        sfClock_restart(character->attack_clock);
        character->actual_state += 4;
        character->attacking = true;
        if (sfSound_getStatus(game_data->resources->tab_sound[1]) != sfPlaying)
            sfSound_play(game_data->resources->tab_sound[1]);
        character->to_animate = true;
    }
    cast_event(character, event, game_data);
    if (not character->attacking and not character->casting
            and character->actual_state isnt P_DEATH and
            not (character->to_animate = character_movement_input(character))) {
        character_anim->rect.left = 0;
        sfSprite_setTextureRect(character_anim->sprite, character_anim->rect);
    }
}
