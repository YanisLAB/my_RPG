/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** player.c
*/

#include "../../include/my_rpg.h"

int low_or_up(float nbr)
{
    int ref = nbr / 32;

    nbr = nbr / 32;
    if ((int) (nbr + 0.25) != ref)
        return (nbr + 0.25);
    return (ref);
}

sfBool check_pos_player(all_t *all, int x, int y)
{
    int px = low_or_up((all->map[0].rect.top + 540 + x));
    int py = low_or_up((all->map[0].rect.left + 990 + y));

    if (all->world.map[px][py] != '0')
        return (sfTrue);
    return (sfFalse);
}

void player_value(all_t *all)
{
    all->p.lvl.nbr = 1;
    all->p.max_xp = 100;
    all->p.xp = 0;
    all->p.attack = 50;
    all->p.point = 0;
    all->p.offset1 = 0;
    all->p.offset2 = 0;
    all->p.life = 200;
    all->p.max_hp = 200;
    all->p.max_mana = 500;
    all->p.mana = 500;
}

void init_player_bis(all_t *all)
{
    my_int_str(all->p.lvl.str, all->p.lvl.nbr);
    all->p.lvl.text = sfText_create();
    all->p.lvl.my_font = sfFont_createFromFile("assets/Alamak.ttf");
    sfText_setFont(all->p.lvl.text, all->p.lvl.my_font);
    sfText_setString(all->p.lvl.text, all->p.lvl.str);
    sfText_setColor(all->p.lvl.text, sfBlack);
    all->p.lvl.position.x = 1330;
    all->p.lvl.position.y = 470;
    sfText_setPosition(all->p.lvl.text, all->p.lvl.position);
    update_life(all);
    all->p.attack_s = init_sprite((sfIntRect) {0, 0, 176, 162},
    "assets/player/attck.png");
    sfSprite_setOrigin(all->p.attack_s.sprite, (sfVector2f) {88, 81});
    all->p.attack_c.sec = 0;
    all->p.attack_c.clock = sfClock_create();
    all->p.finish = 0;
}

void init_player(all_t *all)
{
    all->use[5] = sfTrue;
    all->p.player = init_sprite((sfIntRect) {0, 582, 65, 65},
    "assets/player/Player1.png");
    sfSprite_setOrigin(all->p.player.sprite, (sfVector2f) {32, 32});
    set_pos(&all->p.player, 990, 540);
    all->spelloverlay[0] = init_sprite((sfIntRect) {0, 0, 233, 15},
    "assets/player/lifebar.png");
    all->spelloverlay[1] = init_sprite((sfIntRect) {0, 0, 233, 15},
    "assets/player/manabar.png");
    all->spelloverlay[2] = init_sprite((sfIntRect) {0, 0, 868, 162},
    "assets/player/barlife.png");
    all->spelloverlay[3] = init_sprite((sfIntRect) {0, 0, 60, 60},
    "assets/player/kré.png");
    set_pos(&all->spelloverlay[0], 1015, 975);
    set_pos(&all->spelloverlay[1], 615, 975);
    set_pos(&all->spelloverlay[2], 500, 945);
    set_pos(&all->spelloverlay[3], 632, 1005);
    player_value(all);
    init_player_bis(all);
}