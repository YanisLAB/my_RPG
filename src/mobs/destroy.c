/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** destroy.c
*/

#include "../../include/my_rpg.h"

void mob_list_destroy(mob_z_t **list)
{
    mob_z_t *temp = (*list);

    if (temp == NULL)
        return ;
    while (temp != NULL) {
        destroy_sprite(&temp->mobs.mob);
        temp = temp->next;
    }
    temp = (*list);
    while (temp != NULL) {
        temp = (*list)->next;
        free(*list);
        (*list) = temp;
    }
}

void destroy_mob(all_t *all)
{
    mob_list_destroy(&all->mob_z1);
}

void display_boss(all_t *all)
{
    for (size_t index = 0; index != PARICULE_MAX; index++) {
        display_rain(all->window, &all->particle_rain[index], \
        all->rain.rectangle_shape);
    }
    display_sprite(all->window, &all->boss_f.bar_life, 0, 0);
    display_sprite(all->window, &all->boss_f.bg_bar, 0, 0);
    sfRenderWindow_drawText(all->window, all->boss_f.name.text, NULL);
}

void destroy_boss_final(all_t *all)
{
    destroy_sprite(&all->boss_f.boss);
    destroy_sprite(&all->boss_f.bar_life);
    destroy_sprite(&all->boss_f.bg_bar);
    sfText_destroy(all->boss_f.name.text);
}