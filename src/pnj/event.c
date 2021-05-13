/*
** EPITECH PROJECT, 2020
** rpg_repo
** File description:
** eventpnj.c
*/

#include "../../include/my_rpg.h"

void check_pnj(all_t *all, int i)
{
    if (i == 0)
        pnj1(all);
    if (i == 1)
        pnj2(all);
}

void event_pnj(all_t *all)
{
    for (int i = 0; i < INDEX_PNJ; i += 1) {
        if (get_distance(all->pnj[i].position.x,
        all->pnj[i].position.y, pp.x, pp.y) < 100) {
            all->dial = true;
            check_pnj(all, i);
            break;
        } else
            all->dial = false;
    }
}