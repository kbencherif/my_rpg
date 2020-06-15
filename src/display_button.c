/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** display_button
*/

#include <SFML/Audio.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include "button.h"
#include <stdbool.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include "window.h"
#include "game_data.h"

void display_button(sfRenderWindow *win, menus_t *menu, sfEvent event, int i)
{
    const sfView *ig_view = sfRenderWindow_getView(win);
    sfRenderWindow_setView(win, sfRenderWindow_getDefaultView(win));
    list_t *tmp = menu->buttons;

    sfRenderWindow_drawRectangleShape(win, menu->menu_back, NULL);
    while (tmp) {
        if (tmp->button->scene == menu->scene) {
            is_on_it(tmp->button, win, event, i);
            draw_on_screen(win, tmp->button);
        }
        tmp = tmp->next;
    }
    sfRenderWindow_setView(win, ig_view);
}

void draw_on_screen(sfRenderWindow *win, button_t *cpy)
{
    if (cpy->rectangle)
        sfRenderWindow_drawRectangleShape(win, cpy->rectangle, NULL);
    if (cpy->text)
        sfRenderWindow_drawText(win, cpy->text, NULL);
}

void is_on_it(button_t *button, sfRenderWindow *win, sfEvent event, int i)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);
    sfFloatRect rect;

    if (!button->rectangle || !button->text)
        return;
    rect = sfRectangleShape_getGlobalBounds(button->rectangle);
    if (sfFloatRect_contains(&rect, mouse_pos.x, mouse_pos.y)) {
        if (i && event.type == sfEvtMouseButtonPressed
                && event.mouseButton.button == sfMouseLeft)
        sfRectangleShape_setTexture
            (button->rectangle, button->click_texture, true);
        else
            sfRectangleShape_setTexture
                (button->rectangle, button->hover_texture, true);
    } else {
        sfRectangleShape_setTexture
            (button->rectangle, button->normal_texture, true);
    }
    return;
}
