/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** create_anms_from_file
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "operator_abstract.h"
#include "anim.h"

anim_t *create_anim_file(const char *path, sfIntRect rect,
                        float ms_per_frame, int nb_frames)
{
    anim_t *anim = malloc(sizeof(anim_t));

    anim->ms_per_frame = ms_per_frame;
    anim->rect = rect;
    anim->nb_frames = nb_frames;
    anim->actual_frame = 1;
    anim->texture = sfTexture_createFromFile(path, NULL);
    anim->sprite = sfSprite_create();
    anim->anim_clock = sfClock_create();
    sfSprite_setTexture(anim->sprite, anim->texture, sfFalse);
    sfSprite_setTextureRect(anim->sprite, rect);
    return anim;
}

void read_anim_config_file(anim_t *anim, char *path)
{
    FILE *file = fopen(path, "r");
    size_t len = 0;
    char *line = NULL;

    getline(&line, &len, file);
    anim->ms_per_frame = my_getnbr(line);
    getline(&line, &len, file);
    anim->rect.height = my_getnbr(line);
    getline(&line, &len, file);
    anim->rect.width = my_getnbr(line);
    getline(&line, &len, file);
    anim->rect.left = my_getnbr(line);
    getline(&line, &len, file);
    anim->rect.top = my_getnbr(line);
    getline(&line, &len, file);
    anim->nb_frames = my_getnbr(line);
    getline(&line, &len, file);
    anim->content_offset.x = my_getnbr(line);
    getline(&line, &len, file);
    anim->content_offset.y = my_getnbr(line);
    fclose(file);
}

anim_t *create_anim_config(sfTexture *texture, char *config_path)
{
    anim_t *anim = malloc(sizeof(anim_t));

    read_anim_config_file(anim, config_path);
    anim->actual_frame = 0;
    anim->texture = texture;
    anim->sprite = sfSprite_create();
    anim->anim_clock = sfClock_create();
    sfSprite_setTexture(anim->sprite, anim->texture, sfFalse);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    return anim;
}
