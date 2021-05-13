/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** my_strcat.c
*/

#include "../include/my_rpg.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int b = 0;

    while (dest[i] != '\0') {
        i = i + 1;
    }
    while (src[b] != '\0') {
        dest [i + b] = src [b];
        b = b + 1;
    }
    dest[i + b] = '\0';
    return (dest);
}
