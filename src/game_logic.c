/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** game_logic file
*/

#include <math.h>
#include "monsters.h"
#include "game_data.h"
#include "character.h"
#include "iterators_prototype.h"
#include "operator_abstract.h"

define_prototype(monster_t);
define_prototype(event_t);

void update_monster(Iter(monster_t) *monsters, monster_t *monster,
                    character_t *character, game_data_t *game_data);
void update_character(character_t *character, Iter(monster_t) *monsters,
                        game_data_t *game_data);
map_t *load_map(sfTexture **tile_tex, char *map_name, game_data_t *game_data);
void dungeon_logic(game_data_t *game_data, event_t *next);
bool is_locked_event(char *name);
void manage_lock_map(game_data_t *game_data, event_t *next);

void view_logic(game_data_t *game_data, sfRenderWindow *win,
                sfVector2f charac_pos)
{
    sfVector2f center = (sfVector2f)
        {charac_pos.x + game_data->character->hitbox.width / 2,
        charac_pos.y + game_data->character->hitbox.height / 2};
    sfVector2f charac_center = center;

    if (game_data->map->block_view) {
        if (charac_center.y <= 1080 / 2)
            center.y = 1080 / 2;
        else if (charac_center.y + 1080 / 2 >=
            game_data->map->tile_map_size.y * 32)
            center.y = (game_data->map->tile_map_size.y * 32) - (1080 / 2);
        if (charac_center.x <= 1920 / 2)
            center.x = 1920 / 2;
        else if (charac_center.x + 1920 / 2 >=
            game_data->map->tile_map_size.x * 32)
            center.x = game_data->map->tile_map_size.x * 32 - 1920 / 2;
    }
    sfView_setCenter(game_data->view, center);
    sfRenderWindow_setView(win, game_data->view);
}

void set_charac_position(character_t *character, sfVector2f pos)
{
    sfVector2f vector = {pos.x - character->pos.x,
                        pos.y - character->pos.y};

    character->pos = pos;
    for (int i = 0; i < NB_ANIMS; i++)
        sfSprite_move(character->anims[i]->sprite, vector);
    character->hitbox.left = pos.x;
    character->hitbox.top = pos.y;
    character->walking_rect = character->hitbox;
    character->walking_rect.top += character->walking_rect.height;
    character->walking_rect.height = 3;
    character->walking_rect.width -= 2;
    for (int i = 0; i < 4; i++) {
        character->attack_boxes[i].left += vector.x;
        character->attack_boxes[i].top += vector.y;
    }
}

void event_logic(game_data_t *game_data)
{
    event_t *next = NULL;

    while ((next = next(game_data->map->events))) {
        if (not is_locked_event(next->new_map_name) and
            sfIntRect_intersects(&next->event_rect, &game_data->character->
            walking_rect, NULL)) {
            game_data->map = load_map(game_data->resources->tile_tex,
                next->new_map_name, game_data);
            set_charac_position(game_data->character, next->new_char_pos);
            game_data->character->checkpoint_pos = next->new_char_pos;
        }
        else
            manage_lock_map(game_data, next);
    }
}

void quest_logic(game_data_t *game_data)
{
    quest_t *quest = search_for_quest(game_data->quests,
                    "kill_monsters_in_plain");

    if (quest and my_strcmp(game_data->map->map_name, "next_to_spawn")
        and not len(game_data->map->monsters) and
        quest->state is NOT_COMPLETED)
        quest->state = COMPLETED;
}

void game_logic(game_data_t *game_data, sfRenderWindow *win)
{
    monster_t *next = NULL;
    character_t *character = game_data->character;
    attack_t attack = {.damages = character->stats->attack_dmg,
        .rect = {0, 0, 0, 0}};

    event_logic(game_data);
    quest_logic(game_data);
    view_logic(game_data, win, character->pos);
    update_character(character, game_data->map->monsters, game_data);
    if (character->attacking)
        attack.rect = character->attack_boxes[character->actual_state - 4];
    reset(game_data->map->monsters);
    while ((next = next(game_data->map->monsters))) {
        update_monster(game_data->map->monsters, next, character, game_data);
        collisions_logic(character, next, &attack, game_data->resources);
    }
    sfView_setCenter(game_data->view, character->pos);
}
