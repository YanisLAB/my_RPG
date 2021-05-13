/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** event.c
*/

#include "../../include/my_rpg.h"

void event_main_menu_more(all_t *all)
{
    if (release_check(all, &all->button[0]) == sfTrue) {
        if (all->world.read_map == sfFalse)
            get_world(&all->world, "assets/map/file");
        if (all->use[5] == sfFalse)
            init_player(all);
        sfMusic_play(all->music_game);
        open_save(all);
        change_scene(all, GAME);
    }
}

void event_main_menu_bis(all_t *all)
{
    if (release_check(all, &all->button[2]) == sfTrue) {
        pos_key(all, 0);
        change_scene(all, HELP);
    }
    if (release_check(all, &all->button[3]) == sfTrue) {
        pos_key(all, 1);
        change_scene(all, OPTION);
    }
    if (release_check(all, &all->button[4]) == sfTrue) {
        if (all->world.read_map == sfFalse)
            get_world(&all->world, "assets/map/file");
        if (all->use[5] == sfFalse)
            init_player(all);
        sfMusic_play(all->music_game);
        change_scene(all, CIN);
    }
    event_main_menu_more(all);
}

void event_main_menu(all_t *all)
{
    while (sfRenderWindow_pollEvent(all->window, &all->event)) {
        if (click_check(all) == sfTrue)
            all->mouse = sfMouse_getPositionRenderWindow(all->window);
        if (all->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
            sfRenderWindow_close(all->window);
        if (release_check(all, &all->button[1]) == sfTrue)
            sfRenderWindow_close(all->window);
        event_main_menu_bis(all);
        overlay_main_menu(all);
    }
}

void overlay_main_menu_bis(all_t *all, int i)
{
    if (overlay_check(&all->button[i], all) == sfTrue &&
    click_check(all) == sfTrue) {
        sfSound_play(all->click.sound);
        all->button[i].rect.top = all->button[i].size.y * 2;
        sfSprite_setTextureRect(all->button[i].sprite,
        all->button[i].rect);
    } else if (overlay_check(&all->button[i], all) == sfTrue) {
        all->button[i].rect.top = all->button[i].size.y;
        sfSprite_setTextureRect(all->button[i].sprite,
        all->button[i].rect);
    } else {
        all->button[i].rect.top = 0;
        sfSprite_setTextureRect(all->button[i].sprite,
        all->button[i].rect);
    }
}

void overlay_main_menu(all_t *all)
{
    for (int i = 0; i < INDEX_BUTTON; i++) {
        overlay_main_menu_bis(all, i);
    }
}