/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** button_logic
*/

#ifndef __BUTTON_LOGIC__
#define __BUTTON_LOGIC__
#include "button.h"
#include "game_data.h"

int check_button(list_t *menus, int scene, sfRenderWindow *win);
void button_logic(int button, menus_t *menus, sfRenderWindow *win,
                            game_data_t **game_data);

#endif
