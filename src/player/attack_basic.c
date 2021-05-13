/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** attack_basic.c
*/

#include "../../include/my_rpg.h"

void display_a(all_t *all, int rect)
{
    all->p.attack_s.rect.top = rect;
    if (rect == 0 || rect == 324) {
        all->p.attack_s.position.x = pp.x;
        all->p.attack_s.position.y = pp.y;
    }
    if (rect == 162) {
        all->p.attack_s.position.x = pp.x - 20;
        all->p.attack_s.position.y = pp.y + 5;
    }
    if (rect == 486) {
        all->p.attack_s.position.x = pp.x + 10;
        all->p.attack_s.position.y = pp.y - 45;
    }
    all->p.attack_s.rect.left += 176;
    sfSprite_setPosition(all->p.attack_s.sprite, all->p.attack_s.position);
}

int choose_rect(all_t *all)
{
    int rect = 0;

    if (all->p.player.rect.top == UP)
        rect = 0;
    if (all->p.player.rect.top == LEFT)
        rect = 162;
    if (all->p.player.rect.top == DOWN)
        rect = 324;
    if (all->p.player.rect.top == RIGHT)
        rect = 486;
    return (rect);
}

void display_attack(all_t *all)
{
    int rect = 0;

    rect = choose_rect(all);
    all->p.attack_s.rect.top = rect;
    all->p.attack_c.time = sfClock_getElapsedTime(all->p.attack_c.clock);
    all->p.attack_c.sec = all->p.attack_c.time.microseconds / 1000000.0;
    display_sprite(all->window, &all->p.attack_s, 0, 0);
    if (all->p.attack_c.sec > 0.2) {
        if (all->p.attack_s.rect.left >= 352) {
            all->p.attack_s.rect.left = -176;
            all->p.finish = 0;
        }
        display_a(all, rect);
        sfClock_restart(all->p.attack_c.clock);
    }
}

void move_player(all_t *all, int top, int mtop)
{
    all->p.player.rect.top = top;
    all->p.player.rect.left += 65;
    all->minimap[1].rect.top = mtop;
    all->minimap[1].rect.left += 16;
}