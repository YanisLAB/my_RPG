/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** attack.c
*/

#include "../../include/my_rpg.h"

void spell_one(all_t *all)
{
    float coef =  0.8 + (float)all->spell_lvl[0].nbr / 5;
    mob_z_t *tmp1 = all->mob_z1;
    while (tmp1) {
        if (get_distance(tmp1->mobs.mob.position.x,
        tmp1->mobs.mob.position.y, pp.x, pp.y) < all->spell[0].range)
            tmp1->life -= all->spell[0].damage * coef;
        tmp1 = tmp1->next;
    }
    for (int i = 0; i < INDEX_BOSS; i += 1) {
        if (get_distance(all->boss[i].boss.position.x,
        all->boss[i].boss.position.y, pp.x, pp.y) < all->spell[0].range)
            all->boss[i].life -= all->spell[0].damage * coef;
    }
    if (get_distance(all->boss_f.boss.position.x,
    all->boss_f.boss.position.y, pp.x, pp.y) < 50)
        all->boss_f.life -= all->spell[0].damage * coef;
    all->colspell1 = all->spell[0].cooldown.nbr;
    all->p.mana -= 100;
    update_life(all);
}

void spell_two(all_t *all)
{
    float coef =  0.8 + (float)all->spell_lvl[1].nbr / 5;
    mob_z_t *tmp1 = all->mob_z1;
    while (tmp1) {
        if (get_distance(tmp1->mobs.mob.position.x,
        tmp1->mobs.mob.position.y, pp.x, pp.y) < all->spell[1].range)
            tmp1->life -= all->spell[1].damage * coef;
        tmp1 = tmp1->next;
    }
    for (int i = 0; i < INDEX_BOSS; i += 1) {
        if (get_distance(all->boss[i].boss.position.x,
        all->boss[i].boss.position.y, pp.x, pp.y) < all->spell[1].range)
            all->boss[i].life -= all->spell[1].damage * coef;
    }
    if (get_distance(all->boss_f.boss.position.x,
    all->boss_f.boss.position.y, pp.x, pp.y) < 50)
        all->boss_f.life -= all->spell[1].damage * coef;
    all->colspell2 = all->spell[1].cooldown.nbr;
    all->p.mana -= 100;
    update_life(all);
}

void spell_tree(all_t *all)
{
    float coef =  0.8 + (float)all->spell_lvl[2].nbr / 5;
    if (all->p.mana <= all->p.max_mana - (all->spell[2].damage * coef))
        all->p.mana += all->spell[2].damage * coef;
    else
        all->p.mana = all->p.max_mana;
    all->colspell3 = all->spell[2].cooldown.nbr;
    update_life(all);
}

void spell_four(all_t *all)
{
    float coef =  0.8 + (float)all->spell_lvl[3].nbr / 5;
    if (all->p.life <= all->p.max_hp - (all->spell[3].damage * coef))
        all->p.life += all->spell[3].damage * coef;
    else
        all->p.life = all->p.max_hp;
    all->colspell4 = all->spell[3].cooldown.nbr;
    all->p.mana -= 100;
    update_life(all);
}

void attack(all_t *all)
{
    mob_z_t *tmp1 = all->mob_z1;

    while (tmp1) {
        if (get_distance(tmp1->mobs.mob.position.x,
        tmp1->mobs.mob.position.y, pp.x, pp.y) < 100)
            tmp1->life -= all->p.attack;
        tmp1 = tmp1->next;
    }
    for (int i = 0; i < INDEX_BOSS; i += 1) {
        if (get_distance(all->boss[i].boss.position.x,
        all->boss[i].boss.position.y, pp.x, pp.y) < 100)
            all->boss[i].life -= all->p.attack;
    }
    if (get_distance(all->boss_f.boss.position.x,
    all->boss_f.boss.position.y, pp.x, pp.y) < 200)
        all->boss_f.life -= all->p.attack;
    all->collattack = 1;
}