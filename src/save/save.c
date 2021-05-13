/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** save.c
*/

#include "../../include/my_rpg.h"

void save_equipe(all_t *all, char *str)
{
    int i = 0;
    int a = 0;
    char **inv;
    int nbr;

    inv = my_str_to_word_array2(str, ':');
    for (inventory_t *tmp = all->equiped; tmp != NULL; tmp = tmp->next) {
        nbr = my_atoi(inv[i]);
        save_equipe_bis(all, tmp, nbr, a);
        a++;
        i += 1;
    }
}

void save_invent(all_t *all)
{
    char *buff;
    char **str;

    buff = open_file("assets/save_mano.txt");
    str = my_str_to_word_array2(buff, '\n');
    save_inv(all, str[0]);
    save_equipe(all, str[1]);
    str = my_str_to_word_array2(str[2], ':');
    for (int i = 0; i < INDEX_SPELL; i += 1) {
        all->spell_lvl[i].nbr = my_atoi(str[i]);
        all->spell_lvl[i].str[0] = str[i][0];
        all->spell_lvl[i].str[1] = str[i][1];
        sfText_setString(all->spell_lvl[i].text, all->spell_lvl[i].str);
    }
}

void save_keys(all_t *all)
{
    FILE *fd;
    keys_t tmp;

    fd = fopen("assets/save_keys.txt", "rb");
    fread(&tmp, sizeof(keys_t), 1, fd);
    fclose(fd);
    all->keys.up = tmp.up;
    all->keys.down = tmp.down;
    all->keys.left = tmp.left;
    all->keys.right = tmp.right;
    all->touch[0].str[0] = all->keys.inv + 97;
    all->touch[1].str[0] = all->keys.left + 97;
    all->touch[2].str[0] = all->keys.right + 97;
    all->touch[3].str[0] = all->keys.down + 97;
    all->touch[4].str[0] = all->keys.up + 97;
}

void open_save_bis(all_t *all, all_t *tmp)
{
    for (int i = 0; i < INDEX_MAP; i++)
        all->map[i].rect = tmp->map[i].rect;
    for (int i = 0; i < INDEX_MINIMAP; i++) {
        all->minimap[i].rect = tmp->minimap[i].rect;
        sfSprite_setPosition(all->minimap[i].sprite, all->minimap[i].position);
    }
    for (int i = 0; i < INDEX_PNJ; i += 1) {
        all->pnj[i].position = tmp->pnj[i].position;
        sfSprite_setPosition(all->pnj[i].sprite, all->pnj[i].position);
    }
}

void open_save(all_t *all)
{
    FILE *fd;
    all_t *tmp;
    int x = 0;
    int y = 0;

    fd = fopen("assets/save.txt", "rb");
    fread(tmp, sizeof(all_t), 1, fd);
    fclose(fd);
    x = tmp->map->rect.left - all->map->rect.left;
    y = tmp->map->rect.top - all->map->rect.top;
    save_player(all);
    save_invent(all);
    save_keys(all);
    all->quest = tmp->quest;
    open_save_bis(all, tmp);
    for (int i = 0; i < TOUCH; i += 1)
        sfText_setString(all->touch[i].text, all->touch[i].str);
    save_pos_mobs(all, x, y);
}
