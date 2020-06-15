/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** scene_redirection
*/

#include <SFML/Graphics/RenderWindow.h>
#include "analyse_scene.h"
#include "game_data.h"
#include "display_settings.h"
#include "operator_abstract.h"

void other_scene_logic(sfRenderWindow *win, menus_t *menus,
                        game_data_t **game_data)
{
    sfEvent event;
    int i = 0;

    while (sfRenderWindow_pollEvent(win, &event)) {
        analyse_scene_event(event, menus, win , game_data);
        i++;
    }
    display_button(win, menus, event, i);
    if (menus->scene is SETTINGS)
        display_settings(*game_data, win);
    sfRenderWindow_display(win);
    sfRenderWindow_clear(win, sfTransparent);
}
