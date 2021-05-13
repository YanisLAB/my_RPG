/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** free_at.c
*/

#include "../include/my_rpg.h"

int mylist_len(mob_z_t *mobs)
{
    mob_z_t *tmp = mobs;
    int i = 0;

    while (tmp) {
        tmp = tmp->next;
        i += 1;
    }
    return (i);
}

void *mylist_get_at(mob_z_t *list, unsigned int index)
{
    mob_z_t *p = list;

    for (unsigned int i = 0; i < index; i += 1, p = p->next)
        if (p->next == NULL)
            return (NULL);
    return (p);
}

bool free_at(mob_z_t **list, int index)
{
    mob_z_t *temp;
    mob_z_t *p = NULL;

    if ((*list) == NULL)
        return (false);
    if (mylist_len(*list) <= index)
        return (false);
    if (index == 0) {
        temp = (*list)->next;
        free(*list);
        (*list) = temp;
    } else {
        p = mylist_get_at(*list, index - 1);
        temp = p->next->next;
        free(p->next);
        p->next = temp;
    }
    return (true);
}