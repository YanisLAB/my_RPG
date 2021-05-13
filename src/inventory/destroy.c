/*
** EPITECH PROJECT, 2020
** rpg_repo
** File description:
** destroy.c
*/

#include "../../include/my_rpg.h"

void list_destroy(inventory_t **list)
{
    inventory_t *temp = (*list);
    if (temp == NULL)
        return ;
    while (temp->next != NULL) {
        temp = (*list)->next;
        if ((*list)->inv.item)
            destroy_sprite(&(*list)->inv.stuff);
        free(*list);
        (*list) = temp;
    }
    free((*list));
}

void destroy_inventory(all_t *all)
{
    for (int i = 0; i < INDEX_INVEN; i++)
        destroy_sprite(&all->inventory_s[i]);
    destroy_sprite(&all->overlay_items);
    list_destroy(&all->equiped);
    list_destroy(&all->inventory);
}