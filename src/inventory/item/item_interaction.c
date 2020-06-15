/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** items' interaction file
*/

#include "game_data.h"
#include "operator_abstract.h"

void apply_effect(int type, character_t *character, item_t *item)
{
    switch (type) {
        case ARMOR:
            if (item->equipped is false)
                item->equipped = true;
            else
                item->equipped = false;
            break;
        case CONSUMABLE_HEAL:
            character->health_bar->stat += item->stat;
            if (character->health_bar->stat >
                    character->stats->max_health_points)
                character->health_bar->stat =
                    character->stats->max_health_points;
            break;
        case CONSUMABLE_MANA:
            character->mana_bar->stat += item->stat;
            if (character->mana_bar->stat >
                    character->stats->max_mana_points)
                character->mana_bar->stat =
                    character->stats->max_mana_points;
    }
}

void item_interaction(game_data_t *game_data)
{
    item_list_t *reset = game_data->inventory->item_list;

    for (int i = 0; game_data->inventory->item_list and
            i < game_data->inventory->pos; i++)
        game_data->inventory->item_list =
            game_data->inventory->item_list->next;
    if (game_data->inventory->item_list) {
        apply_effect(game_data->inventory->item_list->item->type,
                game_data->character, game_data->inventory->item_list->item);
        if (game_data->inventory->item_list->item->type isnt ARMOR and
                game_data->inventory->item_list->item->type isnt QUEST)
            game_data->inventory->item_list->item->quantity -= 1;
        if (game_data->inventory->item_list->item->quantity <= 0)
            delete_item(&reset, game_data->inventory->item_list->item->name);
    }
    game_data->inventory->item_list = reset;
}
