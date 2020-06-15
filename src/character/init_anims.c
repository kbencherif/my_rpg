/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** initialize character anims
*/

#include <stdlib.h>
#include "anim.h"
#include "character.h"
#include "resources.h"

void set_anims_positions(character_t *character, sfVector2f char_pos)
{
    sfVector2f sprite_pos;
    sfVector2f content_offset;
    sfVector2f anim_pos;

    for (int i = 0; i < NB_ANIMS; i++) {
        sprite_pos = sfSprite_getPosition(
            character->anims[i]->sprite);
        content_offset = character->anims[i]->content_offset;
        anim_pos.x = char_pos.x + sprite_pos.x - content_offset.x;
        anim_pos.y = char_pos.y + sprite_pos.y - content_offset.y;
        sfSprite_setPosition(character->anims[i]->sprite, anim_pos);
    }
}

void init_char_attacks_anims(character_t *character, charac_texts_t *char_texts)
{
    character->anims[UP_ATTACK] = create_anim_config(
        char_texts->up_attack, "./config/charac/up_attack.anim");
    character->anims[LEFT_ATTACK] = create_anim_config(
        char_texts->left_attack, "./config/charac/left_attack.anim");
    character->anims[RIGHT_ATTACK] = create_anim_config(
        char_texts->right_attack, "./config/charac/right_attack.anim");
    character->anims[DOWN_ATTACK] = create_anim_config(
        char_texts->down_attack, "./config/charac/down_attack.anim");
    character->anims[CAST] = create_anim_config(
        char_texts->cast, "./config/charac/cast.anim");
}

void init_char_movements_anims(character_t *character,
                                charac_texts_t *char_texts)
{
    character->anims[DOWN] = create_anim_config(char_texts->walk_down,
                                            "./config/charac/walk_down.anim");
    character->anims[UP] = create_anim_config(char_texts->walk_up,
                                            "./config/charac/walk_up.anim");
    character->anims[RIGHT] = create_anim_config(char_texts->walk_right,
                                            "./config/charac/walk_right.anim");
    character->anims[LEFT] = create_anim_config(char_texts->walk_left,
                                            "./config/charac/walk_left.anim");
}

void initialize_animations(character_t *character, resources_t *resources)
{
    character->anims = malloc(sizeof(anim_t *) * NB_ANIMS);
    init_char_movements_anims(character, resources->character_texts);
    init_char_attacks_anims(character, resources->character_texts);
    character->anims[P_DEATH] = create_anim_config(
        resources->character_texts->death, "./config/charac/death.anim");
}
