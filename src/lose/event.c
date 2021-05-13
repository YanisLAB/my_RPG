/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** event.c
*/

#include "../../include/my_rpg.h"

void overlay_lose_bis(all_t *all, int i)
{
    if (overlay_check(&all->lose[i], all) == sfTrue &&
    click_check(all) == sfTrue) {
        sfSound_play(all->click.sound);
        all->lose[i].rect.top = all->lose[i].size.y * 2;
        sfSprite_setTextureRect(all->lose[i].sprite,
        all->lose[i].rect);
    } else if (overlay_check(&all->lose[i], all) == sfTrue) {
        all->lose[i].rect.top = all->lose[i].size.y;
        sfSprite_setTextureRect(all->lose[i].sprite,
        all->lose[i].rect);
    } else {
        all->lose[i].rect.top = 0;
        sfSprite_setTextureRect(all->lose[i].sprite,
        all->lose[i].rect);
    }
}

void overlay_lose(all_t *all)
{
    for (int i = 1; i < INDEX_LOSE; i += 1) {
        overlay_lose_bis(all, i);
    }
}

void event_loseb(all_t *all)
{
        if (release_check(all, &all->lose[5]) == sfTrue)
            change_scene(all, OPTION);
        if (release_check(all, &all->lose[4]) == sfTrue) {
            change_scene(all, MENU);
            reset(all);
        }
        if (release_check(all, &all->lose[2]) == sfTrue) {
            restart(all);
            change_scene(all, GAME);
        }
        overlay_lose(all);
}

void event_lose(all_t *all)
{
    while (sfRenderWindow_pollEvent(all->window, &all->event)) {
        if (click_check(all) == sfTrue)
            all->mouse = sfMouse_getPositionRenderWindow(all->window);
        if (release_check(all, &all->lose[1]) == sfTrue)
            sfRenderWindow_close(all->window);
        event_loseb(all);
    }
}
