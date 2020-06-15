/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** monsters
*/

#ifndef MONSTER_H_
#define MONSTER_H_
#include <stdbool.h>
#include "anim.h"
#include "resources.h"
#include "character.h"
#include "particle_system.h"

typedef struct monster
{
    anim_t **anims;
    sfClock *hit_clock;
    sfClock *movement_clock;
    sfClock *fire_clock;
    sfClock *fire_dmg_clock;
    fire_particle_sys_t *fire;
    int actual_state;
    bool hitted;
    bool anim_flipped;
    bool on_fire;
    sfRectangleShape *health_bar;
    int health;
    int body_damages;
    float speed_factor;
    attack_t *attack;
    sfVector2f attack_offset;
    sfIntRect hitbox;
    sfIntRect walking_rect;
    sfVector2f pos;
    sfVector2f movement;
} monster_t;

enum {
    M_WALK,
    M_HIT,
    M_ATTACK,
    M_DEATH,
};

enum {
    SKELETON,
    EYE,
    MUSH,
    GOBLIN,
    BOSS,
};

char *concate(char *dest, char *src);
int my_strcmp(char *s1, char *s2);
sfIntRect create_box_from_file(char *path, sfVector2f box_pos);

monster_t *init_monster(resources_t *resources,
                        int monster_key, sfVector2f pos);
void actualize_monster_pos(monster_t *monster);
void apply_monster_damage(monster_t *monster, int attack_value);
void move_monster(monster_t *monster, sfVector2f offset);
void init_monster_health_bar(monster_t *monster);
void change_monster_state(monster_t *monster, int state);
void handle_death(monster_t *monster, character_t *character);
void handle_attacking(monster_t *monster, sfIntRect char_hitbox);
void apply_monster_damage(monster_t *monster, int attack_value);
void remove_invincibility(monster_t *monster);
void get_movement_vector(monster_t *monster, sfIntRect char_hitbox);
void handle_monster_flip(monster_t *monster);

#define NB_MONSTER_ANIM 4
#define MONSTER_ATTACK_FRAME 7

#endif /* ifndef MONSTER_H_ */
