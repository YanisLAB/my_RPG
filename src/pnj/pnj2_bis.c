/*
** EPITECH PROJECT, 2020
** rpg2
** File description:
** pnj2_bis.c
*/

#include "../../include/my_rpg.h"

void pnj2_bis(all_t *all)
{
    if (all->quest == 3) {
        if ((all->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEnter) == 1) ||
        sfJoystick_isButtonPressed(0, 1) == sfTrue) {
            all->p.xp += 200;
            all->quest += 1;
            all->dial = false;
        }
    } else
        blabla2(all);
}

void pnj2_if(all_t *all)
{
    if ((all->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyEnter) == 1) ||
    sfJoystick_isButtonPressed(0, 1) == sfTrue) {
        delet_badge(&all->inventory);
        all->p.xp += 200;
        all->quest += 1;
        all->dial = false;
    }
}

void pnj2_condition(all_t *all)
{
    if ((all->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyEnter) == 1) ||
    sfJoystick_isButtonPressed(0, 1) == sfTrue) {
        all->p.xp += 10;
        all->quest += 1;
        all->dial = false;
    }
}