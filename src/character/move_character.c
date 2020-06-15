/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** move character
*/

#include <SFML/Audio.h>
#include <stdbool.h>
#include "anim.h"
#include "character.h"
#include "operator_abstract.h"
#include "tile.h"
#include "map.h"

bool is_movable(character_t *character, map_t *map,
                sfVector2f offset)
{
    sfFloatRect new_feet_pos = (sfFloatRect)
        {character->walking_rect.left, character->walking_rect.top,
        character->walking_rect.width, character->walking_rect.height};
    sfFloatRect tile_bounds;

    new_feet_pos.left += offset.x * 2;
    new_feet_pos.top += offset.y * 2;
    if (new_feet_pos.left + character->hitbox.width >=
        map->tile_map_size.x * 32 or new_feet_pos.top >=
        map->tile_map_size.y * 32 or new_feet_pos.left <= 0
        or new_feet_pos.top <= 32)
        return false;
    for (int i = 0; map->tile_map[i]; i++) {
        tile_bounds = sfRectangleShape_getGlobalBounds(map->tile_map[i]->rect);
        if (map->tile_map[i]->blocked and
            sfFloatRect_intersects(&tile_bounds, &new_feet_pos, NULL))
            return false;
    }
    return true;
}

void move_player(character_t *character, sfVector2f offset)
{
    if (not character or character->actual_state is P_DEATH
        or character->casting)
        return;
    for (int i = 0; i < NB_ANIMS; i++)
        sfSprite_move(character->anims[i]->sprite, offset);
    character->hitbox.left = character->pos.x + offset.x;
    character->hitbox.top = character->pos.y + offset.y;
    character->walking_rect = character->hitbox;
    character->walking_rect.top += character->walking_rect.height;
    character->walking_rect.height = 3;
    character->walking_rect.width -= 3;
    character->walking_rect.left += 3;
    for (int i = 0; i < 4; i++) {
        character->attack_boxes[i].left += offset.x;
        character->attack_boxes[i].top += offset.y;
    }
}

void check_move(resources_t *res, character_t *character, map_t *map)
{
    int speed = character->stats->movement_speed;
    sfVector2f down = {0, speed};
    sfVector2f up = {0, -speed};
    sfVector2f left = {-speed, 0};
    sfVector2f right = {speed, 0};

    if ((character->actual_state is DOWN and character->to_animate and
        is_movable(character, map, down)) or
        (character->actual_state is UP and character->to_animate and
        is_movable(character, map, up)) or
        (character->actual_state is LEFT and character->to_animate and
        is_movable(character, map, left)) or
        (character->actual_state is RIGHT and character->to_animate and
            is_movable(character, map, right))) {
        if (sfClock_getElapsedTime(res->walk_clock).microseconds > 700000) {
            sfSound_play(res->tab_sound[0]);
            sfClock_restart(res->walk_clock);
        }
    }
}

void handle_deplacement(character_t *character, map_t *map, resources_t *res)
{
    int speed = character->stats->movement_speed;
    sfVector2f down = {0, speed};
    sfVector2f up = {0, -speed};
    sfVector2f left = {-speed, 0};
    sfVector2f right = {speed, 0};

    check_move(res, character, map);
    if (character->actual_state is DOWN
        and character->to_animate and is_movable(character, map, down))
        move_player(character, down);
    if (character->actual_state is UP
        and character->to_animate and is_movable(character, map, up))
        move_player(character, up);
    if (character->actual_state is LEFT
        and character->to_animate and is_movable(character, map, left))
        move_player(character, left);
    if (character->actual_state is RIGHT
        and character->to_animate and is_movable(character, map, right))
        move_player(character, right);
}

bool character_movement_input(character_t *character)
{
    bool direction_pushed = false;

    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        character->actual_state = UP;
        direction_pushed = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        character->actual_state = DOWN;
        direction_pushed = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        character->actual_state = LEFT;
        direction_pushed = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        character->actual_state = RIGHT;
        direction_pushed = true;
    }
    return direction_pushed;
}
