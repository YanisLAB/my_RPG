/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** move_mobs.c
*/

#include "../../include/my_rpg.h"

void moov_to_player_y(sprite_t *mobs, all_t *all)
{
    if (mobs->position.y <= pp.y + 10) {
        mobs->position.y += 2;
        mobs->rect.top = 130;
        mobs->rect.left += 64;
    } else if (mobs->position.y >= pp.y - 10) {
        mobs->position.y -= 2;
        mobs->rect.top = 0;
        mobs->rect.left += 64;
    }
}

void moov_to_player(sprite_t *mobs, all_t *all)
{
    if (mobs->position.x <= pp.x + 10) {
        mobs->position.x += 2;
        mobs->rect.top = 195;
        mobs->rect.left += 64;
    } else if (mobs->position.x >= pp.x - 10) {
        mobs->position.x -= 2;
        mobs->rect.top = 65;
        mobs->rect.left += 64;
    }
    moov_to_player_y(mobs, all);
    set_pos(mobs, mobs->position.x, mobs->position.y);
}

void moov_mobs(mob_z_t **mobs, all_t *all)
{
    mob_z_t *tmp = *mobs;

    while (tmp) {
        if (get_distance(tmp->mobs.mob.position.x,
        tmp->mobs.mob.position.y, pp.x,
        pp.y) < 300 && get_distance(tmp->mobs.mob.position.x,
        tmp->mobs.mob.position.y, pp.x,
        pp.y) > 25)
            moov_to_player(&tmp->mobs.mob, all);
        tmp = tmp->next;
    }
}