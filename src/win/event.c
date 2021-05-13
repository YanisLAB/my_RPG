/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** event.c
*/

#include "../../include/my_rpg.h"

void check_overlay_win(all_t *all, int i)
{
    if (overlay_check(&all->win[i], all) == sfTrue &&
    click_check(all) == sfTrue) {
        sfSound_play(all->click.sound);
        all->win[i].rect.top = all->win[i].size.y * 2;
        sfSprite_setTextureRect(all->win[i].sprite,
        all->win[i].rect);
    } else if (overlay_check(&all->win[i], all) == sfTrue) {
        all->win[i].rect.top = all->win[i].size.y;
        sfSprite_setTextureRect(all->win[i].sprite,
        all->win[i].rect);
    } else {
        all->win[i].rect.top = 0;
        sfSprite_setTextureRect(all->win[i].sprite,
        all->win[i].rect);
    }
}

void overlay_win(all_t *all)
{
    for (int i = 1; i < INDEX_WIN - 1; i += 1) {
        check_overlay_win(all, i);
    }
}

void event_more(all_t *all)
{
    if (all->use[1] == sfFalse)
        init_option(all);
}

void event_win_bis(all_t *all)
{
    if (click_check(all) == sfTrue)
        all->mouse = sfMouse_getPositionRenderWindow(all->window);
    if (release_check(all, &all->win[1]) == sfTrue)
        sfRenderWindow_close(all->window);
    if (release_check(all, &all->win[3]) == sfTrue) {
        event_more(all);
        change_scene(all, OPTION);
    }
}

void event_win(all_t *all)
{
    while (sfRenderWindow_pollEvent(all->window, &all->event)) {
        event_win_bis(all);
        if (release_check(all, &all->win[2]) == sfTrue) {
            change_scene(all, MENU);
            reset(all);
        }
        overlay_win(all);
    }
}
