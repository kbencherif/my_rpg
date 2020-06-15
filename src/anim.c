/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** anim abstraction file
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "operator_abstract.h"
#include "anim.h"

void reset_anim(anim_t *anim)
{
    anim->rect.left = 0;
    anim->actual_frame = 1;
    sfClock_restart(anim->anim_clock);
}

int move_rect_left(anim_t *anim, float offset, float max_value)
{
    if (anim->rect.left >= max_value) {
        anim->rect.left = 0;
        anim->actual_frame = 1;
        return 1;
    } else {
        anim->rect.left += offset;
        anim->actual_frame += 1;
        return 0;
    }
}

void animate(anim_t *anim)
{
    if (sfClock_getElapsedTime(anim->anim_clock).microseconds
        > anim->ms_per_frame) {
        move_rect_left(anim, anim->rect.width,
            (anim->nb_frames - 1) * anim->rect.width);
        sfSprite_setTextureRect(anim->sprite, anim->rect);
        sfClock_restart(anim->anim_clock);
    }
}
