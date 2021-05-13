/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** display.c
*/

#include "../../include/my_rpg.h"

void display(all_t *all)
{
    if (all->scene == MENU)
        display_main_menu(all);
    if (all->scene == GAME)
        display_map(all);
    if (all->scene == OPTION)
        display_option(all);
    if (all->scene == PAUSE)
        display_pause(all);
    if (all->scene == CIN)
        cine(all);
    if (all->scene == DEAD)
        display_lose(all);
    if (all->scene == WIN)
        display_win(all);
    if (all->scene == HELP)
        display_help(all);
}