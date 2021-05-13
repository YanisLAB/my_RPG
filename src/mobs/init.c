/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** mobs.c
*/

#include "../../include/my_rpg.h"

void init_mobs(mob_z_t **mobs, int nb_mob, int x, int y)
{
    pos_mob_t pos;

    pos.x = x;
    pos.y = y;
    for (int i = 0; i < nb_mob; i += 1)
        mobs_push_back(mobs, init_sprite((sfIntRect) {0, 130, 65, 65},
        "assets/mobs/mob1.png"), 150, pos);
}

void set_id_mob(text_t *boss, int id, int x, int y)
{
    boss->my_font = sfFont_createFromFile("assets/Alamak.ttf");
    boss->text = sfText_create();
    boss->nbr = id;
    my_int_str(boss->str, id);
    sfText_setString(boss->text, boss->str);
    sfText_setFont(boss->text, boss->my_font);
    sfText_setCharacterSize(boss->text, 15);
    sfText_setColor(boss->text, sfWhite);
    sfText_setOutlineColor(boss->text, sfRed);
    sfText_setOutlineThickness(boss->text, 2);
    boss->position.x = x;
    boss->position.y = y;
    sfText_setPosition(boss->text, boss->position);
}

void init_boss_bis(all_t *all)
{
    for (int i = 0; i < INDEX_BOSS; i++)
        all->boss[i].clock.clock = sfClock_create();
    for (int i = 0; i < INDEX_BOSS; i += 1) {
        sfSprite_setOrigin(all->boss[i].boss.sprite,
        (sfVector2f) {48.75, 48.75});
        all->boss[i].life = 900;
        all->boss[i].dead = sfFalse;
        all->boss[i].offset1 = 0;
        all->boss[i].offset2 = 0;
    }
}

void init_boss(all_t *all)
{
    all->use[6] = sfTrue;
    all->boss[0].boss = init_sprite((sfIntRect) {0, 292, 98, 97},
    "assets/mobs/mino_boss.png");
    all->boss[1].boss = init_sprite((sfIntRect) {0, 292, 98, 97},
    "assets/mobs/orc_boss.png");
    all->boss[2].boss = init_sprite((sfIntRect) {0, 292, 98, 97},
    "assets/mobs/wolf_boss.png");
    set_pos(&all->boss[0].boss, -3250, -4200);
    set_pos(&all->boss[1].boss, -2000, -3000);
    set_pos(&all->boss[2].boss, 300, -2500);
    init_boss_bis(all);
    set_id_mob(&all->boss[0].id, 44, all->boss[0].boss.position.x,
    all->boss[0].boss.position.y);
    set_id_mob(&all->boss[1].id, 99, all->boss[1].boss.position.x,
    all->boss[1].boss.position.y);
    set_id_mob(&all->boss[2].id, 49, all->boss[2].boss.position.x,
    all->boss[2].boss.position.y);
}

void init_all_mobs(all_t *all)
{
    all->mob_z1 = NULL;
    init_mobs(&all->mob_z1, 15, -2500, -150);
    init_mobs(&all->mob_z1, 15, -800, 0);
    init_mobs(&all->mob_z1, 15, -2500, -1500);
    init_mobs(&all->mob_z1, 15, -2500, -2500);
    init_mobs(&all->mob_z1, 15, -3500, -4200);
    init_mobs(&all->mob_z1, 15, -2000, -3000);
    init_mobs(&all->mob_z1, 15, 300, -2300);
    init_mobs(&all->mob_z1, 15, -3250, 5000);
    init_mobs(&all->mob_z1, 15, -2000, -4000);
    init_mobs(&all->mob_z1, 15, 300, -3500);
}