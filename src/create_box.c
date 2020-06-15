/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** create_box
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/RectangleShape.h>
#include "button.h"
#include "lib.h"

sfRectangleShape *create_box(button_t *button, sfVector2f size)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    button->normal_texture = sfTexture_createFromFile
        ("./resources/textures/button_normal.png", NULL);
    button->hover_texture = sfTexture_createFromFile
        ("./resources/textures/button_hover.png", NULL);
    button->click_texture = sfTexture_createFromFile
        ("./resources/textures/button_click.png", NULL);
    sfRectangleShape_setSize(rect, size);
    return rect;
}
