/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** create_button
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/RectangleShape.h>
#include <stdlib.h>
#include <stdio.h>
#include "button.h"
#include "lib.h"

list_t *make_button(void)
{
    list_t *buttons = NULL;
    FILE *file = fopen("./config/button.conf", "r");
    char *buffer = NULL;
    size_t n = 0;
    int i = 0;

    if (file == NULL) {
        return NULL;
    }
    while (getline(&buffer, &n, file) != -1) {
        if (buffer[0] == '#')
            continue;
        if ((i = find_char(buffer, '\n')) != -1)
            buffer[i - 1] = '\0';
        buttons = push_button(create_button(buffer), buttons);
        free(buffer);
        buffer = NULL;
    }
    fclose(file);
    return buttons;
}

button_t *create_button(char *buffer)
{
    char **info = my_str_to_word_array(buffer, ':');
    button_t *button = malloc(sizeof(button_t));

    button->text = set_up_text(info);
    if (!my_strcmp("null", info[TEXTURE])) {
        button->button_size.x = my_getnbr(info[SIZE_X]);
        button->button_size.y = my_getnbr(info[SIZE_Y]);
        button->button_pos.x = my_getnbr(info[POS_X]);
        button->button_pos.y = my_getnbr(info[POS_Y]);
        button->rectangle = create_box(button, button->button_size);
        sfRectangleShape_setPosition(button->rectangle, button->button_pos);
    } else
        button->rectangle = NULL;
    button->scene = my_getnbr(info[SCENE]);
    button->new_scene = my_getnbr(info[NEW_SCENE]);
    return button;
}

sfText *set_up_text(char **info)
{
    sfText *text = NULL;
    sfFont *font = NULL;
    sfVector2f pos = {0, 0};
    sfColor color;

    if (my_strcmp("null", info[STRING]))
        return NULL;
    pos.x = my_getnbr(info[FONT_POS_X]);
    pos.y = my_getnbr(info[FONT_POS_Y]);
    text = sfText_create();
    font = sfFont_createFromFile(concate("./resources/font/", info[FONT]));
    sfText_setFont(text, font);
    sfText_setString(text, info[STRING]);
    sfText_setCharacterSize(text, my_getnbr(info[FONT_SIZE]));
    sfText_setPosition(text, pos);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 1.5);
    if (!my_strcmp("null", info[FONT_COLOR])) {
        color = create_color(info[FONT_COLOR]);
        sfText_setColor(text, color);
    }
    return text;
}

sfColor create_color(char *color)
{
    char **rgb = my_str_to_word_array(my_strdup(color), ',');
    int r = my_getnbr(rgb[0] + 1);
    int g = my_getnbr(rgb[1]);
    int b = 0;

    rgb[2][find_char(rgb[2], ')')] = '\0';
    b = my_getnbr(rgb[2]);
    return sfColor_fromRGB(r, g, b);
}
