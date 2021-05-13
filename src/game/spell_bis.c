/*
** EPITECH PROJECT, 2020
** my_rpg1
** File description:
** spell_bis.c
*/

#include "../../include/my_rpg.h"

void even_spellb(all_t *all)
{
    if (((all->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyNum2) == 1) ||
    sfJoystick_isButtonPressed(0, 7) == sfTrue) && all->colspell2 == 0 &&
    all->p.mana >= 100) {
        set_pos(&all->spelloverlay[3], 692, 1005);
        spell_two(all);
        add_particle(&all->particle_environment_bis, all->particle_bis, 25, pp);
        all->s = 2;
        all->colpart[1] = 2;
    }
}