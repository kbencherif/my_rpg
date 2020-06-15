/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** anim lib include
*/

#ifndef ANIM_H_
#define ANIM_H_
#include <SFML/Graphics.h>

typedef struct anim {
    sfTexture *texture;
    sfSprite *sprite;
    sfClock *anim_clock;
    sfIntRect rect;
    int nb_frames;
    int actual_frame;
    float ms_per_frame;
    sfVector2f content_offset;
} anim_t;

anim_t *create_anim_file(const char *path, sfIntRect rect,
                        float ms_per_frame, int nb_frames);
anim_t *create_anim_config(sfTexture *texture, char *config_path);
void reset_anim(anim_t *anim);

void animate(anim_t *anim);
int my_getnbr(char const *str);

#endif /* ifndef ANIM_H_ */
