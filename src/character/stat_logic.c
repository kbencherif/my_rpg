/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** update character ui
*/

#include "character.h"
#include "monsters.h"
#include "game_data.h"
#include "tile.h"
#include "operator_abstract.h"

void mana_logic(stat_bar_t *mana_bar, sfClock *mana_regen_clock)
{
    if (mana_bar->stat < my_getnbr(mana_bar->max_stat + 1) and
        sfClock_getElapsedTime(mana_regen_clock).microseconds > 100000) {
        mana_bar->stat += 1;
        sfClock_restart(mana_regen_clock);
    }
}

void xp_logic(character_t *character, stat_bar_t *xp_bar)
{
    if (xp_bar->stat >= my_getnbr(xp_bar->max_stat + 1)) {
        xp_bar->stat = 0;
        character->stat_point += 1;
    }
}

void update_character_stat_bar(stat_bar_t *stat_bar)
{
    char *stat_bar_string =
        concate(my_itoa(stat_bar->stat), stat_bar->max_stat);

    sfRectangleShape_setSize(stat_bar->stat_bar,
                (sfVector2f) {stat_bar->stat, 20});
    sfText_setString(stat_bar->bar_text, stat_bar_string);
}

void updata_character_ui(character_t *character)
{
    update_character_stat_bar(character->health_bar);
    update_character_stat_bar(character->mana_bar);
    update_character_stat_bar(character->xp_bar);
}
