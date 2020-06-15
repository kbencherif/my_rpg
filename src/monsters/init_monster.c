/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** file initializing monster
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "operator_abstract.h"
#include "monsters.h"
#include "resources.h"

void load_animation(char *path, monster_t *monster,
    int monster_key, resources_t *resources)
{
    monster->anims = malloc(sizeof(anim_t) * NB_MONSTER_ANIM);
    monster->anims[M_WALK] = create_anim_config(resources->
        monster_textures[monster_key].walk, concate(path, "_walk.anim"));
    monster->anims[M_HIT] = create_anim_config(resources->
        monster_textures[monster_key].hit, concate(path, "_hit.anim"));
    monster->anims[M_DEATH] = create_anim_config(resources->
        monster_textures[monster_key].death, concate(path, "_death.anim"));
    monster->anims[M_ATTACK] = create_anim_config(resources->
        monster_textures[monster_key].attack, concate(path, "_attack.anim"));
}

char *get_monster_name(int monster_key)
{
    switch (monster_key) {
        case SKELETON:
            return "skeleton";
        case EYE:
            return "eye";
        case GOBLIN:
            return "goblin";
        case MUSH:
            return "mushroom";
        case BOSS:
            return "boss";
    }
    return "skeleton";
}

void init_monster_fields(monster_t *monster)
{
    monster->attack = malloc(sizeof(attack_t));
    monster->hit_clock = sfClock_create();
    monster->movement_clock = sfClock_create();
    monster->fire_clock = sfClock_create();
    monster->fire_dmg_clock = sfClock_create();
    monster->on_fire = false;
    monster->hitted = false;
    monster->actual_state = M_WALK;
    monster->body_damages = 0;
    monster->movement = (sfVector2f) {0, 0};
    monster->anim_flipped = false;
}

void init_config_fields(monster_t *monster, char *path, sfVector2f pos)
{
    FILE *file = fopen(concate(path, ".conf"), "r");
    char *line = NULL;
    size_t len = 0, buf = 0;

    getline(&line, &len, file);
    monster->health = my_getnbr(line);
    getline(&line, &len, file);
    monster->body_damages = my_getnbr(line);
    getline(&line, &len, file);
    monster->attack->damages = my_getnbr(line);
    getline(&line, &len, file);
    buf = my_getnbr(line);
    getline(&line, &len, file);
    monster->speed_factor = buf / my_getnbr(line);
    monster->attack->rect = create_box_from_file(concate(path, "_attack.box"),
        (sfVector2f) {0, 0});
    monster->attack_offset = (sfVector2f) {monster->attack->rect.left,
    monster->attack->rect.top};
    monster->attack->rect.left += pos.x;
    monster->attack->rect.top += pos.y;
    fclose(file);
}

monster_t *init_monster(resources_t *resources,
                        int monster_key, sfVector2f pos)
{
    monster_t *monster = malloc(sizeof(monster_t));
    char *monster_name = get_monster_name(monster_key);
    char *path = concate("./config/monsters/", monster_name);

    load_animation(path, monster, monster_key, resources);
    for (int i = 0; i < 4; i++)
        sfSprite_setPosition(monster->anims[i]->sprite, pos);
    init_monster_fields(monster);
    init_monster_health_bar(monster);
    actualize_monster_pos(monster);
    init_config_fields(monster, path, monster->pos);
    monster->hitbox =
        create_box_from_file(concate(path, "_hitbox.box"), monster->pos);
    monster->walking_rect = monster->hitbox;
    monster->walking_rect.top += monster->walking_rect.height;
    monster->walking_rect.height = 1;
    return monster;
}
