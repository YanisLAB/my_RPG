/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** event_game.c
*/

#include "../../include/my_rpg.h"

void move_player_check_bis(all_t *all)
{
    if ((all->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(all->keys.left) == 1)
    && check_pos_player(all, 0, -8) == sfTrue) {
        move_player(all, 582, 143);
        move_map_rect(all, -8, 0);
    } else if ((all->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(all->keys.right) == 1)
    && check_pos_player(all, 0, 8) == sfTrue) {
        move_player(all, 715, 175);
        move_map_rect(all, 8, 0);
    }
}

void move_player_check(all_t *all)
{
    if ((all->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(all->keys.up) == 1)
    && check_pos_player(all, -8, 0) == sfTrue) {
        move_player(all, 520, 127);
        move_map_rect(all, 0, -8);
    } else if ((all->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(all->keys.down) == 1)
    && check_pos_player(all, 8, 0) == sfTrue) {
        move_player(all, 650, 159);
        move_map_rect(all, 0, 8);
    } else
        move_player_check_bis(all);
    for (int i = 0; i < INDEX_PNJ; i++)
        sfSprite_setPosition(all->pnj[i].sprite, all->pnj[i].position);
}

void event_game_b(all_t *all)
{
    if (all->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(all->keys.inv) == 1)
        all->invent = !all->invent;
    if (all->invent == true)
        event_inventory(all);
    if (all->invent == false)
        move_player_check(all);
}

void norm_condition(all_t *all)
{
    if (all->use[2] == sfFalse)
        init_pause(all);
    change_scene(all, PAUSE);
}

void event_game(all_t *all)
{
    while (sfRenderWindow_pollEvent(all->window, &all->event)) {
        if (all->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEscape) == 1 && all->invent == false)
            norm_condition(all);
        event_game_b(all);
        event_spell(all);
        event_pnj(all);
    }
}