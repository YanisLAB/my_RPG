/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-yanis.labchiri
** File description:
** main.c
*/

#include "../include/my_rpg.h"

void time_manage(all_t *all)
{
    all->coll.time = sfClock_getElapsedTime(all->coll.clock);
    all->coll.sec = all->coll.time.microseconds / 1000000.0;
    if (all->coll.sec > 1)
        act_coll(all);
}

void game_loop(all_t *all)
{
    for (size_t index = 0; index != PARICULE_MAX; index++) {
        update_particle(&all->particle_environment, \
        &all->particle[index]);
        update_particle_bis(&all->particle_environment_bis, \
        &all->particle_bis[index]);
    }
    if (all->quest == 4) {
        for (size_t index = 0; index != PARICULE_MAX; index++)
            update_rain(&all->rain, \
            &all->particle_rain[index]);
    }
    sfRenderWindow_clear(all->window, sfBlack);
    display(all);
    sfClock_restart(all->clocks.clock);
    sfRenderWindow_display(all->window);
}

int main(void)
{
    all_t all;
    init_all(&all);
    while (sfRenderWindow_isOpen(all.window)) {
        all.clocks.time = sfClock_getElapsedTime(all.clocks.clock);
        all.clocks.sec = all.clocks.time.microseconds / 1000000.0;
        event_all(&all);
        if (all.clocks.sec > 0.008) {
            game_loop(&all);
        }
        time_manage(&all);
    }
    destroy_all(&all);
    return (0);
}
