/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-yanis.labchiri
** File description:
** destroy.c
*/

#include "../../include/my_rpg.h"

void destroy_main(all_t *all)
{
    for (int i = 0; i < INDEX_BUTTON; i += 1)
        destroy_sprite(&all->button[i]);
    for (int i = 0; i < INDEX_PARA; i += 1)
        destroy_sprite(&all->parrallax[i]);
    destroy_sprite(&all->logo);
}