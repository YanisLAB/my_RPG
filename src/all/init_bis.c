/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** init_bis.c
*/

#include "../../include/my_rpg.h"

void init_bis_b(all_t *all)
{
    init_particle_environment(&all->particle_environment_bis, \
    (sfVector2f){PARICULE_ANGLE_MIN, PARICULE_ANGLE_MAX}, \
    (sfVector2f){GRAVITY_X, GRAVITY_Y}, ALPHA);
    init_particle_environment_bis(&all->particle_environment, ALPHA);
    init_rain_env(&all->rain, \
    (sfVector2f){PARICULE_ANGLE_MIN, PARICULE_ANGLE_MAX}, \
    (sfVector2f){GRAVITY_X, GRAVITY_Y}, ALPHA);
    add_particle(&all->rain, all->particle_rain, \
    5000, (sfVector2f) {-10, -5});
    all->quest_bg = init_sprite((sfIntRect) {0, 0, 636, 156},
    "assets/quest/quest.png");
    set_pos(&all->quest_bg, 615, 800);
    all->quest_t = set_text_quest(625, 810);
    const sfImage *logo = sfImage_createFromFile("assets/logo.png");
    const sfUint8 *h = sfImage_getPixelsPtr(logo);
    sfRenderWindow_setIcon(all->window, 500, 500, h);
}

void init_bis(all_t *all)
{
    display_load(all);
    init_pnj(all);
    display_load(all);
    init_all_mobs(all);
    display_load(all);
    init_spell(all);
    display_load(all);
    init_boss(all);
    init_help(all);
    display_load(all);
    init_option(all);
    display_load(all);
    init_boss_final(all);
    init_bis_b(all);
    for (int i = 0; i < 2; i += 1)
        destroy_sprite(&all->load[i]);
}