/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-mydefender-yanis.labchiri
** File description:
** int_to_str.c
*/

#include "../include/my_rpg.h"

void my_int_str(char *str, int nb)
{
    int i = 0;
    int p = 0;
    int m[2] = {10, 1};
    while (p < 2) {
        if (nb / m[p] >= 0) {
            str[i] = ((nb / m[p]) + 48);
            nb = nb - (nb / m[p]) * m[p];
            i += 1;
        }
        p++;
    }
    str[i] = '\0';
}

int time_boucle(int nbr, int *m, char *str, int *i)
{
    int copy = nbr;
    for (int p = 0; p < 2; p++) {
        if (nbr / m[p] >= 0) {
            str[*i] = ((nbr / m[p]) + 48);
            nbr = nbr - (nbr / m[p]) * m[p];
            *i += 1;
        }
    }
    return (copy);
}

void time_str(char *str, int nb)
{
    int i = 0;
    int nbr = 0;
    int nbr2 = 0;
    int m[2] = {10, 1};
    nbr = time_boucle(nb / 3600, m, str, &i);
    str[i] = 'h';
    i++;
    nbr2 = time_boucle((nb - (nbr * 3600)) / 60, m, str, &i);
    str[i] = 'm';
    i++;
    time_boucle(  ((nb - (nbr * 3600)) - (nbr2 * 60))  , m, str, &i);
    str[i] = 's';
    i++;
    str[i] = '\0';
}