/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** event.c
*/

#include "../../include/my_rpg.h"

void item_switch(inv_t *tmp, inv_t *tmp2)
{
    tmp2->item = sfTrue;
    tmp->item = sfFalse;
    tmp2->type = tmp->type;
    tmp2->stuff.sprite = sfSprite_create();
    tmp2->stuff.texture = sfTexture_copy(tmp->stuff.texture);
    tmp2->stuff.rect = tmp->stuff.rect;
    sfSprite_setTexture(tmp2->stuff.sprite, tmp2->stuff.texture, sfFalse);
    sfSprite_setTextureRect(tmp2->stuff.sprite, tmp2->stuff.rect);
    set_pos(&tmp2->stuff, tmp2->coord.x, tmp2->coord.y);
    tmp->type = 0;
}

void check_switch(inventory_t *tmp, all_t *all)
{
    inventory_t *tmp2 = all->equiped;
    for (; tmp2 != NULL; tmp2 = tmp2->next) {
        if (tmp->inv.type == tmp2->inv.type && tmp2->inv.item == sfFalse) {
            item_switch(&tmp->inv, &tmp2->inv);
            tmp2->inv.stat[0] = tmp->inv.stat[0];
            tmp2->inv.stat[1] = tmp->inv.stat[1];
            tmp2->inv.stat[2] = tmp->inv.stat[2];
            update_stat(all, tmp->inv.stat, 1);
            destroy_sprite(&tmp->inv.stuff);
        }
    }
}

void event_inventory(all_t *all)
{
    if (click_check(all) == sfTrue) {
        all->mouse = sfMouse_getPositionRenderWindow(all->window);
        switch_items(all);
        unequipe_item(all);
    }
    if (all->event.type == sfEvtMouseButtonPressed &&
    all->event.mouseButton.button == sfMouseRight)
        remove_item(all);
    for (int i = 2; i < INDEX_INVEN; i++) {
        if (all->p.point > 0 && release_check(all,
        &all->inventory_s[i]) == sfTrue) {
            all->spell_lvl[i - 2].nbr += 1;
            all->p.point -= 1;
            my_int_str(all->spell_lvl[i - 2].str, all->spell_lvl[i - 2].nbr);
            sfText_setString(all->spell_lvl[i - 2].text,
            all->spell_lvl[i - 2].str);
        }
    }
    overlay_inv(all);
}

void overlay_invb(all_t *all, int i)
{
    if (overlay_check(&all->inventory_s[i], all) == sfTrue &&
    click_check(all) == sfTrue) {
        sfSound_play(all->click.sound);
        all->inventory_s[i].rect.top = all->inventory_s[i].size.y * 2;
        sfSprite_setTextureRect(all->inventory_s[i].sprite,
        all->inventory_s[i].rect);
    } else if (overlay_check(&all->inventory_s[i], all) == sfTrue) {
        all->inventory_s[i].rect.top = all->inventory_s[i].size.y;
        sfSprite_setTextureRect(all->inventory_s[i].sprite,
        all->inventory_s[i].rect);
    } else {
        all->inventory_s[i].rect.top = 0;
        sfSprite_setTextureRect(all->inventory_s[i].sprite,
        all->inventory_s[i].rect);
    }
}

void overlay_inv(all_t *all)
{
    for (int i = 2; i < INDEX_INVEN; i++) {
        overlay_invb(all, i);
    }
}