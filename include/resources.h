/*
** EPITECH PROJECT, 2019
** resources
** File description:
** resources.h
*/

#ifndef RESOURCES_H_
#define RESOURCES_H_
#include <SFML/Graphics.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>

typedef struct monster_textures
{
    sfTexture *walk;
    sfTexture *hit;
    sfTexture *attack;
    sfTexture *death;
} monster_textures_t;

typedef struct charac_textures
{
    sfTexture *walk_down;
    sfTexture *walk_up;
    sfTexture *walk_right;
    sfTexture *walk_left;
    sfTexture *up_attack;
    sfTexture *down_attack;
    sfTexture *right_attack;
    sfTexture *left_attack;
    sfTexture *death;
    sfTexture *cast;
} charac_texts_t;

typedef struct resources
{
    sfTexture *item_texture;
    sfTexture **tile_tex;
    monster_textures_t *monster_textures;
    charac_texts_t *character_texts;
    sfSound **tab_sound;
    sfFont *fantasy_font;
    sfSound *walk_sound;
    sfSound *atk_sound;
    sfRectangleShape *menu_back;
    sfClock *walk_clock;
} resources_t;

resources_t *init_resources(void);
sfTexture **create_texture_tab(void);

#endif /* ifndef RESOURCES_H_ */
