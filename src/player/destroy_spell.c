/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** destroy_spell.c
*/

#include "../../include/my_rpg.h"

void destroy_cooldown(all_t *all)
{
    sfText_destroy(all->p.lvl.text);
    sfFont_destroy(all->p.lvl.my_font);
    for (int i = 0; i < 4; i++) {
        sfText_destroy(all->spell[i].cooldown.text);
        sfFont_destroy(all->spell[i].cooldown.my_font);
        sfText_destroy(all->spell_lvl[i].text);
        sfFont_destroy(all->spell_lvl[i].my_font);
    }
    sfClock_destroy(all->coll.clock);
}