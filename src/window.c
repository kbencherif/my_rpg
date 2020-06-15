/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** function useful for window handling
*/

#include <SFML/Window/Event.h>
#include <SFML/Config.h>
#include <SFML/Graphics/RenderWindow.h>

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "My RPG", sfDefaultStyle,
            NULL);
    sfRenderWindow_setMouseCursorVisible(window, sfTrue);
    sfRenderWindow_setVerticalSyncEnabled(window, sfFalse);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setVerticalSyncEnabled(window, sfTrue);
    return window;
}
