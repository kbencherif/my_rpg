/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** menus
*/

#include <SFML/Audio.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/Texture.h>

sfRectangleShape *create_menu(void)
{
    sfVector2f pos = {0, 0};
    sfVector2f size = {1920, 1080};
    sfTexture *text = sfTexture_createFromFile("resources/menu/menu.jpg", NULL);
    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setTexture(rect , text, sfTrue);
    return (rect);
}

sfSound *setup_sound(void)
{
    sfSound *sound = NULL;
    sfSoundBuffer *soundbuf = NULL;
    sound = sfSound_create();
    soundbuf = sfSoundBuffer_createFromFile("resources/song/zipclick.flac");
    sfSound_setBuffer(sound, soundbuf);
    return sound;
}
