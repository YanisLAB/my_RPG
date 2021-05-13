/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** map_bis.c
*/

#include "../../include/my_rpg.h"

void init_map(all_t *all)
{
    all->use[0] = sfTrue;
    all->map[0] = init_sprite(
    (sfIntRect) {6178, 5796, 1980, 1080}, "assets/map/rpgbg.png");
    all->map[1] = init_sprite(
    (sfIntRect) {6178, 5796, 1980, 1080}, "assets/map/rpg1.png");
    all->cine[0] = init_sprite(
    (sfIntRect) {4178, 3796, 1980, 1080}, "assets/map/rpgbg.png");
    all->cine[1] = init_sprite(
    (sfIntRect) {4178, 3796, 1980, 1080}, "assets/map/rpg1.png");
    init_minimap(all);
}

void destroy_map(all_t *all)
{
    for (int i = 0; i < INDEX_MAP; i++) {
        destroy_sprite(&all->map[i]);
    }
    for (int i = 0; i < INDEX_CINE; i++)
        destroy_sprite(&all->cine[i]);
    destroy_minimap(all);
}