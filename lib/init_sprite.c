/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_sprite.c
*/

#include "../include/my_rpg.h"

sprite_t init_sprite(sfIntRect rect, char *path)
{
    sprite_t sprite;
    sprite.rect = rect;
    sprite.texture = sfTexture_createFromFile(path, NULL);
    sfTexture_setRepeated(sprite.texture, sfTrue);
    sprite.sprite = sfSprite_create();
    sfSprite_setTexture(sprite.sprite, sprite.texture, sfFalse);
    sfSprite_setTextureRect(sprite.sprite, sprite.rect);
    return (sprite);
}

void move_rect(sfIntRect *rect, float offset, float offset2)
{
    rect->left += offset;
    rect->top -= offset2;
}

void destroy_sprite(sprite_t *sprite)
{
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
}

void display_sprite(sfRenderWindow *window, sprite_t *sprite,
                    float offset, float offset2)
{
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    move_rect(&sprite->rect, offset, offset2);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfRenderWindow_drawSprite(window, sprite->sprite, NULL);
}

void set_pos(sprite_t *sprite, int x, int y)
{
    sprite->position.x = x;
    sprite->position.y = y;
    sfSprite_setPosition(sprite->sprite, sprite->position);
}