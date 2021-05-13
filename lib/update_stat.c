/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** update_stat.c
*/

#include "../include/my_rpg.h"

void update_stat(all_t *all, int *stat, int type)
{
    all->p.max_mana += stat[0] * type;
    all->p.max_hp += stat[1] * type;
    all->p.attack += stat[2] * type;
}