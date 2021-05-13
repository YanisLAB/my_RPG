/*
** EPITECH PROJECT, 2020
** Repo_rpg
** File description:
** display.c
*/

#include "../../include/my_rpg.h"

void display_mobs(mob_z_t **mobs, all_t *all)
{
    mob_z_t *tmp = *mobs;

    while (tmp) {
        display_sprite(all->window, &tmp->mobs.mob, 0, 0);
        tmp = tmp->next;
    }
}

void display_all_mobs(all_t *all)
{
    display_mobs(&all->mob_z1, all);
    if (all->quest != 2)
        return;
    for (int i = 0; i < INDEX_BOSS; i += 1) {
        if (all->boss[i].dead == sfFalse) {
            display_sprite(all->window, &all->boss[i].boss, 0, 0);
            sfRenderWindow_drawText(all->window, all->boss[i].id.text, NULL);
        }
    }
}