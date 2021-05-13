/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** open_file.c
*/

#include "../include/my_rpg.h"

char *fill_buffer(char *buffer, int fd, int size)
{
    int r = 0;

    r = read(fd, buffer, size);
    if (r == -1) {
        return (NULL);
    }
    if (buffer[0] == '\0') {
        return (NULL);
    }
    return (buffer);
}

char *open_file(char *file)
{
    int fd = open(file, O_RDONLY);
    char *buffer = NULL;
    int ret = 0;

    if (fd < 0)
        return (NULL);
    if (ret == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (1000 + 1));
    buffer[1000] = '\0';
    buffer = fill_buffer(buffer, fd, 1000);
    if (buffer == NULL)
        return (NULL);
    close(fd);
    return (buffer);
}