/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** init_win.c
*/

#include "../../include/my_rpg.h"

void set_pos_win(all_t *all)
{
    set_pos(&all->win[1], 849, 571);
    set_pos(&all->win[2], 1099, 730);
    set_pos(&all->win[3], 674, 730);
    set_pos(&all->win[4], 836, 411);
    for (int i = 0; i < INDEX_WIN; i++) {
        all->win[i].size = sfTexture_getSize(all->win[i].texture);
        all->win[i].size.y /= 3;
    }
}

void init_win_text(all_t *all)
{
    time_str(all->time_play.str, all->time_play.nbr);
    all->time_play.text = sfText_create();
    all->time_play.my_font = sfFont_createFromFile("assets/Alamak.ttf");
    sfText_setFont(all->time_play.text, all->time_play.my_font);
    sfText_setString(all->time_play.text, all->time_play.str);
    sfText_setColor(all->time_play.text, sfWhite);
    sfText_setCharacterSize(all->time_play.text, 20);
    sfText_setOutlineColor(all->time_play.text, sfBlack);
    sfText_setOutlineThickness(all->time_play.text, 1);
    all->time_play.position.x = 900;
    all->time_play.position.y = 480;
    sfText_setPosition(all->time_play.text, all->time_play.position);
}

void init_win(all_t *all)
{
    all->use[4] = sfTrue;
    all->win[0] = init_sprite(
    (sfIntRect) {0, 0, 1920, 1080}, "assets/end/win.png");
    all->win[1] = init_sprite(
    (sfIntRect) {0, 0, 230, 94}, "assets/pause/quit.png");
    all->win[2] = init_sprite(
    (sfIntRect) {0, 0, 160, 155}, "assets/pause/home.png");
    all->win[3] = init_sprite(
    (sfIntRect) {0, 0, 160, 155}, "assets/menu_button/params.png");
    all->win[4] = init_sprite(
    (sfIntRect) {0, 0, 248, 58}, "assets/end/time_played.png");
    init_win_text(all);
    set_pos_win(all);
}

void display_win(all_t *all)
{
    display_sprite(all->window, &all->map[0], 0, 0);
    display_sprite(all->window, &all->map[1], 0, 0);
    for (int i = 0; i < INDEX_WIN; i += 1)
        display_sprite(all->window, &all->win[i], 0, 0);
    sfRenderWindow_drawText(all->window, all->time_play.text, NULL);
}

void destroy_win(all_t *all)
{
    for (int i = 0; i < INDEX_WIN; i += 1)
        destroy_sprite(&all->win[i]);
}