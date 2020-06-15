/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** particle system
*/

#ifndef PARTICLE_SYS_
#define PARTICLE_SYS_
#include <SFML/Graphics.h>

typedef struct rain_particle {
    sfVertexArray *vertices;
    int velocity;
} rain_particle_t;

typedef struct rain_particle_sys {
    rain_particle_t *particles;
    sfClock *update_clock;
} rain_particle_sys_t;

typedef struct fire_particle {
    sfCircleShape *particle_shape;
    sfVector2f velocity;
} fire_particle_t;

typedef struct fire_particle_sys {
    fire_particle_t *particles;
    sfClock *update_clock;
    sfVector2f start_pos;
    int nb_living_particles;
} fire_particle_sys_t;

rain_particle_sys_t *init_rain_particle_sys(void);
void draw_rain_particle_sys(rain_particle_sys_t *particle_sys,
                            sfRenderWindow *win);
void update_rain_particle_sys(rain_particle_sys_t *particle_sys);
void draw_fire_particle_sys(fire_particle_sys_t *particle_sys,
                            sfRenderWindow *win);
fire_particle_sys_t *init_fire_particle_sys(sfVector2f pos);
void update_fire_particle_sys(fire_particle_sys_t *particle_sys);
void system_set_position(fire_particle_sys_t *system, sfVector2f pos);

#define NB_RAIN_PARTICLES 100
#define NB_FIRE_PARTICLES 70

#endif /* ifndef PARTICLE_SYS_ */
