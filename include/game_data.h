/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** game data include
*/

#ifndef GAME_DATA_
#define GAME_DATA_
#include "anim.h"
#include "character.h"
#include "particle_system.h"
#include "monsters.h"
#include "resources.h"
#include "dialogue.h"
#include "npc.h"
#include "map.h"
#include "stat_point.h"
#include "quests.h"
#include "button.h"
#include "info.h"
#include "intro.h"

typedef struct iter_monster_t Iter_monster_t;
typedef struct iter_tile_t Iter_tile_t;
typedef struct iter_quest_t Iter_quest_t;

typedef struct game_data
{
    rain_particle_sys_t *rain_particle_system;
    npc_t **npcs;
    character_t *character;
    resources_t *resources;
    sfView *view;
    inventory_t *inventory;
    stat_point_ui_t *stat_point_ui;
    dialogue_box_t *dialogue_box;
    info_t *info_box;
    Iter_quest_t *quests;
    map_t *map;
    int sounds_volume;
    int music_volume;
    int intro_transparency;
    int intro_line;
    bool intro_first;
} game_data_t;

void display_button(sfRenderWindow *win, menus_t *menu, sfEvent event, int i);
void game_logic(game_data_t *game_data, sfRenderWindow *win);
void anim_game(game_data_t *game_data);
void draw_game(game_data_t *game_data, sfRenderWindow *win);
void collisions_logic(character_t *character, monster_t *monster,
        attack_t *attack, resources_t *res);
void draw_inventory(sfRenderWindow *win, inventory_t *inventory);
void update_inventory_pos(game_data_t *game_data, sfRenderWindow *win);
void draw_dialogue_box(sfRenderWindow *win, game_data_t *game_data);
int find_path(game_data_t *game_data, sfVector2f monster_pos,
            sfVector2f character_pos);
void search_npc(game_data_t *game_data);
void inventory_event(game_data_t *game_data, sfEvent event,
        sfRenderWindow *win);
void updata_character_ui(character_t *character);
void draw_stat_point_ui(sfRenderWindow *win, game_data_t *game_data);
game_data_t *init_game_data(sfRenderWindow *win, char *class_name,
                            char *map_name, sfVector2f char_pos);
void save_game(game_data_t *game_data);
game_data_t *load_game(sfRenderWindow *win);
void check_quests(game_data_t *game_data, char *quest_name, npc_t *npc);
void character_event(sfEvent event, character_t *character,
                    game_data_t *game_data);
quest_t *init_quest(game_data_t *game_data, char *name);
void new_game(game_data_t **game_data, menus_t *menus, sfRenderWindow *win,
                char *class_name);
void game_intro(sfRenderWindow *win, game_data_t *game_data, menus_t *menus,
        intro_t *intro);
void analyse_intro_events(sfEvent event, sfRenderWindow *win, menus_t *menus,
        game_data_t *game_data);
void draw_intro(sfRenderWindow *win, game_data_t *game_data, intro_t *intro);

enum {
    MAIN_MENU,
    NEW_GAME_MENU,
    GAME,
    PAUSE,
    DEAD,
    HELP,
    SETTINGS,
    INTRO,
    END
};

#endif /* ifndef GAME_DATA_ */
