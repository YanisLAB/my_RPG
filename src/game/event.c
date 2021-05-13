/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** event.c
*/

#include "../../include/my_rpg.h"

void move_map_rectb(all_t *all, int left, int top)
{
    for (int i = 0; i < INDEX_BOSS; i += 1) {
        all->boss[i].boss.position.x -= left;
        all->boss[i].boss.position.y -= top;
        all->boss[i].id.position.x = all->boss[i].boss.position.x;
        all->boss[i].id.position.y = all->boss[i].boss.position.y;
        sfText_setPosition(all->boss[i].id.text, all->boss[i].boss.position);
        sfSprite_setPosition(all->boss[i].boss.sprite,
        all->boss[i].boss.position);
    }
    all->boss_f.boss.position.x -= left;
    all->boss_f.boss.position.y -= top;
    for (int i = 0; i < INDEX_MAP; i++) {
        all->map[i].rect.left += left;
        all->map[i].rect.top += top;
    }
    all->minimap[0].rect.left += (left / 4);
    all->minimap[0].rect.top += (top / 4);
    sfSprite_setPosition(all->boss_f.boss.sprite, all->boss_f.boss.position);
    sfCircleShape_setTextureRect(all->minimap->circle, all->minimap[0].rect);
}

void move_map_rect(all_t *all, int left, int top)
{
    mob_z_t *tmp = all->mob_z1;

    while (tmp) {
        tmp->mobs.mob.position.x -= left;
        tmp->mobs.mob.position.y -= top;
        sfSprite_setPosition(tmp->mobs.mob.sprite, tmp->mobs.mob.position);
        tmp = tmp->next;
    }
    for (int i = 0; i < INDEX_PNJ; i++) {
        all->pnj[i].position.x -= left;
        all->pnj[i].position.y -= top;
    }
    move_map_rectb(all, left, top);
}

int randomizer_item(void)
{
    int nb = (rand() % 6) * 1;

    if (nb != 0)
        return (nb);
    else
        return (randomizer_item());
}

void give_items(all_t *all, int id, char **buffer, inventory_t *tmp)
{
    (void)all;
    tmp->inv.stat[2] = 0;
    if (id == 1)
        tmp->inv.stat[0] = my_atoi(buffer[2]);
    if (id == 2)
        tmp->inv.stat[1] = my_atoi(buffer[2]);
    if (id == 3) {
        tmp->inv.stat[0] = my_atoi(buffer[2]);
        tmp->inv.stat[1] = my_atoi(buffer[3]);
    }
    if (id == 4)
        tmp->inv.stat[1] = my_atoi(buffer[2]);
    if (id == 5)
        tmp->inv.stat[2] = my_atoi(buffer[2]);
    for (int i = 0; buffer[i] != NULL; i++)
        free(buffer[i]);
    free(buffer);
}

void give_item(all_t *all, int type)
{
    inventory_t *tmp = all->inventory;
    int id = 0;
    char **buffer = NULL;
    char *line = NULL;

    if (type == 0)
        type = randomizer_item();
    for (; tmp->inv.item == sfTrue; tmp = tmp->next);
    line = get_line("assets/item.txt", type);
    buffer = my_str_to_word_array2(line, ':');
    tmp->inv.stuff = init_sprite((sfIntRect) {0, 0, 81, 79}, buffer[1]);
    set_pos(&tmp->inv.stuff, tmp->inv.coord.x, tmp->inv.coord.y);
    tmp->inv.type = type;
    tmp->inv.item = sfTrue;
    id = my_atoi(buffer[0]);
    tmp->inv.stuff.size = sfTexture_getSize(tmp->inv.stuff.texture);
    tmp->inv.stat[0] = 0;
    tmp->inv.stat[1] = 0;
    give_items(all, id, buffer, tmp);
    free(line);
}