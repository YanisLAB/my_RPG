/*
** EPITECH PROJECT, 2020
** Repo_rpg
** File description:
** display.c
*/

#include "../../include/my_rpg.h"

void display_equiped(all_t *all)
{
    inventory_t *tmp = all->equiped;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->window);

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->inv.item) {
            sfRenderWindow_drawSprite(all->window, tmp->inv.stuff.sprite,
            NULL);
        }
        if ((mouse.x >= tmp->inv.coord.x && mouse.x <= tmp->inv.coord.x + 69)
        && (mouse.y >= tmp->inv.coord.y && mouse.y <= tmp->inv.coord.y + 69)) {
            sfSprite_setPosition(all->overlay_items.sprite, tmp->inv.coord);
            sfRenderWindow_drawSprite(all->window,
            all->overlay_items.sprite, NULL);
        }
    }
}

void display_inventory_bis(all_t *all, inventory_t *tmp, sfVector2i mouse)
{
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->inv.item)
            sfRenderWindow_drawSprite(all->window, tmp->inv.stuff.sprite,
            NULL);
        if ((mouse.x >= tmp->inv.coord.x && mouse.x <= tmp->inv.coord.x + 81)
        && (mouse.y >= tmp->inv.coord.y && mouse.y <= tmp->inv.coord.y + 79)) {
            sfSprite_setPosition(all->overlay_items.sprite, tmp->inv.coord);
            sfRenderWindow_drawSprite(all->window,
            all->overlay_items.sprite, NULL);
        }
    }
}

void display_inventory(all_t *all)
{
    inventory_t *tmp = all->inventory;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(all->window);
    for (int i = 0; i < INDEX_INVEN; i++) {
        if (all->p.point == 0 && i >= 2)
            break;
        display_sprite(all->window, &all->inventory_s[i], 0, 0);
    }
    for (int i = 0; i < INDEX_SPELL; i++)
        sfRenderWindow_drawText(all->window, all->spell_lvl[i].text, NULL);
    display_inventory_bis(all, tmp, mouse);
    sfRenderWindow_drawText(all->window, all->p.lvl.text, NULL);
    display_equiped(all);
}