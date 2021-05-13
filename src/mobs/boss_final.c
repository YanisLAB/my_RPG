/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** boss_final.c
*/

#include "../../include/my_rpg.h"

void init_name(text_t *boss)
{
    char *name = "OUAII LE BOSSSS!";
    boss->my_font = sfFont_createFromFile("assets/Alamak.ttf");
    boss->text = sfText_create();
    my_strcpy(boss->str, name);
    sfText_setString(boss->text, boss->str);
    sfText_setFont(boss->text, boss->my_font);
    sfText_setCharacterSize(boss->text, 30);
    sfText_setColor(boss->text, sfWhite);
    sfText_setOutlineColor(boss->text, sfBlack);
    sfText_setOutlineThickness(boss->text, 2);
    boss->position.x = 850;
    boss->position.y = 10;
    sfText_setPosition(boss->text, boss->position);
}

void init_boss_final(all_t *all)
{
    all->use[7] = sfTrue;
    all->boss_f.boss = init_sprite((sfIntRect) {0, 0, 130, 130},
    "assets/mobs/final_boss.png");
    set_pos(&all->boss_f.boss, -4200, 800);
    sfSprite_setOrigin(all->boss_f.boss.sprite, (sfVector2f) {65, 65});
    all->boss_f.life = 1000;
    all->boss_f.life_max = 1000;
    all->boss_f.offset1 = 0;
    all->boss_f.offset2 = 0;
    init_name(&all->boss_f.name);
    all->boss_f.bg_bar = init_sprite((sfIntRect) {0, 0, 1100, 61},
    "assets/mobs/bg_boss.png");
    set_pos(&all->boss_f.bg_bar, 400, 40);
    all->boss_f.bar_life = init_sprite((sfIntRect) {0, 0, 993, 21},
    "assets/mobs/life_boss.png");
    set_pos(&all->boss_f.bar_life, 455, 60);
    all->boss_f.regen = 0;
}

void moov_boss_y(boss_f_t *boss, all_t *all)
{
    if (boss->boss.position.y < pp.y) {
        boss->boss.position.y += 2;
        boss->boss.rect.top = 260;
        boss->boss.rect.left += 128;
    } else if (boss->boss.position.y > pp.y) {
        boss->boss.position.y -= 2;
        boss->boss.rect.top = 0;
        boss->boss.rect.left += 128;
    }
}

void moov_boss(boss_f_t *boss, all_t *all)
{
    if (boss->boss.position.x < pp.x) {
        boss->boss.position.x += 2;
        boss->boss.rect.top = 390;
        boss->boss.rect.left += 128;
    } else if (boss->boss.position.x > pp.x) {
        boss->boss.position.x -= 2;
        boss->boss.rect.top = 130;
        boss->boss.rect.left += 128;
    }
    moov_boss_y(boss, all);
    set_pos(&boss->boss, boss->boss.position.x, boss->boss.position.y);
}

void event_fboss(all_t *all)
{
    if (get_distance(all->boss_f.boss.position.x,
    all->boss_f.boss.position.y, pp.x,
    pp.y) < 400) {
        moov_boss(&all->boss_f, all);
        all->boss_f.fight = sfTrue;
    }
    if (get_distance(all->boss_f.boss.position.x,
    all->boss_f.boss.position.y, pp.x,
    pp.y) < 40)
        all->p.life -= 1.2;
    update_life(all);
}