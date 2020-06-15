/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** load saved game
*/

#include <stdio.h>
#include <stdlib.h>
#include "game_data.h"
#include "iterators_prototype.h"
#include "operator_abstract.h"
#include "quests.h"
#include "lib.h"

define_prototype(quest_t);

stat_t *load_saved_stats(FILE *file)
{
    stat_t *stats = malloc(sizeof(stat_t));
    size_t len = 0;
    char *line = NULL;

    stats = malloc(sizeof(stat_t));
    getline(&line, &len, file);
    stats->attack_dmg = my_getnbr(line);
    getline(&line, &len, file);
    stats->spell_dmg = my_getnbr(line);
    getline(&line, &len, file);
    stats->max_health_points = my_getnbr(line);
    getline(&line, &len, file);
    stats->max_mana_points = my_getnbr(line);
    getline(&line, &len, file);
    stats->movement_speed = my_getnbr(line);
    return stats;
}

void load_stats(game_data_t *game_data, FILE *file)
{
    character_t *character = game_data->character;
    resources_t *resources = game_data->resources;
    size_t len = 0;
    char *line = NULL;

    character->stats = load_saved_stats(file);
    init_character_health_bar(character, resources->fantasy_font);
    init_character_mana_bar(character, resources->fantasy_font);
    init_character_xp_bar(character, resources->fantasy_font);
    getline(&line, &len, file);
    game_data->character->health_bar->stat = my_getnbr(line);
    getline(&line, &len, file);
    game_data->character->mana_bar->stat = my_getnbr(line);
    getline(&line, &len, file);
    game_data->character->xp_bar->stat = my_getnbr(line);
    getline(&line, &len, file);
    game_data->character->stat_point = my_getnbr(line);
}

void load_quests(game_data_t *game_data, FILE *file)
{
    size_t len = 0;
    char *lineptr = NULL;
    quest_t *quest = NULL;
    int *data = NULL;

    while (getline(&lineptr, &len, file) != -1) {
        lineptr[my_strlen(lineptr) - 1] = 0;
        quest = init_quest(game_data, lineptr);
        getline(&lineptr, &len, file);
        quest->state = my_getnbr(lineptr);
        getline(&lineptr, &len, file);
        data = malloc(sizeof(int *));
        *data = my_getnbr(lineptr);
        quest->data = data;
        push_front(game_data->quests, quest);
    }
    fclose(file);
}

void load_items(game_data_t *game_data, FILE *file)
{
    size_t len = 0;
    char *lineptr = NULL;
    item_t *item = NULL;
    char *name = NULL;
    int quantity = 0;

    while (getline(&lineptr, &len, file) != -1 and
            not my_strcmp("\n", lineptr)) {
        lineptr[my_strlen(lineptr) - 1] = 0;
        name = my_strdup(lineptr);
        getline(&lineptr, &len, file);
        quantity = my_getnbr(lineptr);
        item = create_item_from_config(concate(concate(
            "config/item/", name), ".item"),
            game_data->resources->item_texture, quantity);
        getline(&lineptr, &len, file);
        item->equipped = my_getnbr(lineptr);
        add_item(game_data->inventory, item);
    }
}

game_data_t *load_game(sfRenderWindow *win)
{
    FILE *file = fopen("config/save", "r");
    game_data_t *game_data;
    size_t len = 0;
    char *lineptr = NULL;
    char *map_name = NULL;
    char *class_name = NULL;

    if (not file)
        return NULL;
    getline(&lineptr, &len, file);
    lineptr[my_strlen(lineptr) - 1] = 0;
    class_name = my_strdup(lineptr);
    getline(&lineptr, &len, file);
    lineptr[my_strlen(lineptr) - 1] = 0;
    map_name = my_strdup(lineptr);
    getline(&lineptr, &len, file);
    game_data = init_game_data(win, class_name, map_name, get_pos(lineptr));
    load_stats(game_data, file);
    load_items(game_data, file);
    load_quests(game_data, file);
    return game_data;
}
