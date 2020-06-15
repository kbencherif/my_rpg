/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init stat point ui file
*/

#include "stat_point.h"
#include <stdlib.h>

void set_ui_pos(stat_point_ui_t *ui, sfText *text)
{
    sfVector2f pos = sfRectangleShape_getPosition(ui->background);
    sfFloatRect text_size = {0, 0, 0, 0};

    sfText_setPosition(ui->text, (sfVector2f) {pos.x + 10, pos.y + 10});
    text_size = sfText_getGlobalBounds(text);
    pos = (sfVector2f) {text_size.left, text_size.top + text_size.height + 10};
    for (int i = 0; ui->icons[i]; i++) {
        sfSprite_setPosition(ui->icons[i], pos);
        pos.x += 64;
    }
}

void set_bg(sfRectangleShape *bg, sfSprite *inventory, sfText *text)
{
    sfFloatRect text_size = sfText_getGlobalBounds(text);
    sfVector2f size = {text_size.width + 20, 150};
    sfFloatRect rect = sfSprite_getGlobalBounds(inventory);
    sfVector2f pos = {rect.left + size.x / 2, rect.top - size.y - 10};

    sfRectangleShape_setSize(bg, size);
    sfRectangleShape_setFillColor(bg, sfBlack);
    sfRectangleShape_setOutlineColor(bg, sfWhite);
    sfRectangleShape_setOutlineThickness(bg, 2);
    sfRectangleShape_setPosition(bg, pos);
}

stat_point_ui_t *init_stat_point_ui(sfFont *font, sfSprite *inventory)
{
    sfTexture *texture = sfTexture_createFromFile(
            "./resources/stat_point/texture.png", NULL);
    sfIntRect rects[4] = {{122, 0, 62, 63}, {0, 0, 62, 63},
        {0, 61, 62, 63}, {62, 61, 62, 63}};
    stat_point_ui_t *ui = malloc(sizeof(stat_point_ui_t));
    ui->icons = malloc(sizeof(sfSprite *) * (LEN + 1));
    ui->background = sfRectangleShape_create();
    ui->text = sfText_create();

    sfText_setString(ui->text, "SKILL PTS : 1000");
    sfText_setFont(ui->text, font);
    sfText_setFillColor(ui->text, sfWhite);
    for (int i = 0; i < LEN; i++) {
        ui->icons[i] = sfSprite_create();
        sfSprite_setTexture(ui->icons[i], texture, sfFalse);
        sfSprite_setTextureRect(ui->icons[i], rects[i]);
    }
    ui->icons[LEN] = NULL;
    set_bg(ui->background, inventory, ui->text);
    set_ui_pos(ui, ui->text);
    return ui;
}
