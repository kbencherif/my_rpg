/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** set_music
*/

#include "game_data.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Audio.h>

void set_music_and_sounds(game_data_t *game_data, sfMusic *to_stop,
        sfMusic *to_play, menus_t *menus)
{
    if (game_data) {
        sfSound_setVolume(menus->sound, game_data->sounds_volume);
        sfMusic_setVolume(to_play, game_data->music_volume);
    } else {
        sfMusic_setVolume(to_play, 50);
        sfSound_setVolume(menus->sound, 50);
    }
    if (sfMusic_getStatus(to_play) != sfPlaying) {
        sfMusic_stop(to_stop);
        sfMusic_play(to_play);
        sfMusic_setLoop(to_play, true);
    }
}
