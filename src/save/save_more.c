/*
** EPITECH PROJECT, 2020
** my_rpg1
** File description:
** save_more.c
*/

#include "../../include/my_rpg.h"

void save_mano(all_t *all)
{
    int fd = open("assets/save_mano.txt", O_CREAT | O_TRUNC | O_WRONLY, 0666);

    for (inventory_t *tmp = all->inventory; tmp != NULL; tmp = tmp->next) {
        my_put_nbr(tmp->inv.type, fd);
        if (tmp->next != NULL)
            write(fd, ":", 1);
    }
    write(fd, "\n", 1);
    for (inventory_t *tmp = all->equiped; tmp != NULL; tmp = tmp->next) {
        my_put_nbr(tmp->inv.item, fd);
        if (tmp->next != NULL)
            write(fd, ":", 1);
    }
    write(fd, "\n", 1);
    for (int i = 0; i < INDEX_SPELL; i += 1) {
        write(fd, all->spell_lvl[i].str, my_strlen(all->spell_lvl[i].str));
        if (i + 1 != INDEX_SPELL)
            write(fd, ":", 1);
    }
    write(fd, "\n", 1);
}

void write_save(all_t *all)
{
    FILE *fd;
    fd = fopen("assets/save.txt", "wb");
    fwrite(all, sizeof(all_t), 1, fd);
    fclose(fd);
    fd = fopen("assets/save_player.txt", "wb");
    fwrite(&all->p, sizeof(player_t), 1, fd);
    fclose(fd);
    fd = fopen("assets/save_map.txt", "wb");
    fwrite(&all->map, sizeof(sprite_t), 1, fd);
    fclose(fd);
    fd = fopen("assets/save_keys.txt", "wb");
    fwrite(&all->keys, sizeof(keys_t), 1, fd);
    fclose(fd);
    save_mano(all);
}

void save_player(all_t *all)
{
    FILE *fd;
    player_t tmp2;
    fd = fopen("assets/save_player.txt", "rb");
    fread(&tmp2, sizeof(player_t), 1, fd);
    fclose(fd);
    all->p.lvl.nbr = tmp2.lvl.nbr;
    my_int_str(all->p.lvl.str, all->p.lvl.nbr);
    sfText_setString(all->p.lvl.text, all->p.lvl.str);
    all->p.point = tmp2.point;
    all->p.xp = tmp2.xp;
    all->p.life = tmp2.life;
    all->p.max_hp = tmp2.max_hp;
    all->p.mana = tmp2.mana;
    all->p.max_mana = tmp2.max_mana;
    all->p.attack = tmp2.attack;
}

void save_inv(all_t *all, char *str)
{
    int i = 0;
    char **inv;
    int nbr;

    inv = my_str_to_word_array2(str, ':');
    for (inventory_t *tmp = all->inventory; tmp != NULL; tmp = tmp->next) {
        nbr = my_atoi(inv[i]);
        if (nbr != 0)
            give_item(all, nbr);
        i += 1;
    }
}

void save_equipe_bis(all_t *all, inventory_t *tmp, int nbr, int a)
{
    inventory_t *temp;
    if (nbr == 1) {
        give_item(all, nbr + a);
        for (temp = all->inventory; temp->next->inv.item == sfTrue;
        temp = temp->next);
        item_switch(&temp->inv, &tmp->inv);
        tmp->inv.stat[0] = temp->inv.stat[0];
        tmp->inv.stat[1] = temp->inv.stat[1];
        tmp->inv.stat[2] = temp->inv.stat[2];
        update_stat(all, temp->inv.stat, 1);
        destroy_sprite(&temp->inv.stuff);
    }
}