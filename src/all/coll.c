/*
** EPITECH PROJECT, 2020
** rpg2
** File description:
** coll.c
*/

#include "../../include/my_rpg.h"

void act_collbis(all_t *all)
{
    if (all->collattack > 0)
        all->collattack -= 1;
    if (all->colspell1 > 0)
        all->colspell1 -= 1;
    if (all->colspell2 > 0)
        all->colspell2 -= 1;
    if (all->colspell3 > 0)
        all->colspell3 -= 1;
    if (all->colspell4 > 0)
        all->colspell4 -= 1;
    if (all->p.mana < all->p.max_mana + 2)
        all->p.mana += 2;
    else
        all->p.mana = all->p.max_mana;
}

void act_coll(all_t *all)
{
    if (all->p.life < all->p.max_hp + 2)
        all->p.life += 2;
    else
        all->p.life = all->p.max_hp;
    if (all->boss_f.life <= 300 && all->boss_f.regen == 0) {
        all->boss_f.life = 1000;
        all->boss_f.regen = 1;
    }
    for (int i = 0; i < 4; i += 1) {
        if (all->colpart[i] > 0)
            all->colpart[i] -= 1;
    }
    all->time_play.nbr += 1;
    act_collbis(all);
    if (all->use[5] == sfTrue)
        update_life(all);
    sfClock_restart(all->coll.clock);
}