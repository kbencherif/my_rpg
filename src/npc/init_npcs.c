/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** npcs initialisation file
*/

#include <sys/types.h>
#include <dirent.h>
#include "npc.h"
#include "inventory.h"
#include <stdlib.h>
#include "lib.h"
#include <stdio.h>

item_t *read_item(char *line, sfTexture *texture)
{
    char *item_path = NULL;
    int i = 0;
    item_t *item = NULL;

    for (; line[i] != '\n'; i++);
    line[i] = '\0';
    item_path = concate(line + 7, ".item");
    item = create_item_from_config(
            concate("./config/item/", item_path), texture, 1);
    return item;
}

void npc_from_config(npc_t *npc, FILE *file)
{
    size_t size = 0;
    char *line = NULL;
    int i = 0;

    getline(&line, &size, file);
    npc->interaction_box.height = my_getnbr(line);
    getline(&line, &size, file);
    npc->interaction_box.width = my_getnbr(line);
    getline(&line, &size, file);
    for (; line[i] != '\n'; i++);
    line[i] = '\0';
    npc->name = my_strdup(line + 8);
    getline(&line, &size, file);
    npc->pos.x = my_getnbr(line);
    getline(&line, &size, file);
    npc->pos.y = my_getnbr(line);
    getline(&line, &size, file);
    i = 0;
    for (; line[i] != '\n'; i++);
    line[i] = '\0';
    npc->map = my_strdup(line + 6);
}

npc_t *init_npc(char *dir, char *texture_path)
{
    sfTexture *texture = sfTexture_createFromFile(texture_path, NULL);
    char *conf_file = concate(dir, "/npc.conf");
    FILE *file = fopen(conf_file, "r");

    if (!file)
        return NULL;
    npc_t *npc = malloc(sizeof(npc_t));
    npc->interaction_box = (sfIntRect) {0, 0, 0, 0};
    npc->pos = (sfVector2f) {0, 0};
    npc->sprite = sfSprite_create();

    sfSprite_setTexture(npc->sprite, texture, sfFalse);
    npc_from_config(npc, file);
    fclose(file);
    return npc;
}

npc_t **init_npcs(char *npcs_dr)
{
    npc_t **npcs = malloc(sizeof(npc_t *) * (NPC_NB + 1));
    DIR *dir = opendir(npcs_dr);
    struct dirent *npc_dr;
    char *texture_path = NULL;
    char *npc_dr_path = NULL;
    char *dialogues_path = NULL;

    for (int i = 0; (npc_dr = readdir(dir));) {
        if (npc_dr->d_name[0] != '.' && npc_dr->d_type == DT_DIR) {
            texture_path = concate("resources/npc/", npc_dr->d_name);
            texture_path = concate(texture_path, ".png");
            dialogues_path = concate(npcs_dr, npc_dr->d_name);
            dialogues_path = concate(dialogues_path, "/dialogue/dialogue");
            npc_dr_path = concate(npcs_dr, npc_dr->d_name);
            npcs[i] = init_npc(npc_dr_path, texture_path);
            npcs[i]->dialogues = get_dialogues(dialogues_path);
            i++;
        }
    }
    npcs[NPC_NB] = NULL;
    return npcs;
}
