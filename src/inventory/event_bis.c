/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** event_bis.c
*/

#include "../../include/my_rpg.h"

void switch_items(all_t *all)
{
    inventory_t *tmp = all->inventory;
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->inv.item == sfTrue && ((all->mouse.x >= tmp->inv.coord.x &&
        all->mouse.x <= tmp->inv.coord.x + 81) && (all->mouse.y >=
        tmp->inv.coord.y && all->mouse.y <= tmp->inv.coord.y + 79)))
            check_switch(tmp, all);
    }
}

void remove_item(all_t *all)
{
    inventory_t *tmp = all->inventory;
    all->mouse = sfMouse_getPositionRenderWindow(all->window);
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->inv.item == sfTrue && tmp->inv.type != 6 &&
        ((all->mouse.x >= tmp->inv.coord.x && all->mouse.x <=
        tmp->inv.coord.x + 81) && (all->mouse.y >= tmp->inv.coord.y &&
        all->mouse.y <= tmp->inv.coord.y + 79))) {
            destroy_sprite(&tmp->inv.stuff);
            tmp->inv.item = sfFalse;
        }
    }
}

void unequipe_item(all_t *all)
{
    inventory_t *equipe = all->equiped;
    inventory_t *tmp = all->inventory;
    for (; tmp != NULL && tmp->inv.item == sfTrue; tmp = tmp->next);
    if (tmp == NULL)
        return;
    for (; equipe != NULL; equipe = equipe->next) {
        if (equipe->inv.item == sfTrue && ((all->mouse.x >=
        equipe->inv.coord.x && all->mouse.x <= equipe->inv.coord.x + 81)
        && (all->mouse.y >= equipe->inv.coord.y && all->mouse.y <=
        equipe->inv.coord.y + 79))) {
            equipe->inv.item = sfFalse;
            give_item(all, equipe->inv.type);
            update_stat(all, equipe->inv.stat, -1);
            destroy_sprite(&equipe->inv.stuff);
            return;
        }
    }
}