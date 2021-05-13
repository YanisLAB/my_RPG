/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** joystick.c
*/

#include "../../include/my_rpg.h"

void joystick_movement_bis(all_t *all)
{
    if ((sfJoystick_getAxisPosition(0, sfJoystickX) < -40 &&
    sfJoystick_getAxisPosition(0, sfJoystickY) > -3 &&
    sfJoystick_getAxisPosition(0, sfJoystickY) < 3)
    && check_pos_player(all, 0, -8) == sfTrue) {
        move_player(all, 582, 143);
        move_map_rect(all, -8, 0);
    } else if ((sfJoystick_getAxisPosition(0, sfJoystickX) > 40 &&
    sfJoystick_getAxisPosition(0, sfJoystickY) > -3 &&
    sfJoystick_getAxisPosition(0, sfJoystickY) < 3)
    && check_pos_player(all, 0, 8) == sfTrue) {
        move_player(all, 715, 175);
        move_map_rect(all, 8, 0);
    }
}

void joystick_time(all_t *all)
{
    all->controller.time = sfClock_getElapsedTime(all->controller.clock);
    all->controller.sec = all->controller.time.microseconds / 1000000.0;
    all->time_joy.time = sfClock_getElapsedTime(all->time_joy.clock);
    all->time_joy.sec = all->time_joy.time.microseconds / 1000000.0;
    if (sfJoystick_isButtonPressed(0, 8) == sfTrue && all->event.type ==
    sfEvtJoystickButtonPressed && all->time_joy.sec > 0.5) {
        all->invent = !all->invent;
        sfClock_restart(all->time_joy.clock);
    }
}

void joystick_movement(all_t *all)
{
    joystick_time(all);
    if (sfJoystick_isConnected(0) == sfTrue && all->controller.sec > 0.02) {
        if ((sfJoystick_getAxisPosition(0, sfJoystickY) < -40 &&
        sfJoystick_getAxisPosition(0, sfJoystickX) > -3 &&
        sfJoystick_getAxisPosition(0, sfJoystickX) < 3)
        && check_pos_player(all, -8, 0) == sfTrue) {
            move_player(all, 520, 127);
            move_map_rect(all, 0, -8);
        } else if ((sfJoystick_getAxisPosition(0, sfJoystickY) > 40 &&
        sfJoystick_getAxisPosition(0, sfJoystickX) > -3 &&
        sfJoystick_getAxisPosition(0, sfJoystickX) < 3)
        && check_pos_player(all, 8, 0) == sfTrue) {
            move_player(all, 650, 159);
            move_map_rect(all, 0, 8);
        } else
            joystick_movement_bis(all);
        for (int i = 0; i < INDEX_PNJ; i++)
            sfSprite_setPosition(all->pnj[i].sprite, all->pnj[i].position);
        sfClock_restart(all->controller.clock);
    }
}