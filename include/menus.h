/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** menus
*/

#ifndef __MENUS_H__
#define __MENUS_H__
#include <SFML/Audio.h>
#include <SFML/Graphics/RectangleShape.h>
#include "game_data.h"

sfRectangleShape *create_menu(void);
sfSound *setup_sound(void);
void set_music_and_sounds(game_data_t *game_data, sfMusic *to_stop,
        sfMusic *to_play, menus_t *menus);

#endif
