/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** event.c
*/

#include "../../include/my_rpg.h"

void event_helpb(all_t *all)
{
        if (release_check(all, &all->help[3]) == sfTrue
        && (all->help_page == 1 || all->help_page == 2)) {
            all->help_page -= 1;
        }
        if (release_check(all, &all->help[4]) == sfTrue
        && (all->help_page == 0 || all->help_page == 1)) {
            all->help_page += 1;
        }
        if (release_check(all, &all->help[5]) == sfTrue)
            change_scene(all, all->last_scene);
        overlay_help(all);
}

void event_help(all_t *all)
{
    while (sfRenderWindow_pollEvent(all->window, &all->event)) {
        if (click_check(all) == sfTrue)
            all->mouse = sfMouse_getPositionRenderWindow(all->window);
        if (all->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
            sfRenderWindow_close(all->window);
        event_helpb(all);
    }
}

void overlay_help_b(all_t *all, int i)
{
    if (overlay_check(&all->help[i], all) == sfTrue &&
    click_check(all) == sfTrue) {
        sfSound_play(all->click.sound);
        all->help[i].rect.top = all->help[i].size.y * 2;
        sfSprite_setTextureRect(all->help[i].sprite,
        all->help[i].rect);
    } else if (overlay_check(&all->help[i], all) == sfTrue) {
        all->help[i].rect.top = all->help[i].size.y;
        sfSprite_setTextureRect(all->help[i].sprite,
        all->help[i].rect);
    } else {
        all->help[i].rect.top = 0;
        sfSprite_setTextureRect(all->help[i].sprite,
        all->help[i].rect);
    }
}

void overlay_help(all_t *all)
{
    for (int i = 3; i < INDEX_HELP; i++)
        overlay_help_b(all, i);
}