/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** reset.c
*/

#include "../../include/my_rpg.h"

void restart_bis(all_t *all)
{
    init_mobs(&all->mob_z1, 15, -3500, -4200);
    init_mobs(&all->mob_z1, 15, -2000, -3000);
    init_mobs(&all->mob_z1, 15, 300, -2300);
    init_mobs(&all->mob_z1, 15, -3250, 5000);
    init_mobs(&all->mob_z1, 15, -2000, -4000);
    init_mobs(&all->mob_z1, 15, 300, -3500);
    set_pos(&all->pnj[0], 900, 540);
    set_pos(&all->pnj[1], -2450, -150);
    all->colspell1 = 0;
    all->colspell2 = 0;
    all->colspell3 = 0;
    all->colspell4 = 0;
}

void restart(all_t *all)
{
    all->p.life = all->p.max_hp;
    all->p.mana = all->p.max_mana;
    all->map[0].rect = (sfIntRect) {6178, 5796, 1980, 1080};
    all->map[1].rect = (sfIntRect) {6178, 5796, 1980, 1080};
    all->minimap[0].rect = (sfIntRect) {1641, 1434, 300, 300};
    set_pos(&all->boss[0].boss, -3250, -4200);
    set_pos(&all->boss[1].boss, -2000, -3000);
    set_pos(&all->boss[2].boss, 300, -2500);
    destroy_mob(all);
    init_mobs(&all->mob_z1, 15, -2500, -150);
    init_mobs(&all->mob_z1, 15, -800, 0);
    init_mobs(&all->mob_z1, 15, -2500, -1500);
    init_mobs(&all->mob_z1, 15, -2500, -2500);
    restart_bis(all);
}