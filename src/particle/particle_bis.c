/*
** EPITECH PROJECT, 2020
** my_rpg1
** File description:
** particle_bis.c
*/

#include "../../include/my_rpg.h"

void update_particle(const particle_environment_t *particle_environment,
particle_t *particule)
{
    if (particule->living) {
        particule->vel.y -= 1;
        particule->pos.x += (particule->vel.x * particle_environment->speed);
        particule->pos.y += (particule->vel.y * particle_environment->speed);
        if ((particule->pos.x >= 0 && particule->pos.x <= 1920)
        && (particule->pos.y >= 0 && particule->pos.y <= 1080))
            particule->color.a -= 1;
    }
}