/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** ciné.c
*/

#include "../../include/my_rpg.h"

void cine(all_t *all)
{
    if (all->cine[0].rect.left >= 6178)
        change_scene(all, GAME);
    display_sprite(all->window, &all->cine[0], 0, 0);
    display_sprite(all->window, &all->cine[1], 0, 0);
    for (int i = 0; i < INDEX_CINE; i++)
        move_rect(&all->cine[i].rect, 4, -4);
}