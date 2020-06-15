/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** object
*/

#ifndef __OBJECTS__
#define __OBJECTS__
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Window/Event.h>
#include <SFML/Audio.h>

typedef struct button {
    sfText *text;
    sfRectangleShape *rectangle;
    sfVector2f button_size;
    sfVector2f button_pos;
    int scene;
    int new_scene;
    sfTexture *normal_texture;
    sfTexture *hover_texture;
    sfTexture *click_texture;
} button_t;

typedef struct list {
    button_t *button;
    struct list *next;
} list_t;

typedef struct menus {
    list_t *buttons;
    int scene;
    sfRectangleShape *menu_back;
    sfSound *sound;
} menus_t;

void draw_on_screen(sfRenderWindow *win, button_t *cpy);
void is_on_it(button_t *button, sfRenderWindow *win, sfEvent event, int i);
list_t *push_button(button_t *button, list_t *list);
sfRectangleShape *create_box(button_t *button, sfVector2f size);
list_t *make_button(void);
int find_char(char *str, char c);
button_t *create_button(char *buffer);
sfText *set_up_text(char **info);
sfColor create_color(char *color);

enum {
    STRING,
    FONT,
    FONT_SIZE,
    FONT_POS_X,
    FONT_POS_Y,
    FONT_COLOR,
    SIZE_X,
    SIZE_Y,
    POS_X,
    POS_Y,
    TEXTURE,
    BUTTON_COLOR,
    SCENE,
    NEW_SCENE,
};

#endif
