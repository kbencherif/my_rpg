/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** button_logic
*/

#include "button.h"
#include "game_data.h"
#include "scene_logic.h"
#include "operator_abstract.h"
#include "scene_redirection.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/RectangleShape.h>

int check_button(list_t *menus, int scene, sfRenderWindow *win)
{
    list_t *tmp = menus;
    int button = 0;
    sfFloatRect rect;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);

    while (tmp) {
        if (tmp->button->scene == scene && tmp->button->rectangle) {
            rect = sfRectangleShape_getGlobalBounds(tmp->button->rectangle);
            if ((sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y)))
                return button;
        }
        button++;
        tmp = tmp->next;
    }
    return -1;
}

void button_logic(int button, menus_t *menus, sfRenderWindow *win,
                            game_data_t **game_data)
{
    switch(button) {
        case 1:
            menus->scene = NEW_GAME_MENU;
            break;
        case 2:
            *game_data = load_game(win);
            if (not *game_data)
                return;
            menus->scene = GAME;
            break;
        case 3:
            menus->scene = SETTINGS;
            break;
        case 4: case 9:
            sfRenderWindow_close(win);
            break;
        default:
            other_button(button, menus, win, game_data);
            break;
    }
}

void other_button(int button, menus_t *menus, sfRenderWindow *win,
                            game_data_t **game_data)
{
    switch(button) {
        case 5:
            menus->scene = HELP;
            break;
        case 7:
            menus->scene = GAME;
            break;
        case 8:
            save_game(*game_data);
            menus->scene = MAIN_MENU;
            break;
        case 11:
            continue_playing_after_dying(*game_data);
            menus->scene = GAME;
            break;
        default:
            other_button2(button, menus, win, game_data);
            break;
    }
}

void other_button2(int button, menus_t *menus, sfRenderWindow *win,
                            game_data_t **game_data)
{
    switch(button) {
        case 12:
            continue_playing_after_dying((*game_data));
            save_game(*game_data);
            sfRenderWindow_close(win);
            break;
        case 14:
            menus->scene = MAIN_MENU;
            break;
        case 26:
            if ((*game_data)->music_volume > 0)
                (*game_data)->music_volume--;
            break;
        case 27:
            if ((*game_data)->music_volume < 100)
                (*game_data)->music_volume++;
            break;
        default:
            other_button3(button, menus, win, game_data);
            break;
    }
}

void other_button3(int button, menus_t *menus, sfRenderWindow *win,
                            game_data_t **game_data)
{
    switch(button) {
        case 28:
            if ((*game_data)->sounds_volume > 0)
                (*game_data)->sounds_volume--;
            break;
        case 29:
            if ((*game_data)->sounds_volume < 100)
                (*game_data)->sounds_volume++;
            break;
        case 30:
            menus->scene = PAUSE;
            break;
        case 31:
            new_game(game_data, menus, win, "skeleton");
            menus->scene = INTRO;
            break;
        case 32:
            new_game(game_data, menus, win, "orc");
            menus->scene = INTRO;
            break;
    }
}
