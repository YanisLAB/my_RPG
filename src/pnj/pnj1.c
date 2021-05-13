/*
** EPITECH PROJECT, 2020
** rpg_repo
** File description:
** pnj.c
*/

#include "../../include/my_rpg.h"

void get_quest(all_t *all)
{
    char *quest = " Hello there. My son is in the west village.,\n\
    He needs your help. I can't go. \n\
    I'm stuck here. I'll have him give you... I'll ask him to\n\
    give you something to thank you for your help.";

    sfText_setCharacterSize(all->quest_t.text, 25);
    my_strcpy(all->quest_t.str, quest);
    sfText_setString(all->quest_t.text, all->quest_t.str);
}

void blabla(all_t *all)
{
    char *quest = "\tHey, what's up? What a beautiful day. Don't\n\
    you think? You can hear the birds singing.\n\
    It's beautiful.";
    sfText_setCharacterSize(all->quest_t.text, 25);
    my_strcpy(all->quest_t.str, quest);
    sfText_setString(all->quest_t.text, all->quest_t.str);
}

void delet_badge(inventory_t **inv)
{
    inventory_t *tmp = *inv;
    int i = 0;

    while (tmp) {
        if (tmp->inv.type == 6) {
            destroy_sprite(&tmp->inv.stuff);
            tmp->inv.type = 0;
            tmp->inv.item = sfFalse;
        }
        i += 1;
        tmp = tmp->next;
    }
}

void pnj1(all_t *all)
{
    if (all->quest == 0) {
        get_quest(all);
        if ((all->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeyEnter) == 1) ||
        sfJoystick_isButtonPressed(0, 1) == sfTrue) {
            all->p.xp += 10;
            all->quest += 1;
            all->dial = false;
        }
    } else
        blabla(all);
}