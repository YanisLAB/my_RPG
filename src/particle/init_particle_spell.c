/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** init.c
*/

#include "../../include/my_rpg.h"

void update_particle_bis(const particle_environment_t *particle_environment,
particle_t *particule)
{
    if (particule->living) {
        particule->vel.x += particle_environment->gravity.x;
        particule->vel.y += particle_environment->gravity.y;
        particule->pos.x += (particule->vel.x * particle_environment->speed);
        particule->pos.y += (particule->vel.y * particle_environment->speed);
        if ((particule->pos.x >= 0 && particule->pos.x <= 1920)
        && (particule->pos.y >= 0 && particule->pos.y <= 1080))
            particule->color.a -= 1;
    }
}

void init_particle_environment(particle_environment_t *particle_environment,
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha)
{
    particle_environment->angle_min = angle.x;
    particle_environment->angle_max = angle.y;
    particle_environment->gravity = gravity;
    particle_environment->alpha = alpha;
    particle_environment->speed = SPEED + 0.4;
    particle_environment->circle_shape = sfCircleShape_create();
    particle_environment->clock = sfClock_create();
}

void init_particule(const particle_environment_t *particle_environme,
particle_t *particule, const sfVector2f pos)
{
    float angle = 0;
    particule->pos = pos;
    particule->color.a = particle_environme->alpha;
    particule->color.r = 0;
    particule->color.g = 0;
    particule->color.b = 255;
    angle = ((float)rand()/(float)(RAND_MAX)) * (particle_environme->angle_max
    - particle_environme->angle_min) + particle_environme->angle_min;
    particule->vel.x = cos(angle);
    particule->vel.y = sin(angle);
    particule->living = true;
    particule->radius = 5;
}

void display_particle(sfRenderWindow *window, const particle_t *particule,
sfCircleShape *circle_shape)
{
    if (particule->living) {
        sfCircleShape_setRadius(circle_shape, particule->radius);
        sfCircleShape_setFillColor(circle_shape, particule->color);
        sfCircleShape_setPosition(circle_shape, particule->pos);
        sfRenderWindow_drawCircleShape(window, circle_shape, NULL);
    }
}

void add_particle(const particle_environment_t *particle_environment,
particle_t *particule, const size_t particle_num, const sfVector2f pos)
{
    size_t compte = 0;
    for (int i = 0; compte != particle_num; i += 1) {
        if (!particule[i].living) {
            init_particule(particle_environment, &particule[i], pos);
            compte += 1;
        }
    }
}
