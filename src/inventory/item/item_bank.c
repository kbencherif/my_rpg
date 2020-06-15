/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** main file
*/

#include "inventory.h"
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "lib.h"
#include "game_data.h"

int count_obj(char *dr_name)
{
    DIR *dirp = opendir(dr_name);
    struct dirent *dir;
    int obj_amount = 0;

    while ((dir = readdir(dirp)) != NULL)
        if (dir->d_name[0] != '.')
            obj_amount++;
    closedir(dirp);
    return obj_amount;
}

char **get_config_files_name(char *dr_name)
{
    int obj_amount = count_obj(dr_name);
    char **config_files_name = malloc(sizeof(char *) * (obj_amount + 1));
    DIR *dr = opendir(dr_name);
    struct dirent *directory;
    int i = 0;

    for (; (directory = readdir(dr)) != NULL ;)
        if (directory->d_name[0] != '.') {
            config_files_name[i] = my_strdup(directory->d_name);
            config_files_name[i] = concate(dr_name,
                    config_files_name[i]);
            i++;
        }
    config_files_name[i] = NULL;
    return config_files_name;
}
