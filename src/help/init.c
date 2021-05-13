/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-yanis.labchiri
** File description:
** init_main_help.c
*/

#include "../../include/my_rpg.h"

void setpos_help(all_t *all)
{
    set_pos(&all->help[3], 50, 940);
    set_pos(&all->help[4], 1640, 940);
    set_pos(&all->help[5], 1710, 50);
    for (int i = 0; i < INDEX_HELP; i++) {
        all->help[i].size = sfTexture_getSize(all->help[i].texture);
        all->help[i].size.y /= 3;
    }
}

void pos_key(all_t *all, int type)
{
    if (type == 0) {
        all->touch[0].position = (sfVector2f) {1290, 435};
        all->touch[1].position = (sfVector2f) {167, 440};
        all->touch[2].position = (sfVector2f) {325, 440};
        all->touch[3].position = (sfVector2f) {245, 440};
        all->touch[4].position = (sfVector2f) {245, 350};
    }
    if (type == 1) {
        all->touch[0].position = (sfVector2f) {710, 405};
        all->touch[1].position = (sfVector2f) {805, 480};
        all->touch[2].position = (sfVector2f) {910, 408};
        all->touch[3].position = (sfVector2f) {1005, 480};
        all->touch[4].position = (sfVector2f) {1105, 410};
    }
    for (int i = 0; i < 5; i++)
        sfText_setPosition(all->touch[i].text, all->touch[i].position);
}

void init_help(all_t *all)
{
    all->use[8] = sfTrue;
    all->help_page = 0;
    all->help[0] = init_sprite(
    (sfIntRect) {0, 0, 1920, 1080}, "assets/help/help1.jpg");
    all->help[1] = init_sprite(
    (sfIntRect) {0, 0, 1920, 1080}, "assets/help/help2.jpg");
    all->help[2] = init_sprite(
    (sfIntRect) {0, 0, 1920, 1080}, "assets/help/help3.jpg");
    all->help[3] = init_sprite(
    (sfIntRect) {0, 0, 230, 94}, "assets/help/before.png");
    all->help[4] = init_sprite(
    (sfIntRect) {0, 0, 230, 94}, "assets/help/next.png");
    all->help[5] = init_sprite(
    (sfIntRect) {0, 0, 160, 155}, "assets/pause/home.png");
    setpos_help(all);
}

void display_help(all_t *all)
{
    if (all->help_page == 0) {
        display_sprite(all->window, &all->help[0], 0, 0);
        display_sprite(all->window, &all->help[4], 0, 0);
    }
    if (all->help_page == 1) {
        display_sprite(all->window, &all->help[1], 0, 0);
        display_sprite(all->window, &all->help[3], 0, 0);
        display_sprite(all->window, &all->help[4], 0, 0);
        for (int i = 0; i < TOUCH; i++) {
            sfRenderWindow_drawText(all->window, all->touch[i].text, NULL);
            sfText_setString(all->touch[i].text, all->touch[i].str);
        }
    }
    if (all->help_page == 2) {
        display_sprite(all->window, &all->help[2], 0, 0);
        display_sprite(all->window, &all->help[3], 0, 0);
    }
    display_sprite(all->window, &all->help[5], 0, 0);
}

void destroy_help(all_t *all)
{
    for (int i = 0; i < INDEX_HELP; i++)
        destroy_sprite(&all->help[i]);
}