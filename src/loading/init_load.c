/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** init_load.c
*/

#include "../../include/my_rpg.h"

void init_loading(all_t *all)
{
    all->load[0] = init_sprite((sfIntRect) {0, 0, 1920, 1080},
    "assets/loading/loading.png");
    all->load[1] = init_sprite((sfIntRect) {0, 0, 0, 28},
    "assets/loading/loadbar.png");
    set_pos(&all->load[1], 315, 660);
}

void display_load(all_t *all)
{
    sfRenderWindow_clear(all->window, sfBlack);
    display_sprite(all->window, &all->load[0], 0, 0);
    display_sprite(all->window, &all->load[1], 0, 0);
    all->load[1].rect.width += 100;
    sfRenderWindow_display(all->window);
}