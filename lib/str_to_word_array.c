/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** str_to_word_array.c
*/

#include "../include/my_rpg.h"

char *my_str_dup(char *src)
{
    char *dup;
    int src_len = my_strlen(src);

    dup = malloc(sizeof(char) * (src_len + 1));
    for (int i = 0; src[i] != '\0'; i = i + 1)
        dup[i] = src[i];
    dup[src_len] = '\0';
    return dup;
}

void check_str(char **array, char *temp, int *ii, int *k)
{
    if (*ii != 0) {
        temp[*ii] = '\0';
        *ii = 0;
        array[*k] = my_str_dup(temp);
        *k += 1;
    }
}

char **my_str_to_word_array(char *str)
{
    char **array = malloc(sizeof(char *) * (my_strlen(str) + 1));
    char temp[512];
    int i = 0;
    int ii = 0;
    int k = 0;

    for (; str[i] != '\0'; i += 1) {
        if (str[i] != '\n') {
            temp[ii] = str[i];
            ii += 1;
        } else
            check_str(array, temp, &ii, &k);
    }
    check_str(array, temp, &ii, &k);
    array[k] = NULL;
    return (array);
}

void free_all(char **buff, char *tab)
{
    for (int i = 0; buff[i] != NULL; i += 1)
        free(buff[i]);
    free(buff);
    free(tab);
}

char **my_str_to_word_array2(char *str, char sep)
{
    char **array = malloc(sizeof(char *) * (my_strlen(str) + 1));
    char temp[512];
    int i = 0;
    int a = 0;
    int k = 0;
    for (; str[i] != '\0'; i += 1) {
        if (str[i] != sep) {
            temp[a] = str[i];
            a += 1;
        } else {
            check_str(array, temp, &a, &k);
        }
    }
    check_str(array, temp, &a, &k);
    array[k] = NULL;
    return (array);
}