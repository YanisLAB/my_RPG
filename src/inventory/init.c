/*
** EPITECH PROJECT, 2020
** Repo_rpg
** File description:
** init.c
*/

#include "../../include/my_rpg.h"

void set_type(all_t *all)
{
    inventory_t *tmp = all->equiped;

    for (int i = 1; tmp != NULL; tmp = tmp->next, i += 1)
        tmp->inv.type = i;
}

void init_equiped(all_t *all)
{
    all->equiped = NULL;
    sfVector2f head = {969, 446};
    sfVector2f chestplate = {969, 525};
    sfVector2f legs = {969, 621};
    sfVector2f boots = {969, 762};
    sfVector2f weapon = {897, 609};
    init_item_push_back(&all->equiped, head);
    init_item_push_back(&all->equiped, chestplate);
    init_item_push_back(&all->equiped, legs);
    init_item_push_back(&all->equiped, boots);
    init_item_push_back(&all->equiped, weapon);
    set_type(all);
}

void init_carac(all_t *all)
{
    all->inventory_s[1] = init_sprite((sfIntRect)
    {0, 0, 196, 21}, "assets/inventory/xp.png");
    all->inventory_s[2] = init_sprite((sfIntRect)
    {0, 0, 27, 37}, "assets/inventory/carac.png");
    all->inventory_s[3] = init_sprite((sfIntRect)
    {0, 0, 27, 37}, "assets/inventory/carac.png");
    all->inventory_s[4] = init_sprite((sfIntRect)
    {0, 0, 27, 37}, "assets/inventory/carac.png");
    all->inventory_s[5] = init_sprite((sfIntRect)
    {0, 0, 27, 37}, "assets/inventory/carac.png");
    set_pos(&all->inventory_s[1], 1201, 505);
    set_pos(&all->inventory_s[2], 1258, 577);
    set_pos(&all->inventory_s[3], 1411, 577);
    set_pos(&all->inventory_s[4], 1258, 705);
    set_pos(&all->inventory_s[5], 1411, 705);
    for (int i = 2; i < INDEX_INVEN; i++) {
        all->inventory_s[i].size =
        sfTexture_getSize(all->inventory_s[i].texture);
        all->inventory_s[i].size.y /= 3;
    }
}

void init_inv(all_t *all)
{
    int x = 362;
    int y = 360;

    all->inventory = NULL;
    all->invent = false;
    all->inventory_s[0] = init_sprite((sfIntRect)
    {0, 0, 1920, 1080}, "assets/inventory/inventory.png");
    init_carac(all);
    all->overlay_items = init_sprite((sfIntRect)
    {0, 0, 81, 79}, "assets/inventory/items/overlay_items.png");
    for (int i = 0; i < 6; i += 1) {
        for (int k = 0; k < 5; k += 1) {
            init_item_push_back(&all->inventory, (sfVector2f) {x, y});
            x += 81;
        }
        x = 362;
        y += 79;
    }
    init_equiped(all);
}
