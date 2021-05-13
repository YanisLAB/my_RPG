/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-yanis.labchiri
** File description:
** event.c
*/

#include "../../include/my_rpg.h"

void event_all(all_t *all)
{
    if (all->scene == MENU)
        event_main_menu(all);
    if (all->scene == GAME)
        event_game(all);
    if (all->scene == OPTION)
        event_option(all);
    if (all->scene == HELP)
        event_help(all);
    if (all->scene == PAUSE)
        event_pause(all);
    if (all->scene == CIN)
        event_cine(all);
    if (all->scene == DEAD)
        event_lose(all);
    if (all->scene == WIN)
        event_win(all);
    if (all->scene == HELP)
        event_help(all);
}