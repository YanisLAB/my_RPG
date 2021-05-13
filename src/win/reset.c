/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** reset.c
*/

#include "../../include/my_rpg.h"

void init_reset(all_t *all)
{
    init_inv(all);
    init_player(all);
    init_pnj(all);
    init_music(all);
    init_all_mobs(all);
}

void reset2(all_t *all)
{
    destroy_inventory(all);
    destroy_boss(all);
    destroy_sound(all);
    destroy_player(all);
    destroy_map(all);
    destroy_mob(all);
    all->scene = 0;
    all->last_scene = 0;
    all->keys.change = 0;
    all->controller.sec = 0;
    all->time_joy.sec = 0;
    all->keys.down = 18;
    all->keys.up = 22;
    all->keys.left = 0;
    all->keys.right = 3;
    all->keys.inv = 4;
    all->quest = 0;
    all->dial = false;
    init_reset(all);
}