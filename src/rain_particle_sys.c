/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init rain particle sys
*/

#include <stdlib.h>
#include "particle_system.h"

void randomize_pos(sfVertex *start, sfVertex *end)
{
    int x_pos = rand() % 1920;
    int y_pos = rand() % 1080;

    start->position.x = x_pos + 10;
    start->position.y = y_pos;
    end->position.x = x_pos;
    end->position.y = y_pos + 20;
}

void draw_rain_particle_sys(rain_particle_sys_t *particle_sys,
                            sfRenderWindow *win)
{
    for (int i = 0; i < NB_RAIN_PARTICLES; i++)
        sfRenderWindow_drawVertexArray(win,
            particle_sys->particles[i].vertices, NULL);
}

void update_rain_particle_sys(rain_particle_sys_t *particle_sys)
{
    sfVertex *start = NULL;
    sfVertex *end = NULL;
    int velocity = 0;

    for (int i = 0; i < NB_RAIN_PARTICLES; i++) {
        start = sfVertexArray_getVertex(
            particle_sys->particles[i].vertices, 0);
        end = sfVertexArray_getVertex(particle_sys->particles[i].vertices, 1);
        if (start->position.y > 1080) {
            velocity = particle_sys->particles[i].velocity;
            start->position.x -= 1 * velocity;
            start->position.y += 2 * velocity;
            end->position.x -= 1 * velocity;
            end->position.y += 2 * velocity;
        } else {
            randomize_pos(start, end);
        }
    }
    sfClock_restart(particle_sys->update_clock);
}

rain_particle_sys_t *init_rain_particle_sys(void)
{
    rain_particle_sys_t *particle_system = malloc(sizeof(rain_particle_sys_t));
    rain_particle_t *particle_sys = malloc(sizeof(rain_particle_t)
        * NB_RAIN_PARTICLES);
    sfVertex start_rain_vertex = {{10, 0}, {25, 50, 50, 150}, {0, 0}};
    sfVertex end_rain_vertex = {{0, 20}, {50, 127, 255, 212}, {0, 0}};

    for (int i = 0; i < NB_RAIN_PARTICLES; i++) {
        particle_sys[i] =
            (rain_particle_t) {sfVertexArray_create(), rand() % 2 + 1};
        sfVertexArray_setPrimitiveType(particle_sys[i].vertices, sfLines);
        sfVertexArray_append(particle_sys[i].vertices, start_rain_vertex);
        sfVertexArray_append(particle_sys[i].vertices, end_rain_vertex);
        randomize_pos(&start_rain_vertex, &end_rain_vertex);
    }
    particle_system->update_clock = sfClock_create();
    particle_system->particles = particle_sys;
    return particle_system;
}
