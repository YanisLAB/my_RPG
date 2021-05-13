/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** minimap.c
*/

#include "../../include/my_rpg.h"

void display_minimap(all_t *all)
{
    sfRenderWindow_drawCircleShape(all->window, all->minimap[0].circle, NULL);
    for (int i = 1; i < INDEX_MINIMAP; i++)
        display_sprite(all->window, &all->minimap[i], 0, 0);
}

void init_minimap(all_t *all)
{
    all->minimap[0] = init_sprite(
    (sfIntRect) {1641, 1434, 300, 300}, "assets/map/minimap.png");
    all->minimap[1] = init_sprite(
    (sfIntRect) {0, 144, 16, 16}, "assets/player/miniplayer.png");
    all->minimap[2] = init_sprite(
    (sfIntRect) {0, 0, 300, 300}, "assets/map/radar.png");
    all->minimap[0].circle = sfCircleShape_create();
    sfCircleShape_setTexture(all->minimap[0].circle,
    all->minimap[0].texture, sfTrue);
    sfCircleShape_setTextureRect(all->minimap[0].circle, all->minimap[0].rect);
    sfCircleShape_setRadius(all->minimap[0].circle, 110);
    sfCircleShape_setPosition(all->minimap[0].circle, (sfVector2f) {65, 65});
    set_pos(&all->minimap[1], 167, 167);
    set_pos(&all->minimap[2], 25, 25);
}

void destroy_minimap(all_t *all)
{
    sfCircleShape_destroy(all->minimap[0].circle);
    for (int i = 0; i < INDEX_MINIMAP; i++) {
        destroy_sprite(&all->minimap[i]);
    }
}