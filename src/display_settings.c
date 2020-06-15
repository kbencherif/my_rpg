/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** display_settings
*/

#include "game_data.h"
#include "operator_abstract.h"
#include "button.h"

void display_settings(game_data_t *game_data, sfRenderWindow *win)
{
    char *sounds = my_itoa(game_data->sounds_volume);
    char *music = my_itoa(game_data->music_volume);
    sfFont *font = sfFont_createFromFile("./resources/font/Windlass.ttf");
    sfText *sound_on_screen = sfText_create();
    sfText *music_on_screen = sfText_create();

    sfText_setString(sound_on_screen, sounds);
    sfText_setString(music_on_screen, music);
    sfText_setFont(sound_on_screen, font);
    sfText_setFont(music_on_screen, font);
    sfText_setCharacterSize(sound_on_screen, 40);
    sfText_setCharacterSize(music_on_screen, 40);
    sfText_setColor(sound_on_screen, sfBlack);
    sfText_setColor(music_on_screen, sfBlack);
    sfText_setPosition(music_on_screen, (sfVector2f) {675, 260});
    sfText_setPosition(sound_on_screen, (sfVector2f) {675, 460});
    sfRenderWindow_drawText(win, sound_on_screen, NULL);
    sfRenderWindow_drawText(win, music_on_screen, NULL);
    sfFont_destroy(font);
    sfText_destroy(sound_on_screen);
    sfText_destroy(music_on_screen);
}
