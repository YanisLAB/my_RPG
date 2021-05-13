/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** moov_mobs.c
*/

#include "../../include/my_rpg.h"

void boss_move_y(boss_t *boss, all_t *all)
{
    if (boss->boss.position.y < pp.y) {
        boss->boss.position.y += 2;
        boss->boss.rect.top = 194;
        boss->id.position.x = boss->boss.position.x;
        boss->id.position.y = boss->boss.position.y;
        sfText_setPosition(boss->id.text, boss->id.position);
        boss->boss.rect.left += 95;
    } else if (boss->boss.position.y > pp.y) {
        boss->boss.position.y -= 2;
        boss->boss.rect.top = 0;
        boss->id.position.x = boss->boss.position.x;
        boss->id.position.y = boss->boss.position.y;
        sfText_setPosition(boss->id.text, boss->id.position);
        boss->boss.rect.left += 95;
    }
}

void boss_to_player(boss_t *boss, all_t *all)
{
    if (boss->boss.position.x < pp.x) {
        boss->boss.position.x += 2;
        boss->boss.rect.top = 291;
        boss->id.position.x = boss->boss.position.x;
        boss->id.position.y = boss->boss.position.y;
        sfText_setPosition(boss->id.text, boss->id.position);
        boss->boss.rect.left += 95;
    } else if (boss->boss.position.x > pp.x) {
        boss->boss.position.x -= 2;
        boss->boss.rect.top = 97;
        boss->id.position.x = boss->boss.position.x;
        boss->id.position.y = boss->boss.position.y;
        sfText_setPosition(boss->id.text, boss->id.position);
        boss->boss.rect.left += 95;
    }
    boss_move_y(boss, all);
    sfClock_restart(boss->clock.clock);
    set_pos(&boss->boss, boss->boss.position.x, boss->boss.position.y);
}

void moov_all_mobs(all_t *all)
{
    moov_mobs(&all->mob_z1, all);
    if (all->quest != 2)
        return;
    for (int i = 0; i < INDEX_BOSS; i += 1) {
        all->boss[i].clock.time =
        sfClock_getElapsedTime(all->boss[i].clock.clock);
        all->boss[i].clock.sec =
        all->boss[i].clock.time.microseconds / 1000000.0;
        if (get_distance(all->boss[i].boss.position.x,
        all->boss[i].boss.position.y, pp.x, pp.y) < 700
        && all->boss[i].clock.sec > 0.05)
            boss_to_player(&all->boss[i], all);
    }
}