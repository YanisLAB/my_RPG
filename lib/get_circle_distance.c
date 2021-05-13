/*
** EPITECH PROJECT, 2020
** rpg_repo
** File description:
** get_circle_distance.c
*/

#include "../include/my_rpg.h"

float get_distance(int cx, int cy, int x, int y)
{
    float xdist = x - cx;
    float ydist = y - cy;

    float res = sqrtf(pow(xdist, 2) + pow(ydist, 2));
    return (res);
}