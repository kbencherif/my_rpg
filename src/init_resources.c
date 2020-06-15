/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init resources
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stddef.h>
#include "resources.h"
#include "monsters.h"

monster_textures_t get_monsters_anim_from_file(char *monster_name)
{
    monster_textures_t textures;
    char *path = concate("./resources/Monsters/", monster_name);

    path = concate(path, "/");
    textures.attack =
        sfTexture_createFromFile(concate(path, "Attack.png"), NULL);
    textures.hit =
        sfTexture_createFromFile(concate(path, "Take Hit.png"), NULL);
    textures.walk =
        sfTexture_createFromFile(concate(path, "Walk.png"), NULL);
    textures.death =
        sfTexture_createFromFile(concate(path, "Death.png"), NULL);
    return textures;
}

monster_textures_t *init_monster_textures(void)
{
    monster_textures_t *textures =
        malloc(sizeof(monster_textures_t) * 5);

    textures[SKELETON] = get_monsters_anim_from_file("Skeleton");
    textures[EYE] = get_monsters_anim_from_file("Flying eye");
    textures[GOBLIN] = get_monsters_anim_from_file("Goblin");
    textures[MUSH] = get_monsters_anim_from_file("Mushroom");
    textures[BOSS] = get_monsters_anim_from_file("Boss");
    return textures;
}

sfSound **create_tab_sound(void)
{
    sfSound **tab_sound = malloc(sizeof(sfSound*) * 5);
    sfSoundBuffer *sound1 = sfSoundBuffer_createFromFile
        ("resources/song/walk_song.wav");
    sfSoundBuffer *sound2 = sfSoundBuffer_createFromFile
        ("resources/song/sword-slash.ogg");
    sfSoundBuffer *sound3 = sfSoundBuffer_createFromFile
        ("resources/song/fire_song.ogg");
    sfSoundBuffer *sound4 = sfSoundBuffer_createFromFile
        ("resources/song/interact_song.ogg");
    sfSoundBuffer *sound5 = sfSoundBuffer_createFromFile
        ("resources/song/damage_sound.ogg");
    for (int i = 0; i != 5; i++)
        tab_sound[i] = sfSound_create();
    sfSound_setBuffer(tab_sound[0], sound1);
    sfSound_setBuffer(tab_sound[1], sound2);
    sfSound_setBuffer(tab_sound[2], sound3);
    sfSound_setBuffer(tab_sound[3], sound4);
    sfSound_setBuffer(tab_sound[4], sound5);
    return (tab_sound);
}

resources_t *init_resources(void)
{
    resources_t *resources = malloc(sizeof(resources_t));
    resources->monster_textures = init_monster_textures();
    resources->fantasy_font =
        sfFont_createFromFile("./resources/font/Windlass.ttf");
    resources->item_texture = sfTexture_createFromFile(
            "./resources/inventory/texture/item_spritesheet.png", NULL);
    resources->tile_tex = create_texture_tab();
    resources->tab_sound = create_tab_sound();
    resources->walk_clock = sfClock_create();
    return resources;
}
