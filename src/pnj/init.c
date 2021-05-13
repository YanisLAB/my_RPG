/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** pnj.c
*/

#include "../../include/my_rpg.h"

void init_pnj(all_t *all)
{
    all->pnj[0] = init_sprite((sfIntRect) {0, 0, 70, 120},
    "assets/pnj/pnj.png");
    sfSprite_setOrigin(all->pnj[0].sprite, (sfVector2f) {35, 60});
    set_pos(&all->pnj[0], 900, 540);

    all->pnj[1] = init_sprite((sfIntRect) {0, 0, 70, 120},
    "assets/pnj/pnj.png");
    sfSprite_setOrigin(all->pnj[1].sprite, (sfVector2f) {35, 60});
    set_pos(&all->pnj[1], -2450, -150);
}