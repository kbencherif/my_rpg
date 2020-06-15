/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** load_events
*/

#include <stdio.h>
#include "monsters.h"
#include "lib.h"
#include "game_data.h"
#include "iterators_prototype.h"

define_prototype(event_t);

void get_event(char *lineptr, size_t len, FILE *file, Iter(event_t) *events)
{
    event_t *event = malloc(sizeof(event_t));
    char **buffer = NULL;

    lineptr[my_strlen(lineptr) - 1] = 0;
    event->new_map_name = my_strdup(lineptr);
    getline(&lineptr, &len, file);
    buffer = my_str_to_word_array(lineptr, ' ');
    event->event_rect.left = my_getnbr(buffer[0]);
    event->event_rect.top = my_getnbr(buffer[1]);
    event->event_rect.width = my_getnbr(buffer[2]);
    event->event_rect.height = my_getnbr(buffer[3]);
    getline(&lineptr, &len, file);
    event->new_char_pos = get_pos(lineptr);
    push_front(events, event);
}

Iter(event_t) *load_events(char *path)
{
    Iter(event_t) *events = new_iter(event_t);
    FILE *file = fopen(concate(path, ".events"), "r");
    char *lineptr = NULL;
    size_t len = 0;

    while (getline(&lineptr, &len, file) != -1)
        get_event(lineptr, len, file, events);
    fclose(file);
    return events;
}
