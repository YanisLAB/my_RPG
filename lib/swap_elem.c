/*
** EPITECH PROJECT, 2020
** Repo_rpg
** File description:
** swap_elem.c
*/

#include "../include/my_rpg.h"

void init_item_push_back(inventory_t **list, sfVector2f coord)
{
    inventory_t *node = malloc(sizeof(*node));
    inventory_t *temp;
    inv_t tmp;

    tmp.coord.x = coord.x;
    tmp.coord.y = coord.y;
    tmp.type = 0;
    tmp.item = sfFalse;
    node->inv = tmp;
    node->next = NULL;
    if ((*list) == NULL)
        (*list) = node;
    else {
        for (temp = (*list); temp->next != NULL; temp = temp->next);
        temp->next = node;
    }
}

void mobs_push_back(mob_z_t **mobs, sprite_t img, int life, pos_mob_t pos)
{
    mob_z_t *node = malloc(sizeof(*node));
    mob_z_t *temp;

    node->mobs.mob = img;
    set_pos(&node->mobs.mob,
        (rand() % ((pos.x - 300) - (pos.x + 300)) + (pos.x + 300)),
        (rand() % ((pos.y - 300) - (pos.y + 300)) + (pos.y + 300)) * -1);
    node->life = life;
    node->next = NULL;
    if ((*mobs) == NULL)
        (*mobs) = node;
    else {
        for (temp = (*mobs); temp->next != NULL; temp = temp->next);
        temp->next = node;
    }
}