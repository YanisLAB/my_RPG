/*
** EPITECH PROJECT, 2020
** my_rpg1
** File description:
** spell_coll.c
*/

#include "../../include/my_rpg.h"

void display_coll_spell4(all_t *all)
{
    if (all->colspell4 > 0) {
        all->spell[3].cooldown.position.x = 820;
        all->spell[3].cooldown.position.y = 1020;
        sfText_setPosition(all->spell[3].cooldown.text,
        all->spell[3].cooldown.position);
        my_int_str(all->spell[3].cooldown.str, all->colspell4);
        sfText_setString(all->spell[3].cooldown.text,
        all->spell[3].cooldown.str);
        sfRenderWindow_drawText(all->window, all->spell[3].cooldown.text,
        NULL);
    }
}

void display_coll_spell3(all_t *all)
{
    if (all->colspell3 > 0) {
        all->spell[2].cooldown.position.x = 760;
        all->spell[2].cooldown.position.y = 1020;
        sfText_setPosition(all->spell[2].cooldown.text,
        all->spell[2].cooldown.position);
        my_int_str(all->spell[2].cooldown.str, all->colspell3);
        sfText_setString(all->spell[2].cooldown.text,
        all->spell[2].cooldown.str);
        sfRenderWindow_drawText(all->window, all->spell[2].cooldown.text,
        NULL);
    }
    display_coll_spell4(all);
}

void display_coll_spell2(all_t *all)
{
    if (all->colspell2 > 0) {
        all->spell[1].cooldown.position.x = 705;
        all->spell[1].cooldown.position.y = 1020;
        sfText_setPosition(all->spell[1].cooldown.text,
        all->spell[1].cooldown.position);
        my_int_str(all->spell[1].cooldown.str, all->colspell2);
        sfText_setString(all->spell[1].cooldown.text,
        all->spell[1].cooldown.str);
        sfRenderWindow_drawText(all->window, all->spell[1].cooldown.text,
        NULL);
    }
    display_coll_spell3(all);
}

void display_coll(all_t *all)
{
    if (all->colspell1 > 0) {
        all->spell[0].cooldown.position.x = 640;
        all->spell[0].cooldown.position.y = 1020;
        sfText_setPosition(all->spell[0].cooldown.text,
        all->spell[0].cooldown.position);
        my_int_str(all->spell[0].cooldown.str, all->colspell1);
        sfText_setString(all->spell[0].cooldown.text,
        all->spell[0].cooldown.str);
        sfRenderWindow_drawText(all->window, all->spell[0].cooldown.text,
        NULL);
    }
    display_coll_spell2(all);
}