/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-yanis.labchiri
** File description:
** init.c
*/

#include "../../include/my_rpg.h"

void set_pos_setting(all_t *all)
{
    set_pos(&all->option[1], 775, 587);
    set_pos(&all->option[2], 774, 652);
    set_pos(&all->option[3], 881, 723);
    set_pos(&all->option[4], 1150, 585);
    set_pos(&all->option[5], 720, 585);
    set_pos(&all->option[6], 1150, 650);
    set_pos(&all->option[7], 720, 650);
    for (int i = 3; i < INDEX_OPTION; i++) {
        all->option[i].size = sfTexture_getSize(all->option[i].texture);
        all->option[i].size.y /= 3;
    }
}

text_t init_t(int x, int y, char c)
{
    text_t tmp;
    tmp.str[0] = c;
    tmp.str[1] = '\0';
    tmp.my_font = sfFont_createFromFile("assets/arial.ttf");
    tmp.text = sfText_create();
    sfText_setString(tmp.text, tmp.str);
    sfText_setFont(tmp.text, tmp.my_font);
    sfText_setCharacterSize(tmp.text, 50);
    sfText_setColor(tmp.text, sfWhite);
    sfText_setOutlineColor(tmp.text, sfBlack);
    sfText_setOutlineThickness(tmp.text, 1);
    tmp.position.x = x;
    tmp.position.y = y;
    sfText_setPosition(tmp.text, tmp.position);
    return (tmp);
}

void init_text(all_t *all)
{
    all->touch[0] = init_t(710, 405, 'e');
    all->touch[1] = init_t(805, 480, 'a');
    all->touch[2] = init_t(910, 408, 'd');
    all->touch[3] = init_t(1005, 480, 's');
    all->touch[4] = init_t(1105, 410, 'w');
}

void init_option(all_t *all)
{
    all->use[1] = sfTrue;
    all->option[0] = init_sprite(
    (sfIntRect) {0, 0, 1920, 1080}, "assets/option/option.png");
    all->option[1] = init_sprite(
    (sfIntRect) {0, 0, 36, 38}, "assets/option/barre.png");
    all->option[2] = init_sprite(
    (sfIntRect) {0, 0, 90, 38}, "assets/option/barre.png");
    all->option[3] = init_sprite(
    (sfIntRect) {0, 0, 155, 88}, "assets/option/exit_option.png");
    all->option[4] = init_sprite(
    (sfIntRect) {0, 0, 45, 41}, "assets/option/+.png");
    all->option[5] = init_sprite(
    (sfIntRect) {0, 0, 45, 41}, "assets/option/-.png");
    all->option[6] = init_sprite(
    (sfIntRect) {0, 0, 45, 41}, "assets/option/+.png");
    all->option[7] = init_sprite(
    (sfIntRect) {0, 0, 45, 41}, "assets/option/-.png");
    set_pos_setting(all);
    init_text(all);
}