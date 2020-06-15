/*
** EPITECH PROJECT, 2020
** load_map
** File description:
** .c
*/

#include <stdio.h>
#include "tile.h"
#include "lib.h"
#include "game_data.h"
#include "iterators_prototype.h"

Iter(monster_t) *load_monsters(char *path, resources_t *res);
Iter(event_t) *load_events(char *path);

void set_rectangle(tile_t *tile, sfTexture **tile_tex)
{
    sfVector2u text_size = sfTexture_getSize(tile_tex[tile->texture_nb]);
    sfVector2f true_size = {text_size.x, text_size.y};

    tile->rect = sfRectangleShape_create();
    sfRectangleShape_setTexture(tile->rect,
        tile_tex[tile->texture_nb], sfFalse);
    sfRectangleShape_setSize(tile->rect, true_size);
    sfRectangleShape_setPosition(tile->rect, tile->pos);
}

void get_map_info(map_t *map, FILE *fd)
{
    char *lineptr = NULL;
    char **parsed_line = NULL;
    size_t len = 0;

    getline(&lineptr, &len, fd);
    map->block_view = my_getnbr(lineptr);
    getline(&lineptr, &len, fd);
    map->interior = my_getnbr(lineptr);
    getline(&lineptr, &len, fd);
    parsed_line = my_str_to_word_array(lineptr, ':');
    map->tile_map_size.x = my_getnbr(parsed_line[0]);
    map->tile_map_size.y = my_getnbr(parsed_line[1]);
}

tile_t *parsed_tile_info(char *lineptr, sfTexture **tile_tex)
{
    tile_t *new_tile = malloc(sizeof(tile_t));
    char **parsed_line = NULL;
    char **buffer = NULL;

    parsed_line = my_str_to_word_array(lineptr, ' ');
    buffer = my_str_to_word_array(parsed_line[0], ':');
    new_tile->pos = (sfVector2f) {my_getnbr(buffer[0]),
        my_getnbr(buffer[1])};
    buffer = my_str_to_word_array(parsed_line[1], ':');
    new_tile->texture_nb = my_getnbr(buffer[0]);
    new_tile->blocked = my_getnbr(buffer[1]);
    set_rectangle(new_tile, tile_tex);
    return new_tile;
}

map_t *load_map(sfTexture **tile_tex, char *map_name,
                        game_data_t *game_data)
{
    char *path = concate("config/maps/", map_name);
    FILE *fd = fopen(concate(path, ".map"), "r");
    tile_t **tile_map = NULL;
    size_t size = 0;
    char *lineptr = NULL;
    map_t *map = malloc(sizeof(map_t));
    int i = 0;

    map->map_name = map_name;
    map->monsters = load_monsters(path, game_data->resources);
    map->events = load_events(path);
    get_map_info(map, fd);
    getline(&lineptr, &size, fd);
    tile_map = malloc(sizeof(tile_t *) * (my_getnbr(lineptr) + 20));
    while (getline(&lineptr, &size, fd) != -1)
        tile_map[i++] = parsed_tile_info(lineptr, tile_tex);
    tile_map[i] = NULL;
    map->tile_map = tile_map;
    fclose(fd);
    return map;
}
