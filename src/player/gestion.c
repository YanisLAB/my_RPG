/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** gestion.c
*/

#include "../../include/my_rpg.h"

void destroy_player(all_t *all)
{
    destroy_sprite(&all->p.player);
    for (int i = 0; i < INDEX_PNJ; i += 1)
        destroy_sprite(&all->pnj[i]);
    for (int i = 0; i < INDEX_SPELL; i++)
        destroy_sprite(&all->spelloverlay[i]);
}

void update_life_bossf(all_t *all)
{
    float ratio_life = (float)993 / (float)all->boss_f.life_max;

    all->boss_f.bar_life.rect.width = ratio_life * all->boss_f.life;
}

void update_life(all_t *all)
{
    float ratio_xp = 196 / (float) all->p.max_xp;
    float ratio_hp = 233 / (float) all->p.max_hp;
    float ratio_mana = 233 / (float) all->p.max_mana;
    if (all->p.xp >= all->p.max_xp) {
        all->p.xp -= all->p.max_xp;
        all->p.lvl.nbr += 1;
        all->p.point += 1;
        all->p.max_xp += 10;
        ratio_xp = 196 / all->p.max_xp;
        my_int_str(all->p.lvl.str, all->p.lvl.nbr);
        sfText_setString(all->p.lvl.text, all->p.lvl.str);
    }
    all->spelloverlay[0].rect.width = ratio_hp * all->p.life;
    all->spelloverlay[1].rect.width = ratio_mana * all->p.mana;
    all->inventory_s[1].rect.width = ratio_xp * all->p.xp;
    if (all->use[8] == sfTrue)
        update_life_bossf(all);
}