/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** character logic file
*/

#include "character.h"
#include "monsters.h"
#include "game_data.h"
#include "tile.h"
#include "operator_abstract.h"
#include "iterators_prototype.h"

define_prototype(monster_t);
define_prototype(tile_t);

void handle_casting_spell(character_t *character, Iter(monster_t) *monsters);

void actualize_character_pos(character_t *character)
{
    sfVector2f sprite_pos;
    sfVector2f content_offset;

    sprite_pos = sfSprite_getPosition(
        character->anims[character->actual_state]->sprite);
    content_offset = character->anims[character->actual_state]->content_offset;
    character->pos.x = sprite_pos.x + content_offset.x;
    character->pos.y = sprite_pos.y + content_offset.y;
}

void update_character(character_t *character, Iter(monster_t) *monsters,
                        game_data_t *game_data)
{
    actualize_character_pos(character);
    handle_deplacement(character, game_data->map, game_data->resources);
    reset_state_after_attack(character);
    mana_logic(character->mana_bar, character->mana_regen_clock);
    xp_logic(character, character->xp_bar);
    updata_character_ui(character);
    handle_character_death(character);
    handle_character_hit(character);
    handle_casting_spell(character, monsters);
}
