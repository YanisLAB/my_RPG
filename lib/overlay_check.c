/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** overlay_check.c
*/

#include "../include/my_rpg.h"

sfBool overlay_check(sprite_t *sprite, all_t *all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->window);
    if ((sprite->position.x <= mouse.x &&
    sprite->position.x + sprite->size.x >= mouse.x) &&
        (sprite->position.y <= mouse.y &&
        sprite->position.y + sprite->size.y >= mouse.y)) {
            return (sfTrue);
    }
    return (sfFalse);
}

sfBool release_check(all_t *all, sprite_t *sprite)
{
    if (all->event.type == sfEvtMouseButtonReleased &&
    overlay_check(sprite, all) == sfTrue) {
        if ((sprite->position.x <= all->mouse.x &&
    sprite->position.x + sprite->size.x >= all->mouse.x) &&
        (sprite->position.y <= all->mouse.y &&
        sprite->position.y + sprite->size.y >= all->mouse.y))
            return (sfTrue);
    }
    return (sfFalse);
}

sfBool click_check(all_t *all)
{
    if (all->event.type == sfEvtMouseButtonPressed &&
    all->event.mouseButton.button == sfMouseLeft)
        return (sfTrue);
    return (sfFalse);
}

void change_scene(all_t *all, int scene)
{
    all->last_scene = all->scene;
    all->scene = scene;
}