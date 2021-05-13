/*
** EPITECH PROJECT, 2020
** rpg_repo
** File description:
** my_strlen.c
*/

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i += 1);
    return (i);
}