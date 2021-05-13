/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-yanis.labchiri
** File description:
** init_main_button.c
*/

#include "../../include/my_rpg.h"

void set_position(all_t *all)
{
    all->logo = init_sprite(
    (sfIntRect) {0, 0, 500, 500}, "assets/logo.png");
    set_pos(&all->logo, 305, 233);
    set_pos(&all->button[0], 1100, 400);
    set_pos(&all->button[1], 1700, 900);
    set_pos(&all->button[2], 10, 10);
    set_pos(&all->button[3], 10, 900);
    set_pos(&all->button[4], 1100, 500);
    for (int i = 0; i < INDEX_BUTTON; i++) {
        all->button[i].size = sfTexture_getSize(all->button[i].texture);
        all->button[i].size.y /= 3;
    }
}

void init_main_menu(all_t *all)
{
    all->button[0] = init_sprite(
    (sfIntRect) {0, 0, 230, 94}, "assets/menu_button/continue.png");
    all->button[1] = init_sprite(
    (sfIntRect) {0, 0, 160, 155}, "assets/menu_button/exit.png");
    all->button[2] = init_sprite(
    (sfIntRect) {0, 0, 160, 155}, "assets/menu_button/help.png");
    all->button[3] = init_sprite(
    (sfIntRect) {0, 0, 160, 155}, "assets/menu_button/params.png");
    all->button[4] = init_sprite(
    (sfIntRect) {0, 0, 230, 94}, "assets/menu_button/new_games.png");
    all->parrallax[0] = init_sprite(
    (sfIntRect) {0, 0, 1920, 1080}, "assets/parralax/parallax0.png");
    all->parrallax[1] = init_sprite(
    (sfIntRect) {0, 0, 1920, 1080}, "assets/parralax/parallax1.png");
    all->parrallax[2] = init_sprite(
    (sfIntRect) {0, 0, 1920, 1080}, "assets/parralax/parallax2.png");
    all->parrallax[3] = init_sprite(
    (sfIntRect) {0, 0, 1920, 1080}, "assets/parralax/parallax3.png");
    set_position(all);
}