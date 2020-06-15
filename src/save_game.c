/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** save game file
*/

#include <stdio.h>
#include "game_data.h"
#include "lib.h"
#include "iterators_prototype.h"
#include "operator_abstract.h"
#include "quests.h"

define_prototype(quest_t);

void save_stats(game_data_t *game_data, FILE *file)
{
    character_t *charac = game_data->character;
    stat_t *stats = charac->stats;

    my_fprintf(file, "%i\n", stats->attack_dmg);
    my_fprintf(file, "%i\n", stats->spell_dmg);
    my_fprintf(file, "%i\n%i\n", stats->max_health_points,
        stats->max_mana_points);
    my_fprintf(file, "%i\n", stats->movement_speed);
    my_fprintf(file, "%i\n%i\n", charac->health_bar->stat,
        charac->mana_bar->stat);
    my_fprintf(file, "%i\n", charac->xp_bar->stat);
    my_fprintf(file, "%i\n", charac->stat_point);
}

void save_quest_progress(game_data_t *game_data, FILE *file)
{
    quest_t *next = NULL;
    int *data = malloc(sizeof(int));

    while ((next = next(game_data->quests))) {
        my_fprintf(file, "%s\n", next->name);
        my_fprintf(file, "%i\n", next->state);
        data = next->data;
        my_fprintf(file, "%i\n", *data);
    }
}

void save_inventory(game_data_t *game_data, FILE *file)
{
    item_list_t *item_list = game_data->inventory->item_list;

    while (item_list) {
        my_fprintf(file, "%s\n", item_list->item->name);
        my_fprintf(file, "%i\n", item_list->item->quantity);
        my_fprintf(file, "%i\n", item_list->item->equipped);
        item_list = item_list->next;
    }
    my_fprintf(file, "\n");
}

void save_game(game_data_t *game_data)
{
    FILE *file = fopen("config/save", "w+");

    my_fprintf(file, "%s\n", game_data->character->class_name);
    my_fprintf(file, "%s\n", game_data->map->map_name);
    my_fprintf(file, "%i:%i\n", (int) game_data->character->checkpoint_pos.x,
        (int) game_data->character->checkpoint_pos.y);
    save_stats(game_data, file);
    save_inventory(game_data, file);
    save_quest_progress(game_data, file);
    fclose(file);
}
