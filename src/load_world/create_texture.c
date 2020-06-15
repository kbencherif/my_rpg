/*
** EPITECH PROJECT, 2020
** create_texture
** File description:
** .c
*/

#include <SFML/Graphics.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "lib.h"

char *first_name(char *buff, char *lineptr)
{
    lineptr[(my_strlen(lineptr) - 1)] = '\0';
    buff = my_strdup(lineptr);
    return (buff);
}

char *add_name(char *buff, char *lineptr)
{
    buff = concate(buff, " ");
    lineptr[(my_strlen(lineptr) - 1)] = '\0';
    buff = concate(buff, lineptr);
    return (buff);
}

sfTexture **fill_texture_tab(char **tab_of_name, int counter)
{
    sfTexture **tab_of_texture = malloc(sizeof(sfTexture *) * (counter + 1));
    for (int i = 0; i != counter; i++)
        tab_of_texture[i] = sfTexture_createFromFile(
            tab_of_name[i], NULL);
    tab_of_texture[counter] = NULL;
    return (tab_of_texture);
}

sfTexture **create_texture_tab(void)
{
    FILE *fd = fopen("./resources/tiles/texture.txt", "r");
    char *lineptr = NULL;
    char *buff = NULL;
    char **tab_of_name = NULL;
    size_t size = 0;
    int counter = 1;
    int return_value = 0;

    getline(&lineptr, &size, fd);
    buff = first_name(buff, lineptr);
    while (return_value != -1) {
        return_value = getline(&lineptr, &size, fd);
        if (return_value != -1 && lineptr[0] != '.') {
            counter += 1;
            buff = add_name(buff, lineptr);
        }
    }
    tab_of_name = my_str_to_word_array(buff, ' ');
    fclose(fd);
    return (fill_texture_tab(tab_of_name, counter));
}
