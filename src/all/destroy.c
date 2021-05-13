/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-yanis.labchiri
** File description:
** destroy.c
*/

#include "../../include/my_rpg.h"

static array_t func[INDEX_USE] = {
    {destroy_map},
    {destroy_option},
    {destroy_pause},
    {destroy_lose},
    {destroy_win},
    {destroy_player},
    {destroy_boss},
    {destroy_boss_final},
    {destroy_help}
};

void destroy_pnj_t(all_t *all)
{
    sfText_destroy(all->quest_t.text);
    sfFont_destroy(all->quest_t.my_font);
    sfText_destroy(all->p_enter.text);
    sfFont_destroy(all->p_enter.my_font);
}

void destroy_boss(all_t *all)
{
    for (int i = 0; i < INDEX_BOSS; i += 1) {
        sfText_destroy(all->boss[i].id.text);
        sfFont_destroy(all->boss[i].id.my_font);
        destroy_sprite(&all->boss[i].boss);
    }
}

void destroy_allbis(all_t *all)
{
    destroy_mob(all);
    time_str(all->time_play.str, all->time_play.nbr);
    sfRectangleShape_destroy(all->rain.rectangle_shape);
    sfConvexShape_destroy(all->particle_environment.convex_shape);
}

void destroy_all(all_t *all)
{
    if (all->world.read_map == sfTrue)
        destroy_world(all);
    for (int i = 0; i < INDEX_USE; i++) {
        if (all->use[i] == sfTrue)
            func[i].ptr(all);
    }
    destroy_main(all);
    destroy_cooldown(all);
    sfClock_destroy(all->controller.clock);
    sfClock_destroy(all->time_joy.clock);
    sfClock_destroy(all->clocks.clock);
    destroy_inventory(all);
    destroy_pnj_t(all);
    destroy_sprite(&all->quest_bg);
    destroy_sound(all);
    destroy_allbis(all);
    sfRenderWindow_destroy(all->window);
}