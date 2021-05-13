/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** event.c
*/

#include "../../include/my_rpg.h"

void overlay_pause_bis(all_t *all, int i)
{
    if (overlay_check(&all->pause[i], all) == sfTrue &&
    click_check(all) == sfTrue) {
        sfSound_play(all->click.sound);
        all->pause[i].rect.top = all->pause[i].size.y * 2;
        sfSprite_setTextureRect(all->pause[i].sprite,
        all->pause[i].rect);
    } else if (overlay_check(&all->pause[i], all) == sfTrue) {
        all->pause[i].rect.top = all->pause[i].size.y;
        sfSprite_setTextureRect(all->pause[i].sprite,
        all->pause[i].rect);
    } else {
        all->pause[i].rect.top = 0;
        sfSprite_setTextureRect(all->pause[i].sprite,
        all->pause[i].rect);
    }
}

void overlay_pause(all_t *all)
{
    for (int i = 1; i < INDEX_PAUSE; i += 1)
        overlay_pause_bis(all, i);
}

void event_pause_bis(all_t *all)
{
    if (click_check(all) == sfTrue)
        all->mouse = sfMouse_getPositionRenderWindow(all->window);
    if (release_check(all, &all->pause[1]) == sfTrue)
        sfRenderWindow_close(all->window);
    if (release_check(all, &all->pause[5]) == sfTrue) {
        if (all->use[1] == sfFalse)
            init_option(all);
        change_scene(all, OPTION);
    }
    if (release_check(all, &all->pause[3]) == sfTrue)
        write_save(all);
}

void event_pause(all_t *all)
{
    while (sfRenderWindow_pollEvent(all->window, &all->event)) {
        event_pause_bis(all);
        if (release_check(all, &all->pause[4]) == sfTrue) {
            change_scene(all, MENU);
            reset(all);
        }
        if (release_check(all, &all->pause[2]) == sfTrue)
            change_scene(all, GAME);
        overlay_pause(all);
    }
}
