/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** open_map.c
*/

#include "../../include/my_rpg.h"

int get_world(map_t *map, char *filepath)
{
    map->read_map = sfTrue;
    map->fd = 0;
    map->len = 1;
    map->fd = open(filepath, O_RDONLY);
    map->buffer = malloc(sizeof(char) * 67861);
    if (read(map->fd, map->buffer, 67860) == -1)
        return (84);
    map->map = my_str_to_word_array(map->buffer);
    if (close(map->fd) == -1)
        return (84);
    return (0);
}

int destroy_world(all_t *all)
{
    my_free_char_tab(all->world.map, 260);
    free(all->world.buffer);
    return (0);
}