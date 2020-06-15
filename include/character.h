/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** anim lib include
*/

#ifndef CHARACTER_H_
#define CHARACTER_H_
#include <SFML/Graphics.h>
#include <stdbool.h>
#include "anim.h"
#include "tile.h"
#include "resources.h"
#include "inventory.h"
#include "particle_system.h"

typedef struct stat_bar {
    int stat;
    char *max_stat;
    sfText *bar_text;
    sfRectangleShape *stat_bar;
    sfRectangleShape *borders;
} stat_bar_t;

typedef struct statistics {
    int attack_dmg;
    int spell_dmg;
    int max_health_points;
    int max_mana_points;
    int movement_speed;
} stat_t;

typedef struct character {
    char *class_name;
    stat_bar_t *health_bar;
    stat_bar_t *mana_bar;
    stat_bar_t *xp_bar;
    stat_t *stats;
    anim_t **anims;
    int actual_state;
    int stat_point;
    bool to_animate;
    bool attacking;
    bool hitted;
    bool casting;
    sfVector2f pos;
    sfVector2f checkpoint_pos;
    sfClock *hit_clock;
    sfClock *cast_clock;
    sfClock *attack_clock;
    sfClock *death_clock;
    sfClock *blink_clock;
    sfClock *mana_regen_clock;
    fire_particle_sys_t *fire;
    sfIntRect *attack_boxes;
    sfIntRect hitbox;
    sfIntRect walking_rect;
} character_t;

typedef struct attack
{
    sfIntRect rect;
    int damages;
} attack_t;

enum {
    DOWN,
    UP,
    LEFT,
    RIGHT,
    DOWN_ATTACK,
    UP_ATTACK,
    LEFT_ATTACK,
    RIGHT_ATTACK,
    CAST,
    P_DEATH,
};

void init_character_hit_boxes(character_t *character);
bool character_movement_input(character_t *character);
character_t *init_character(resources_t *resources, sfVector2f char_pos,
                            char *class_name);
void apply_character_damage(character_t *character, int attack_value,
                            resources_t *res);
void set_anims_positions(character_t *character, sfVector2f char_pos);
void initialize_animations(character_t *character, resources_t *resources);
void actualize_character_pos(character_t *character);
void update_character_stat_bar(stat_bar_t *stat_bar);
void handle_character_hit(character_t *character);
void handle_character_death(character_t *character);
void init_character_health_bar(character_t *character, sfFont *font);
void init_character_mana_bar(character_t *character, sfFont *font);
void init_character_xp_bar(character_t *character, sfFont *font);
void mana_logic(stat_bar_t *mana_bar, sfClock *mana_regen_clock);
void xp_logic(character_t *character, stat_bar_t *xp_bar);
void reset_state_after_attack(character_t *character);
void draw_character_bars(sfRenderWindow *win, character_t *character);
void draw_character(character_t *character, sfRenderWindow *win);
void set_charac_position(character_t *character, sfVector2f pos);

char *my_itoa(int number);
char *concate(char *dest, char *src);

#define NB_ANIMS 10

#endif /* ifndef CHARACTER_H_ */
