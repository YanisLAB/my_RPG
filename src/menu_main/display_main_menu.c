/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-yanis.labchiri
** File description:
** display_main_menu.c
*/

#include "../../include/my_rpg.h"

void display_main_menu(all_t *all)
{
    for (int i = 0; i < INDEX_PARA; i += 1)
        display_sprite(all->window, &all->parrallax[i], i + 1, 0);
    display_sprite(all->window, &all->logo, 0, 0);
    for (int i = 0; i < INDEX_BUTTON; i += 1)
        display_sprite(all->window, &all->button[i], 0, 0);
}