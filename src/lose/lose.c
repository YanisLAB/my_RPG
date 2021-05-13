/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** init_lose.c
*/

#include "../../include/my_rpg.h"

void set_pos_lose(all_t *all)
{
    set_pos(&all->lose[1], 849, 645);
    set_pos(&all->lose[2], 849, 343);
    set_pos(&all->lose[3], 849, 491);
    set_pos(&all->lose[4], 1099, 730);
    set_pos(&all->lose[5], 674, 730);
    for (int i = 0; i < INDEX_LOSE; i++) {
        all->lose[i].size = sfTexture_getSize(all->lose[i].texture);
        all->lose[i].size.y /= 3;
    }
}

void init_lose(all_t *all)
{
    all->use[3] = sfTrue;
    all->lose[0] = init_sprite(
    (sfIntRect) {0, 0, 1920, 1080}, "assets/end/lose.png");
    all->lose[1] = init_sprite(
    (sfIntRect) {0, 0, 230, 94}, "assets/pause/quit.png");
    all->lose[2] = init_sprite(
    (sfIntRect) {0, 0, 230, 94}, "assets/end/restart.png");
    all->lose[3] = init_sprite(
    (sfIntRect) {0, 0, 230, 94}, "assets/pause/save.png");
    all->lose[4] = init_sprite(
    (sfIntRect) {0, 0, 160, 155}, "assets/pause/home.png");
    all->lose[5] = init_sprite(
    (sfIntRect) {0, 0, 160, 155}, "assets/menu_button/params.png");
    set_pos_lose(all);
}

void display_lose(all_t *all)
{
    display_sprite(all->window, &all->map[0], 0, 0);
    display_sprite(all->window, &all->map[1], 0, 0);
    for (int i = 0; i < INDEX_LOSE; i += 1)
        display_sprite(all->window, &all->lose[i], 0, 0);
}

void destroy_lose(all_t *all)
{
    for (int i = 0; i < INDEX_LOSE; i += 1)
        destroy_sprite(&all->lose[i]);
}