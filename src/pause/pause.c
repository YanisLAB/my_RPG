/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** init_pause.c
*/

#include "../../include/my_rpg.h"

void set_pos_pause(all_t *all)
{
    set_pos(&all->pause[1], 849, 645);
    set_pos(&all->pause[2], 849, 343);
    set_pos(&all->pause[3], 849, 491);
    set_pos(&all->pause[4], 1099, 730);
    set_pos(&all->pause[5], 674, 730);
    for (int i = 0; i < INDEX_PAUSE; i++) {
        all->pause[i].size = sfTexture_getSize(all->pause[i].texture);
        all->pause[i].size.y /= 3;
    }
}

void init_pause(all_t *all)
{
    all->use[2] = sfTrue;
    all->pause[0] = init_sprite(
    (sfIntRect) {0, 0, 1920, 1080}, "assets/pause/pause.png");
    all->pause[1] = init_sprite(
    (sfIntRect) {0, 0, 230, 94}, "assets/pause/quit.png");
    all->pause[2] = init_sprite(
    (sfIntRect) {0, 0, 230, 94}, "assets/pause/resume.png");
    all->pause[3] = init_sprite(
    (sfIntRect) {0, 0, 230, 94}, "assets/pause/save.png");
    all->pause[4] = init_sprite(
    (sfIntRect) {0, 0, 160, 155}, "assets/pause/home.png");
    all->pause[5] = init_sprite(
    (sfIntRect) {0, 0, 160, 155}, "assets/menu_button/params.png");
    set_pos_pause(all);
}

void display_pause(all_t *all)
{
    display_sprite(all->window, &all->map[0], 0, 0);
    display_sprite(all->window, &all->map[1], 0, 0);
    for (int i = 0; i < INDEX_PAUSE; i += 1)
        display_sprite(all->window, &all->pause[i], 0, 0);
}

void destroy_pause(all_t *all)
{
    for (int i = 0; i < INDEX_PAUSE; i += 1)
        destroy_sprite(&all->pause[i]);
}