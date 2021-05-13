/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** get_line.c
*/

#include "../include/my_rpg.h"

char *get_line(char *filepath, int line)
{
    char *buffer = NULL;
    unsigned long len;
    FILE *fd = fopen(filepath, "r");
    for (; line > 0 && getline(&buffer, &len, fd) != -1; line -= 1);
    fclose(fd);
    return (buffer);
}