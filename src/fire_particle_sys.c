/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** fire particle sys
*/

#include <stdlib.h>
#include "particle_system.h"

void draw_fire_particle_sys(fire_particle_sys_t *particle_sys,
                            sfRenderWindow *win)
{
    for (int i = 0; i < particle_sys->nb_living_particles; i++)
        sfRenderWindow_drawCircleShape(win,
            particle_sys->particles[i].particle_shape, NULL);
}

fire_particle_sys_t *init_fire_particle_sys(sfVector2f pos)
{
    fire_particle_sys_t *particle_system = malloc(sizeof(fire_particle_sys_t));
    fire_particle_t *particles = malloc(sizeof(fire_particle_t)
        * NB_FIRE_PARTICLES);

    particle_system->start_pos = pos;
    particle_system->update_clock = sfClock_create();
    particle_system->particles = particles;
    particle_system->nb_living_particles = 0;
    return particle_system;
}
