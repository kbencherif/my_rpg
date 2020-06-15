/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** analyse_scene
*/

#ifndef __ANALYSE_SCENE__
#define __ANALYSE_SCENE__

#include "button.h"
#include "game_data.h"
#include <SFML/Graphics/RenderWindow.h>

void analyse_scene_event(sfEvent event, menus_t *menus, sfRenderWindow *win,
                                game_data_t **game_data);

#endif
