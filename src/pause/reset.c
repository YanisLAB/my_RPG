/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** reset.c
*/

#include "../../include/my_rpg.h"

void reset_bis(all_t *all)
{
    all->colspell1 = 0;
    all->colspell2 = 0;
    all->colspell3 = 0;
    all->colspell4 = 0;
    all->dial = false;
    init_map(all);
    init_inv(all);
    init_player(all);
    init_music(all);
    init_all_mobs(all);
    init_boss(all);
    init_pnj(all);
}

void reset(all_t *all)
{
    destroy_inventory(all);
    destroy_boss(all);
    sfMusic_stop(all->music_game);
    destroy_sound(all);
    destroy_player(all);
    destroy_map(all);
    destroy_mob(all);
    all->scene = 0;
    all->last_scene = 0;
    all->keys.change = 0;
    all->controller.sec = 0;
    all->time_joy.sec = 0;
    all->quest = 0;
    for (int i = 0; i < INDEX_SPELL; i++) {
        all->spell_lvl[i].nbr = 1;
        my_int_str(all->spell_lvl[i].str, all->spell_lvl[i].nbr);
        sfText_setString(all->spell_lvl[i].text, all->spell_lvl[i].str);
    }
    reset_bis(all);
}