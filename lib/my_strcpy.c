/*
** EPITECH PROJECT, 2020
** rpg_repo
** File description:
** my_strcpy.c
*/

#include "../include/my_rpg.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0;
    for (i = 0; src[i] != '\0'; i += 1)
        dest[i] = src[i];
    for (; dest[i] != '\0'; i += 1)
        dest[i] = '\0';
    return (dest);
}