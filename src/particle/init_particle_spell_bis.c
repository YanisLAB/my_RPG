/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** init.c
*/

#include "../../include/my_rpg.h"

void set_particle_point(particle_environment_t *particle_environment)
{
    sfConvexShape_setPoint(particle_environment->convex_shape, 0,
    (sfVector2f) {0, 4});
    sfConvexShape_setPoint(particle_environment->convex_shape, 1,
    (sfVector2f) {8, 8});
    sfConvexShape_setPoint(particle_environment->convex_shape, 2,
    (sfVector2f) {8, 0});
    sfConvexShape_setPoint(particle_environment->convex_shape, 3,
    (sfVector2f) {12, 0});
    sfConvexShape_setPoint(particle_environment->convex_shape, 4,
    (sfVector2f) {12, 8});
    sfConvexShape_setPoint(particle_environment->convex_shape, 5,
    (sfVector2f) {20, 8});
    sfConvexShape_setPoint(particle_environment->convex_shape, 6,
    (sfVector2f) {20, 12});
    sfConvexShape_setPoint(particle_environment->convex_shape, 7,
    (sfVector2f) {12, 12});
    sfConvexShape_setPoint(particle_environment->convex_shape, 8,
    (sfVector2f) {12, 20});
    sfConvexShape_setPoint(particle_environment->convex_shape, 9,
    (sfVector2f) {8, 20});
}

void init_particle_environment_bis(particle_environment_t *particle_environmen,
const sfUint8 alpha)
{
    particle_environmen->alpha = alpha;
    particle_environmen->speed = SPEED;
    particle_environmen->convex_shape = sfConvexShape_create();
    sfConvexShape_setPointCount(particle_environmen->convex_shape, 12);
    set_particle_point(particle_environmen);
    sfConvexShape_setPoint(particle_environmen->convex_shape, 10,
    (sfVector2f) {8, 12});
    sfConvexShape_setPoint(particle_environmen->convex_shape, 11,
    (sfVector2f) {0, 12});
    particle_environmen->clock = sfClock_create();
}

void init_particule_bis(const particle_environment_t *particle_environment,
particle_t *particule, const sfVector2f pos)
{
    particule->pos = pos;
    particule->color.a = particle_environment->alpha;
    particule->color.r = 0;
    particule->color.g = 255;
    particule->color.b = 0;
    particule->vel.x = 0;
    particule->vel.y = -20;
    particule->pos = pos;
    particule->living = true;
}

void display_particle_bis(sfRenderWindow *window, const particle_t *particule,
sfConvexShape *convex_shape)
{
    if (particule->living) {
        sfConvexShape_setFillColor(convex_shape, particule->color);
        sfConvexShape_setPosition(convex_shape, particule->pos);
        sfRenderWindow_drawConvexShape(window, convex_shape, NULL);
    }
}

void add_particle_bis(const particle_environment_t *particle_environment,
particle_t *particule, const size_t particle_num, const sfVector2f pos)
{
    size_t compte = 0;
    for (int i = 0; compte != particle_num; i += 1) {
        if (!particule[i].living) {
            init_particule_bis(particle_environment, &particule[i],
            (sfVector2f)
            {pos.x + (40 - (rand() % 60)), pos.y + (20 - (rand() % 40))});
            compte += 1;
        }
    }
}
