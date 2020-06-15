/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** map.h
*/

#include "particle_system.h"
#include "monsters.h"
#include "resources.h"
#include "game_data.h"
#include "tile.h"

#ifndef MAP_H_
#define MAP_H_ value

typedef struct iter_monster_t Iter_monster_t;
typedef struct iter_event_t Iter_event_t;

typedef struct event {
    sfIntRect event_rect;
    char *new_map_name;
    sfVector2f new_char_pos;
} event_t;

typedef struct map {
    char *map_name;
    tile_t **tile_map;
    sfVector2f tile_map_size;
    Iter_monster_t *monsters;
    Iter_event_t *events;
    bool block_view;
    bool interior;
} map_t;

sfVector2f get_pos(char *line);
void handle_deplacement(character_t *character, map_t *map, resources_t *res);

#endif /* ifndef MAP_H_ */
