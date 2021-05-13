/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-yanis.labchiri
** File description:
** init_map.c
*/

#include "../../include/my_rpg.h"

void display_map_more_bis(all_t *all)
{
    if (all->s == 3 && all->colpart[2] > 0) {
        for (size_t index = 0; index != PARICULE_MAX; index++) {
            all->particle[index].color.b = 255;
            all->particle[index].color.r = 0;
            all->particle[index].color.g = 0;
            display_particle_bis(all->window, &all->particle[index],
            all->particle_environment.convex_shape);
        }
    }
    if (all->s == 4 && all->colpart[3] > 0) {
        for (size_t index = 0; index != PARICULE_MAX; index++) {
            all->particle[index].color.b = 0;
            all->particle[index].color.r = 0;
            all->particle[index].color.g = 255;
            display_particle_bis(all->window, &all->particle[index],
            all->particle_environment.convex_shape);
        }
    }
}

void display_map_more(all_t *all)
{
    if (all->s == 1 && all->colpart[0] > 0) {
        for (size_t index = 0; index != PARICULE_MAX; index++) {
            all->particle_bis[index].color.b = 0;
            all->particle_bis[index].color.r = 255;
            all->particle_bis[index].color.g = 0;
            display_particle(all->window, &all->particle_bis[index],
            all->particle_environment_bis.circle_shape);
        }
    }
    if (all->s == 2 && all->colpart[1] > 0) {
        for (size_t index = 0; index != PARICULE_MAX; index++) {
            all->particle_bis[index].color.b = 255;
            all->particle_bis[index].color.r = 0;
            all->particle_bis[index].color.g = 0;
            display_particle(all->window, &all->particle_bis[index],
            all->particle_environment_bis.circle_shape);
        }
    }
}

void display_map_bis(all_t *all)
{
    if (all->dial) {
        display_sprite(all->window, &all->quest_bg, 0, 0);
        sfRenderWindow_drawText(all->window, all->quest_t.text, NULL);
        sfRenderWindow_drawText(all->window, all->p_enter.text, NULL);
    }
    for (int i = 0; i < INDEX_PNJ; i += 1)
        display_sprite(all->window, &all->pnj[i], 0, 0);
    for (int i = 0; i < INDEX_SPELL; i += 1)
        display_sprite(all->window, &all->spelloverlay[i], 0, 0);
    display_coll(all);
    display_minimap(all);
    if (all->invent == true)
        display_inventory(all);
}

void display_map_b(all_t *all)
{
    joystick_movement(all);
    display_sprite(all->window, &all->map[0], 0, 0);
    display_sprite(all->window, &all->p.player, 0, 0);
    display_all_mobs(all);
    if (all->p.finish != 0)
        display_attack(all);
    if (all->boss_f.life > 0 && get_distance(all->boss_f.boss.position.x,
    all->boss_f.boss.position.y, pp.x,
    pp.y) < 1000 && all->quest == 4)
        display_sprite(all->window, &all->boss_f.boss, 0, 0);
    display_sprite(all->window, &all->map[1], 0, 0);
    if (all->boss_f.life > 0 && get_distance(all->boss_f.boss.position.x,
    all->boss_f.boss.position.y, pp.x, pp.y) < 1000 && all->quest == 4)
        display_boss(all);

}

void display_map(all_t *all)
{
    display_map_b(all);
    display_map_bis(all);
    display_map_more(all);
    display_map_more_bis(all);
    if (all->s != 0 && all->colpart[0] <= 0 && all->colpart[1] <= 0
    && all->colpart[2] <= 0 && all->colpart[3] <= 0) {
        for (size_t index = 0; index != PARICULE_MAX; index++) {
            all->particle[index].living = false;
            all->particle_bis[index].living = false;
        }
    }
    dammage_all_mobs(all);
    moov_all_mobs(all);
    if (all->boss_f.life > 0 && all->quest == 4)
        event_fboss(all);
    if (all->boss_f.life <= 0) {
        init_win(all);
        change_scene(all, WIN);
    }
    check_dead(all);
}
