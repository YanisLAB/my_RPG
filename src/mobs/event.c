/*
** EPITECH PROJECT, 2020
** Repo_rpg
** File description:
** event.c
*/

#include "../../include/my_rpg.h"

void damage(mob_z_t **mobs, all_t *all)
{
    mob_z_t *tmp = *mobs;

    while (tmp) {
        if (get_distance(tmp->mobs.mob.position.x,
        tmp->mobs.mob.position.y, pp.x,
        pp.y) < 25) {
            all->p.life -= 0.3;
            update_life(all);
        }
        tmp = tmp->next;
    }
}

void dammage_all_mobs(all_t *all)
{
    damage(&all->mob_z1, all);
    if (all->quest != 2)
        return;
    for (int i = 0; i < INDEX_BOSS; i += 1) {
        if (get_distance(all->boss[i].boss.position.x,
        all->boss[i].boss.position.y, pp.x,
        pp.y) < 30 && all->boss[i].life > 0)
            all->p.life -= 0.5;
    }
}