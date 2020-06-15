/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** game_loop
*/

#include "game_data.h"
#include "operator_abstract.h"
#include "inventory.h"
#include "character.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include "scene_logic.h"
#include "iterators_prototype.h"

define_prototype(monster_t);

void analyse_game_events(sfEvent event, sfRenderWindow *win,
                        character_t *character, game_data_t *game_data)
{
    character_event(event, character, game_data);
    if (event.type is sfEvtClosed) {
        save_game(game_data);
        sfRenderWindow_close(win);
    }
    inventory_event(game_data, event, win);
    if (event.type is sfEvtKeyPressed and event.key.code is sfKeyReturn) {
        if (game_data->dialogue_box->open is true)
            game_data->dialogue_box->open = false;
        else
            search_npc(game_data);
    }
}

void set_volume(sfSound **tab_sound, int sounds_volume)
{
    for (int i = 0; i != 5; i++)
        sfSound_setVolume(tab_sound[i], sounds_volume);
}

bool check_end(game_data_t *game_data)
{
    if (my_strcmp(game_data->map->map_name, "donjon_boss_room3") and
                is_empty(game_data->map->monsters))
        return true;
    return false;
}

void game_loop(sfRenderWindow *win, game_data_t *game_data, int *scene)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win, &event)) {
        analyse_game_events(event, win, game_data->character, game_data);
        if (event.type is sfEvtKeyPressed and event.key.code is sfKeyEscape)
            *scene = PAUSE;
    }
    sfRenderWindow_clear(win, sfBlack);
    anim_game(game_data);
    game_logic(game_data, win);
    set_volume(game_data->resources->tab_sound, game_data->sounds_volume);
    draw_game(game_data, win);
    scene_logic(game_data, scene);
    if (check_end(game_data))
        *scene = END;
    sfRenderWindow_display(win);
}
