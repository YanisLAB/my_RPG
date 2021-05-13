/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** event.c
*/

#include "../../include/my_rpg.h"

void event_cine(all_t *all)
{
    while (sfRenderWindow_pollEvent(all->window, &all->event)) {
        if (all->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape) == 1)
            sfRenderWindow_close(all->window);
        if (((all->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEnter) == 1) ||
        sfJoystick_isButtonPressed(0, 1) == sfTrue)) {
            change_scene(all, GAME);
        }
    }
}