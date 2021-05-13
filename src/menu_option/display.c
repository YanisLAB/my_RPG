/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-yanis.labchiri
** File description:
** display.c
*/

#include "../../include/my_rpg.h"

void display_option(all_t *all)
{
    if (all->last_scene == MENU) {
        for (int i = 0; i < INDEX_PARA; i += 1)
            display_sprite(all->window, &all->parrallax[i], i + 1, 0);
    }
    if (all->last_scene == PAUSE) {
        display_sprite(all->window, &all->map[0], 0, 0);
        display_sprite(all->window, &all->map[1], 0, 0);
    }
    for (int i = 0; i < INDEX_OPTION; i += 1)
        display_sprite(all->window, &all->option[i], 0, 0);
    for (int i = 0; i < TOUCH; i += 1) {
        sfRenderWindow_drawText(all->window, all->touch[i].text, NULL);
        sfText_setString(all->touch[i].text, all->touch[i].str);
    }
}