/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** pnj2.c
*/

#include "../../include/my_rpg.h"

void get_quest2(all_t *all)
{
    char *quest = "You're the one my dad called to come and help me ?There's \
    some\n monsters that stole my toys. You can go and get them back for \n\
    me please. They're badge with numbers written on them. \n\
    mine are 44, 49 and 99! One is to the north, one is to \n\
    the northeast and one is to the southwest of here.";
    sfText_setCharacterSize(all->quest_t.text, 20);
    my_strcpy(all->quest_t.str, quest);
    sfText_setString(all->quest_t.text, all->quest_t.str);
}

void blabla2(all_t *all)
{
    char *quest = "     The village is very quiet at the moment.\n\
    It's very pleasant.";
    sfText_setCharacterSize(all->quest_t.text, 25);
    my_strcpy(all->quest_t.str, quest);
    sfText_setString(all->quest_t.text, all->quest_t.str);
}

void get_quest21(all_t *all)
{
    char *quest = "Thank you for getting my toys back! In exchange I can\n\
    give you an hint to find who is sending all these monsters.\n\
    Can you help get them off our island? Nobody\n\
    know exactly where they are, but rumour has it that their\n\
    base is just south east of our island.";

    sfText_setCharacterSize(all->quest_t.text, 18);
    my_strcpy(all->quest_t.str, quest);
    sfText_setString(all->quest_t.text, all->quest_t.str);
}

int check_quest(all_t *all)
{
    int nb = 0;
    inventory_t *tmp = all->inventory;

    while (tmp) {
        if (tmp->inv.type == 6)
            nb += 1;
        tmp = tmp->next;
    }
    if (nb == 3)
        return (0);
    return (1);
}

void pnj2(all_t *all)
{
    if (all->quest == 1) {
        get_quest2(all);
        pnj2_condition(all);
    } else if(all->quest == 2 && check_quest(all) == 0) {
        get_quest21(all);
        pnj2_if(all);
    } else
        pnj2_bis(all);
}