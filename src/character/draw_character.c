/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** draw char
*/

#include "monsters.h"
#include "game_data.h"
#include "character.h"
#include "operator_abstract.h"
#include "inventory.h"
#include "tile.h"

void draw_stat_bar(sfRenderWindow *win, stat_bar_t *stat_bar)
{
    sfRenderWindow_drawRectangleShape(win,
            stat_bar->stat_bar, NULL);
    sfRenderWindow_drawRectangleShape(win,
            stat_bar->borders, NULL);
    sfRenderWindow_drawText(win, stat_bar->bar_text, NULL);
}

void draw_character_bars(sfRenderWindow *win, character_t *character)
{
    draw_stat_bar(win, character->health_bar);
    draw_stat_bar(win, character->mana_bar);
    draw_stat_bar(win, character->xp_bar);
}

void draw_character(character_t *character, sfRenderWindow *win)
{
    if (not character->hitted or sfClock_getElapsedTime(character->blink_clock)
        .microseconds < 250000 or character->actual_state is P_DEATH) {
        sfRenderWindow_drawSprite(win, character->anims
            [character->actual_state]->sprite, NULL);
    }
    if (character->casting) {
        draw_fire_particle_sys(character->fire, win);
    }
}
