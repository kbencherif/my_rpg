/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** update fire particle sys
*/

#include <stdlib.h>
#include "particle_system.h"

void reset_particle(fire_particle_t *particle, sfVector2f start_pos)
{
    sfColor yellow = {255, 249, 0, 200};

    start_pos.x += rand() % 6;
    sfCircleShape_setPosition(particle->particle_shape, start_pos);
    sfCircleShape_setFillColor(particle->particle_shape, yellow);
}

void system_set_position(fire_particle_sys_t *system, sfVector2f pos)
{
    sfVector2f actual_pos;

    for (int i = 0; i < system->nb_living_particles; i++) {
        actual_pos = sfCircleShape_getPosition(
            system->particles[i].particle_shape);
        sfCircleShape_setPosition(system->particles[i].particle_shape,
            (sfVector2f) {(actual_pos.x - system->start_pos.x) + pos.x,
            (actual_pos.y - system->start_pos.y) + pos.y});
    }
    system->start_pos = pos;
}

void add_fire_particle(fire_particle_sys_t *particle_sys)
{
    sfVector2f start_velocity = {0.5 , -0.5};
    fire_particle_t *particles = particle_sys->particles;
    int i = 0;

    start_velocity.x = (float) rand() / ((float) (RAND_MAX) * 1) / 4;
    if (rand() % 2 == 0)
        start_velocity.x = -start_velocity.x;
    for (; i < particle_sys->nb_living_particles; i++);
    particles[i].particle_shape = sfCircleShape_create();
    particles[i].velocity = start_velocity;
    reset_particle(&particles[i], particle_sys->start_pos);
    sfCircleShape_setRadius(particles[i].particle_shape, 3);
    particle_sys->nb_living_particles += 1;
}

void fade_color(fire_particle_t *particle, sfVector2f start_pos)
{
    sfColor color = sfCircleShape_getFillColor(particle->particle_shape);
    sfColor new_color = {.a = color.a - 3};
    sfVector2f particle_pos =
        sfCircleShape_getPosition(particle->particle_shape);

    if (particle_pos.y < start_pos.y - 15) {
        new_color.r = (117 - color.r) * 0.09 + color.r;
        new_color.g = (117 - color.g) * 0.09 + color.g;
        new_color.b = (117 - color.b) * 0.09 + color.b;
    } else {
        new_color.r = (213 - color.r) * 0.06 + color.r;
        new_color.g = (89 - color.g) * 0.06 + color.g;
        new_color.b = (7 - color.b) * 0.06 + color.b;
    }
    sfCircleShape_setFillColor(particle->particle_shape, new_color);
}

void update_fire_particle_sys(fire_particle_sys_t *particle_sys)
{
    fire_particle_t particle;
    sfVector2f particle_pos;

    if (particle_sys->nb_living_particles < NB_FIRE_PARTICLES)
        add_fire_particle(particle_sys);
    for (int i = 0; i < particle_sys->nb_living_particles; i++) {
        particle = particle_sys->particles[i];
        particle_pos = sfCircleShape_getPosition(particle.particle_shape);
        fade_color(&particle, particle_sys->start_pos);
        if (particle_pos.y < particle_sys->start_pos.y - 30)
            reset_particle(&particle, particle_sys->start_pos);
        sfCircleShape_move(particle.particle_shape, particle.velocity);
    }
    sfClock_restart(particle_sys->update_clock);
}
