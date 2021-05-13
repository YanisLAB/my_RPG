/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-yanis.labchiri
** File description:
** event.c
*/

#include "../../include/my_rpg.h"

void key_change_bis(all_t *all)
{
    if (all->event.key.type == sfEvtKeyPressed && all->keys.change == 4 &&
    all->event.key.code >= 0 && all->event.key.code <= 26) {
        all->keys.down = all->event.key.code;
        all->touch[3].str[0] = all->event.key.code + 97;
    }
    if (all->event.key.type == sfEvtKeyPressed && all->keys.change == 5 &&
    all->event.key.code >= 0 && all->event.key.code <= 26) {
        all->keys.up = all->event.key.code;
        all->touch[4].str[0] = all->event.key.code + 97;
    }
    if (all->event.key.type == sfEvtKeyPressed &&
    all->event.key.code >= 0 && all->event.key.code <= 26)
        all->keys.change = 0;
}

void key_change(all_t *all)
{
    if (all->event.key.type == sfEvtKeyPressed && all->keys.change == 1 &&
    all->event.key.code >= 0 && all->event.key.code <= 26) {
        all->keys.inv = all->event.key.code;
        all->touch[0].str[0] = all->event.key.code + 97;
    }
    if (all->event.key.type == sfEvtKeyPressed && all->keys.change == 2 &&
    all->event.key.code >= 0 && all->event.key.code <= 26) {
        all->keys.left = all->event.key.code;
        all->touch[1].str[0] = all->event.key.code + 97;
    }
    if (all->event.key.type == sfEvtKeyPressed && all->keys.change == 3 &&
    all->event.key.code >= 0 && all->event.key.code <= 26) {
        all->keys.right = all->event.key.code;
        all->touch[2].str[0] = all->event.key.code + 97;
    }
    key_change_bis(all);
}

void change_key(all_t *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->window);
    if (all->keys.change != 0) {
        key_change(all);
    } else {
        if ((696 <= mouse.x && 754 >= mouse.x) &&
        (411 <= mouse.y && 467 >= mouse.y) && click_check(all) == sfTrue)
            all->keys.change = 1;
        if ((786 <= mouse.x && 844 >= mouse.x) &&
        (488 <= mouse.y && 545 >= mouse.y) && click_check(all) == sfTrue)
            all->keys.change = 2;
        if ((895 <= mouse.x && 953 >= mouse.x) &&
        (411 <= mouse.y && 467 >= mouse.y) && click_check(all) == sfTrue)
            all->keys.change = 3;
        if ((985 <= mouse.x && 1044 >= mouse.x) &&
        (488 <= mouse.y && 545 >= mouse.y) && click_check(all) == sfTrue)
            all->keys.change = 4;
        if ((1092 <= mouse.x && 1150 >= mouse.x) &&
        (411 <= mouse.y && 467 >= mouse.y) && click_check(all) == sfTrue)
            all->keys.change = 5;
    }
}

void event_option(all_t *all)
{
    while (sfRenderWindow_pollEvent(all->window, &all->event)) {
        if (click_check(all) == sfTrue)
            all->mouse = sfMouse_getPositionRenderWindow(all->window);
        if (all->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
            sfRenderWindow_close(all->window);
        if (release_check(all, &all->option[3]) == sfTrue)
            change_scene(all, all->last_scene);
        for (int i = 1; i <= 4; i++) {
            if (release_check(all, &all->option[3 + i]) == sfTrue)
                music_volume(all, i);
        }
        overlay_option(all);
        change_key(all);
    }
}

void overlay_option(all_t *all)
{
    for (int i = 3; i < INDEX_OPTION; i++) {
        if (overlay_check(&all->option[i], all) == sfTrue &&
        click_check(all) == sfTrue) {
            sfSound_play(all->click.sound);
            all->option[i].rect.top = all->option[i].size.y * 2;
            sfSprite_setTextureRect(all->option[i].sprite,
            all->option[i].rect);
        } else if (overlay_check(&all->option[i], all) == sfTrue) {
            all->option[i].rect.top = all->option[i].size.y;
            sfSprite_setTextureRect(all->option[i].sprite,
            all->option[i].rect);
        } else {
            all->option[i].rect.top = 0;
            sfSprite_setTextureRect(all->option[i].sprite,
            all->option[i].rect);
        }
    }
}