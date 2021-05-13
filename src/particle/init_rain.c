/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** init_rain.c
*/

#include "../../include/my_rpg.h"

void init_rain_env(particle_environment_t *particle_environment,
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha)
{
    particle_environment->angle_min = angle.x;
    particle_environment->angle_max = angle.y;
    particle_environment->gravity = gravity;
    particle_environment->alpha = alpha;
    particle_environment->speed = SPEED;
    particle_environment->circle_shape = sfCircleShape_create();
    particle_environment->rectangle_shape = sfRectangleShape_create();
    sfRectangleShape_setSize(particle_environment->rectangle_shape,
    (sfVector2f) {50, 5});
    sfRectangleShape_rotate(particle_environment->rectangle_shape, -45);
    particle_environment->clock = sfClock_create();
}

void init_rain(const particle_environment_t *particle_environm,
particle_t *particule, const sfVector2f pos)
{
    float angle = 0;
    particule->pos = pos;
    particule->color.a = particle_environm->alpha;
    particule->color.r = 0;
    particule->color.g = 191;
    particule->color.b = 255;
    angle = ((float)rand()/(float)(RAND_MAX)) * (particle_environm->angle_max -
    particle_environm->angle_min) + particle_environm->angle_min;
    particule->vel.x = cos(angle);
    particule->vel.y = sin(angle);
    particule->pos = pos;
    particule->living = true;
    particule->radius = 10;
}

void display_rain(sfRenderWindow *window, const particle_t *particule,
sfRectangleShape *rectangle_shape)
{
    if (particule->living) {
        sfRectangleShape_setFillColor(rectangle_shape, particule->color);
        sfRectangleShape_setPosition(rectangle_shape, particule->pos);
        sfRenderWindow_drawRectangleShape(window, rectangle_shape, NULL);

    }
}

void update_rain(const particle_environment_t *particle_environm,
particle_t *particule)
{
    if (particule->living) {
        particule->color.a = particle_environm->alpha;
        if (particule->pos.x > -15 && particule->pos.y < 1080) {
            particule->vel.x -= 0.2;
            particule->vel.y += 0.2;
            particule->pos.x += (particule->vel.x * particle_environm->speed);
            particule->pos.y += (particule->vel.y * particle_environm->speed);
        } else {
            particule->vel.x = 0.1;
            particule->vel.y = 0.1;
            particule->pos.x = -10 + ((rand() % 1920) * 10);
            particule->pos.y = -5 + ((rand() % -1080) * -5);
        }
    }
}

void add_rain(const particle_environment_t *particle_environment,
particle_t *particule, const size_t particle_num, const sfVector2f pos)
{
    size_t compte = 0;
    for (int i = 0; compte != particle_num; i += 1) {
        if (!particule[i].living) {
            init_rain(particle_environment, &particule[i], (sfVector2f)
            {pos.x + ((rand() % 1920) * 10), pos.y + ((rand() % -1080) * -5)});
            compte += 1;
        }
    }
}