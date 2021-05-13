/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** put_nbr.c
*/

#include "../include/my_rpg.h"

void my_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

int my_put_nbr(int nb, int fd)
{
    if (nb == -2147483648) {
        write (fd, "-2147483648", 11);
        return (0);
    }
    if (nb < 0) {
        nb = - nb;
        write(1, "-", 1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10, fd);
        my_put_nbr(nb % 10, fd);
    } else
        my_putchar(nb + 48, fd);
    return (0);
}