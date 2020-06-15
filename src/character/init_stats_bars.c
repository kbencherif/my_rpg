/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init stat bars
*/

#include <stdlib.h>
#include <stdio.h>
#include "anim.h"
#include "lib.h"
#include "character.h"
#include "resources.h"

void set_fields(stat_bar_t *stat_bar, sfVector2f bar_text_pos, sfFont *font)
{
    stat_bar->bar_text = sfText_create();
    sfText_setFont(stat_bar->bar_text, font);
    sfText_setPosition(stat_bar->bar_text, bar_text_pos);
    sfText_setColor(stat_bar->bar_text, sfBlack);
    sfText_setCharacterSize(stat_bar->bar_text, 13);
    stat_bar->stat_bar = sfRectangleShape_create();
    stat_bar->borders = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(stat_bar->borders, sfBlack);
    sfRectangleShape_setOutlineThickness(stat_bar->borders, 1.5);
    sfRectangleShape_setFillColor(stat_bar->borders, sfTransparent);
}

void init_character_health_bar(character_t *character, sfFont *font)
{
    stat_bar_t *stat_bar = malloc(sizeof(stat_bar_t));
    sfVector2f stat_bar_position = {10, 10};
    sfVector2f bar_text_position = {12, 12};

    stat_bar->stat = character->stats->max_health_points;
    stat_bar->max_stat = concate("/", my_itoa(
        character->stats->max_health_points));
    set_fields(stat_bar, bar_text_position, font);
    sfRectangleShape_setFillColor(stat_bar->stat_bar, sfGreen);
    sfRectangleShape_setSize(stat_bar->stat_bar,
        (sfVector2f) {stat_bar->stat, 20});
    sfRectangleShape_setSize(stat_bar->borders,
        (sfVector2f) {my_getnbr(stat_bar->max_stat + 1), 20});
    sfRectangleShape_setPosition(stat_bar->stat_bar,
        stat_bar_position);
    sfRectangleShape_setPosition(stat_bar->borders,
        stat_bar_position);
    character->health_bar = stat_bar;
}

void init_character_mana_bar(character_t *character, sfFont *font)
{
    stat_bar_t *stat_bar = malloc(sizeof(stat_bar_t));
    sfVector2f stat_bar_position = {10, 40};
    sfVector2f bar_text_position = {12, 42};

    stat_bar->stat = character->stats->max_mana_points;
    stat_bar->max_stat = concate("/", my_itoa(
        character->stats->max_mana_points));
    set_fields(stat_bar, bar_text_position, font);
    sfRectangleShape_setFillColor(stat_bar->stat_bar, sfBlue);
    sfRectangleShape_setSize(stat_bar->stat_bar,
        (sfVector2f) {stat_bar->stat, 20});
    sfRectangleShape_setSize(stat_bar->borders,
        (sfVector2f) {my_getnbr(stat_bar->max_stat + 1), 20});
    sfRectangleShape_setPosition(stat_bar->stat_bar,
        stat_bar_position);
    sfRectangleShape_setPosition(stat_bar->borders,
        stat_bar_position);
    character->mana_bar = stat_bar;
}

void init_character_xp_bar(character_t *character, sfFont *font)
{
    stat_bar_t *stat_bar = malloc(sizeof(stat_bar_t));
    sfVector2f stat_bar_position = {10, 70};
    sfVector2f bar_text_position = {12, 72};

    stat_bar->stat = 0;
    stat_bar->max_stat = concate("/", my_itoa(100));
    set_fields(stat_bar, bar_text_position, font);
    sfRectangleShape_setFillColor(stat_bar->stat_bar, sfYellow);
    sfRectangleShape_setSize(stat_bar->stat_bar,
        (sfVector2f) {stat_bar->stat, 20});
    sfRectangleShape_setSize(stat_bar->borders,
        (sfVector2f) {100, 20});
    sfRectangleShape_setPosition(stat_bar->stat_bar,
        stat_bar_position);
    sfRectangleShape_setPosition(stat_bar->borders,
        stat_bar_position);
    character->xp_bar = stat_bar;
}
