/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** main file
*/

#include "scene_redirection.h"
#include "iterators.h"
#include "window.h"
#include "operator_abstract.h"
#include "game_loop.h"
#include "menus.h"
#include "intro.h"

define_iter(event_t);
define_iter(quest_t);

void new_game(game_data_t **game_data, menus_t *menus, sfRenderWindow *win,
                char *class_name)
{
    sfVector2f char_pos = {(1550), (1080 / 2) - 64};

    *game_data = init_game_data(win, class_name,
            "pre-spawn", char_pos);
    push_front((*game_data)->quests,
            init_sword_quest((*game_data)->resources->item_texture));
    push_front((*game_data)->quests,
            init_get_fire_ring((*game_data)->resources->item_texture));
    menus->scene = GAME;
}

int main(UNUSED int argc, UNUSED char *argv[])
{
    sfRenderWindow *win = create_window(1920, 1080);
    game_data_t *game_data = NULL;
    menus_t *menus = malloc(sizeof(menus_t));
    sfMusic *menu_music = sfMusic_createFromFile
        ("./resources/song/menu_music.mp3");
    sfMusic *game_music = sfMusic_createFromFile
        ("./resources/song/game_music.ogg");
    intro_t *intro = init_intro();

    *menus = (menus_t) {make_button(), MAIN_MENU, create_menu(), setup_sound()};
    while (sfRenderWindow_isOpen(win)) {
        if (menus->scene is GAME) {
            set_music_and_sounds(game_data, menu_music, game_music, menus);
            game_loop(win, game_data, &menus->scene);
        } else if (menus->scene is INTRO || menus->scene is END)
            game_intro(win, game_data, menus, intro);
        else {
            set_music_and_sounds(game_data, game_music, menu_music, menus);
            other_scene_logic(win, menus, &game_data);
        }
    }
    return 0;
}
