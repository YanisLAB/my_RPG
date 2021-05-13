/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** save_bis.c
*/

#include "../../include/my_rpg.h"

void save_pos_mobs(all_t *all, int x, int y)
{
    for (mob_z_t *temp = all->mob_z1; temp != NULL; temp = temp->next) {
        temp->mobs.mob.position.x -= x;
        temp->mobs.mob.position.y -= y;
        sfSprite_setPosition(temp->mobs.mob.sprite, temp->mobs.mob.position);
    }
    for (int i = 0; i < INDEX_BOSS; i += 1) {
        all->boss[i].boss.position.x -= x;
        all->boss[i].boss.position.x -= y;
        sfSprite_setPosition(all->boss[i].boss.sprite,
        all->boss[i].boss.position);
    }
    all->boss_f.boss.position.x -= x;
    all->boss_f.boss.position.y -= y;
    sfSprite_setPosition(all->boss_f.boss.sprite, all->boss_f.boss.position);
}