/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** analyse_scene
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>
#include "display_settings.h"
#include "button.h"
#include "game_data.h"
#include "operator_abstract.h"
#include "button_logic.h"

void analyse_scene_event(sfEvent event, menus_t *menus, sfRenderWindow *win,
        game_data_t **game_data)
{
    int button = -1;
    int i = 1;

    if (event.type is sfEvtClosed)
        sfRenderWindow_close(win);
    if (event.type is sfEvtMouseButtonPressed and
        event.mouseButton.button is sfMouseLeft) {
        display_button(win, menus, event, i);
        if (menus->scene is SETTINGS)
            display_settings(*game_data, win);
        sfRenderWindow_display(win);
        sfRenderWindow_clear(win, sfTransparent);
        sfSleep(sfSeconds(0.07));
        button = check_button(menus->buttons, menus->scene, win);
    }
    if (button isnt -1) {
        button_logic(button, menus, win, game_data);
        if (sfSound_getStatus(menus->sound) != sfPlaying)
            sfSound_play(menus->sound);
    }
}
