/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** dialogues initialisation file
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

char **malloc_fromfile(char *path)
{
    char **arr = NULL;
    char *line = NULL;
    size_t read = 0;
    FILE *file = fopen(path, "r");
    int size = 0;

    for (; getline(&line, &read, file) != -1; size++);
    arr = malloc(sizeof(char *) * (size + 1));
    fclose(file);
    return arr;
}

void remplace_percent(char *line)
{
    for (int i = 0; line[i]; i++)
        if (line[i] == '%')
            line[i] = '\n';
}

char **get_dialogues(char *dialogues_path)
{
    FILE *file = fopen(dialogues_path, "r");
    char **dialogues = malloc_fromfile(dialogues_path);
    char *line = NULL;
    size_t size = 0;
    int i = 0;

    if (!file)
        return NULL;
    for (; getline(&line, &size, file) != -1; i++) {
        dialogues[i] = my_strdup(line);
        remplace_percent(dialogues[i]);
    }
    dialogues[i] = NULL;
    fclose(file);
    return dialogues;
}
