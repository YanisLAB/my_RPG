/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-yanis.labchiri
** File description:
** destroy.c
*/

#include "../../include/my_rpg.h"

void destroy_option(all_t *all)
{
    for (int i = 0; i < INDEX_OPTION; i += 1)
        destroy_sprite(&all->option[i]);
    for (int i = 0; i < TOUCH; i += 1) {
        sfText_destroy(all->touch[i].text);
        sfFont_destroy(all->touch[i].my_font);
    }
}