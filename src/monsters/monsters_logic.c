/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** monter logic file
*/

#include <math.h>
#include "iterators_prototype.h"
#include "game_data.h"
#include "monsters.h"
#include "tile.h"
#include "operator_abstract.h"

define_prototype(monster_t);

void delete_dead_monster(Iter(monster_t) *monsters, monster_t *monster);

void apply_fire_to_monsters(Iter(monster_t) *monsters)
{
    monster_t *next = NULL;
    sfVector2f fire_pos;
    sfVector2f pos;

    while ((next = next(monsters))) {
        pos = next->pos;
        fire_pos = (sfVector2f) {pos.x + next->hitbox.width / 2,
                                pos.y + next->hitbox.height / 2};
        next->on_fire = true;
        next->fire = init_fire_particle_sys(fire_pos);
        sfClock_restart(next->fire_clock);
        sfClock_restart(next->fire_dmg_clock);
        for (int i = 0; i < 4; i++)
            sfSprite_setColor(next->anims[i]->sprite, sfRed);
    }
}

void change_monster_state(monster_t *monster, int state)
{
    reset_anim(monster->anims[monster->actual_state]);
    monster->actual_state = state;
}

void handle_fire(monster_t *monster, int spell_power)
{
    if (monster->on_fire and sfClock_getElapsedTime(monster->fire_dmg_clock)
        .microseconds > 350000 - (10000 * spell_power)) {
        monster->health -= 1;
        sfClock_restart(monster->fire_dmg_clock);
    }
    if (monster->on_fire and sfClock_getElapsedTime(
        monster->fire->update_clock).microseconds > 20000)
        update_fire_particle_sys(monster->fire);
    if (monster->on_fire and sfClock_getElapsedTime(
        monster->fire_clock).microseconds > 4000000) {
        monster->on_fire = false;
        for (int i = 0; i < 4; i++)
            sfSprite_setColor(monster->anims[i]->sprite, sfWhite);
    }
}

bool is_monster_movable(monster_t *monster, tile_t **tile_map,
                sfVector2f offset)
{
    sfFloatRect new_feet_pos = (sfFloatRect)
        {monster->walking_rect.left, monster->walking_rect.top,
        monster->walking_rect.width, monster->walking_rect.height};
    sfFloatRect tile_bounds;

    new_feet_pos.left += offset.x * 2;
    new_feet_pos.top += offset.y * 2;
    for (int i = 0; tile_map[i]; i++) {
        tile_bounds = sfRectangleShape_getGlobalBounds(tile_map[i]->rect);
        if (tile_map[i]->blocked
            and sfFloatRect_intersects(&tile_bounds, &new_feet_pos, NULL))
            return false;
    }
    return true;
}

void update_monster(Iter(monster_t) *monsters, monster_t *monster,
                    character_t *character, game_data_t *game_data)
{
    get_movement_vector(monster, character->hitbox);
    if (sfClock_getElapsedTime(monster->movement_clock)
        .microseconds > 10000 and
        is_monster_movable(monster, game_data->map->tile_map,
        monster->movement)) {
        move_monster(monster, monster->movement);
        sfClock_restart(monster->movement_clock);
    }
    actualize_monster_pos(monster);
    handle_attacking(monster, character->hitbox);
    handle_monster_flip(monster);
    remove_invincibility(monster);
    handle_death(monster, character);
    handle_fire(monster, character->stats->spell_dmg);
    delete_dead_monster(monsters, monster);
    sfRectangleShape_setSize(monster->health_bar,
        (sfVector2f) {monster->health, 5});
}
