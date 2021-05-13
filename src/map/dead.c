/*
** EPITECH PROJECT, 2020
** rpg2
** File description:
** dead.c
*/

#include "../../include/my_rpg.h"

void check_deadb(all_t *all, int i, inventory_t *tmp_inv)
{
    all->p.xp += 50;
    all->boss[i].dead = sfTrue;
    if (all->boss[i].id.nbr == 44)
        tmp_inv->inv.stuff = init_sprite((sfIntRect) {0, 0, 81, 79},
        "assets/inventory/44.png");
    if (all->boss[i].id.nbr == 99)
        tmp_inv->inv.stuff = init_sprite((sfIntRect) {0, 0, 81, 79},
        "assets/inventory/99.png");
    if (all->boss[i].id.nbr == 49)
        tmp_inv->inv.stuff = init_sprite((sfIntRect) {0, 0, 81, 79},
        "assets/inventory/49.png");
    set_pos(&tmp_inv->inv.stuff, tmp_inv->inv.coord.x,
    tmp_inv->inv.coord.y);
    tmp_inv->inv.item = sfTrue;
    tmp_inv->inv.type = 6;
}

void dead_mobsb(all_t *all)
{
    int a = 0;

    a = rand() % 3;
    if (a == 0)
        give_item(all, 0);
}

void dead_mobs(all_t *all)
{
    int i = 0;

    mob_z_t *tmp = all->mob_z1;
    while (tmp) {
        if (tmp->life <= 0) {
            all->p.xp += 50;
            update_life(all);
            dead_mobsb(all);
            free_at(&all->mob_z1, i);
            tmp = all->mob_z1;
            i = 0;
        }
        if (tmp == NULL && tmp->life <= 0)
            break;
        i += 1;
        tmp = tmp->next;
    }
}

void check_dead(all_t *all)
{
    inventory_t *tmp_inv = all->inventory;

    if (all->p.life <= 0) {
        init_lose(all);
        change_scene(all, DEAD);
    }
    dead_mobs(all);
    for (;tmp_inv != NULL && tmp_inv->inv.item == sfTrue;
    tmp_inv = tmp_inv->next);
    if (tmp_inv == NULL)
        return;
    if (all->quest != 2)
        return;
    for (int i = 0; i < INDEX_BOSS; i += 1) {
        if (all->boss[i].life <= 0 && all->boss[i].dead == sfFalse)
            check_deadb(all, i, tmp_inv);
    }
}