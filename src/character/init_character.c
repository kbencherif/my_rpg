/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init character
*/

#include <stdlib.h>
#include <stdio.h>
#include "anim.h"
#include "lib.h"
#include "character.h"
#include "resources.h"

void initialize_fields(character_t *character, char *class_name)
{
    character->actual_state = DOWN;
    character->class_name = my_strdup(class_name);
    character->to_animate = false;
    character->stat_point = 0;
    character->attacking = false;
    character->hitted = false;
    character->casting = false;
    character->fire = NULL;
    character->attack_clock = sfClock_create();
    character->hit_clock = sfClock_create();
    character->death_clock = sfClock_create();
    character->blink_clock = sfClock_create();
    character->cast_clock = sfClock_create();
    character->mana_regen_clock = sfClock_create();
}

void initialize_stats(character_t *charac, char *class_name)
{
    char *path = concate("./config/charac/", class_name);
    FILE *file = fopen(concate(path, ".stats"), "r");
    size_t len = 0;
    char *line = NULL;

    charac->stats = malloc(sizeof(stat_t));
    getline(&line, &len, file);
    charac->stats->attack_dmg = my_getnbr(line);
    getline(&line, &len, file);
    charac->stats->spell_dmg = my_getnbr(line);
    getline(&line, &len, file);
    charac->stats->max_health_points = my_getnbr(line);
    getline(&line, &len, file);
    charac->stats->max_mana_points = my_getnbr(line);
    getline(&line, &len, file);
    charac->stats->movement_speed = my_getnbr(line);
    fclose(file);
}

void init_walk_texts(resources_t *resources, char *path)
{
    resources->character_texts->walk_down =
        sfTexture_createFromFile(concate(path, "/walk_down.png"), NULL);
    resources->character_texts->walk_up =
        sfTexture_createFromFile(concate(path, "/walk_up.png"), NULL);
    resources->character_texts->walk_left =
        sfTexture_createFromFile(concate(path, "/walk_left.png"), NULL);
    resources->character_texts->walk_right =
        sfTexture_createFromFile(concate(path, "/walk_right.png"), NULL);
}

void init_character_textures(resources_t *resources, char *class_name)
{
    resources->character_texts = malloc(sizeof(charac_texts_t));
    char *path = concate("./resources/character/", class_name);

    init_walk_texts(resources, path);
    resources->character_texts->up_attack =
        sfTexture_createFromFile(concate(path, "/top_attack.png"), NULL);
    resources->character_texts->left_attack =
        sfTexture_createFromFile(concate(path, "/left_attack.png"), NULL);
    resources->character_texts->right_attack =
        sfTexture_createFromFile(concate(path, "/right_attack.png"), NULL);
    resources->character_texts->down_attack =
        sfTexture_createFromFile(concate(path, "/down_attack.png"), NULL);
    resources->character_texts->cast =
        sfTexture_createFromFile(concate(path, "/cast_down.png"), NULL);
    resources->character_texts->death =
        sfTexture_createFromFile(concate(path, "/death.png"), NULL);
}

character_t *init_character(resources_t *resources, sfVector2f char_pos,
                            char *class_name)
{
    character_t *character = malloc(sizeof(character_t));

    init_character_textures(resources, class_name);
    initialize_fields(character, class_name);
    initialize_stats(character, class_name);
    initialize_animations(character, resources);
    set_anims_positions(character, char_pos);
    actualize_character_pos(character);
    init_character_health_bar(character, resources->fantasy_font);
    init_character_mana_bar(character, resources->fantasy_font);
    init_character_xp_bar(character, resources->fantasy_font);
    init_character_hit_boxes(character);
    character->checkpoint_pos = char_pos;
    character->walking_rect = character->hitbox;
    character->walking_rect.top += character->walking_rect.height;
    character->walking_rect.height = 3;
    return character;
}
