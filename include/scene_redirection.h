/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** scene_redirection
*/

#ifndef __SCENE_REDIRECTION__
#define __SCENE_REDIRECTION__

#include "game_data.h"
#include "button.h"
#include <SFML/Graphics/RenderWindow.h>

void other_scene_logic(sfRenderWindow *win, menus_t *menus,
                        game_data_t **game_data);
void other_button(int button, menus_t *menus, sfRenderWindow *win,
                            game_data_t **game_data);

void other_button2(int button, menus_t *menus, sfRenderWindow *win,
                            game_data_t **game_data);

void other_button3(int button, menus_t *menus, sfRenderWindow *win,
                            game_data_t **game_data);

#endif
