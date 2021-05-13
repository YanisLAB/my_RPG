/*
** EPITECH PROJECT, 2020
** B-MUL-200-MPL-2-1-myrpg-yanis.labchiri
** File description:
** init.c
*/

#include "../../include/my_rpg.h"

text_t set_text_quest(int x, int y)
{
    text_t tmp;
    tmp.str[0] = 'a';
    tmp.str[1] = '\0';
    tmp.my_font = sfFont_createFromFile("assets/Alamak.ttf");
    tmp.text = sfText_create();
    sfText_setString(tmp.text, tmp.str);
    sfText_setFont(tmp.text, tmp.my_font);
    sfText_setCharacterSize(tmp.text, 25);
    sfText_setColor(tmp.text, sfWhite);
    sfText_setOutlineColor(tmp.text, sfBlack);
    sfText_setOutlineThickness(tmp.text, 1);
    tmp.position.x = x;
    tmp.position.y = y;
    sfText_setPosition(tmp.text, tmp.position);
    return (tmp);
}

void init_all_bis(all_t *all)
{
    all->keys.down = 18;
    all->keys.up = 22;
    all->keys.left = 0;
    all->keys.right = 3;
    all->keys.inv = 4;
    all->quest = 0;
    all->dial = false;
    all->colpart[0] = 0;
    all->colpart[1] = 0;
    all->colpart[2] = 0;
    all->colpart[3] = 0;
    display_load(all);
    init_music(all);
    display_load(all);
    init_map(all);
    display_load(all);
    init_main_menu(all);
    display_load(all);
    init_inv(all);
    init_bis(all);
}

void set_enter_text(all_t *all)
{
    char *text;
    all->p_enter = set_text_quest(800, 10);
    text = "Press enter for clear the quest";
    my_strcpy(all->p_enter.str, text);
    sfText_setString(all->p_enter.text, all->p_enter.str);
}

void init_all(all_t *all)
{
    for (int i = 0; i < INDEX_USE; i++)
        all->use[i] = sfFalse;
    init_loading(all);
    all->world.read_map = sfFalse;
    all->scene = 0;
    all->last_scene = 0;
    all->keys.change = 0;
    all->controller.sec = 0;
    all->controller.clock = sfClock_create();
    all->time_joy.sec = 0;
    all->time_joy.clock = sfClock_create();
    all->window = sfRenderWindow_create
    (*sfVideoMode_getFullscreenModes(0), "rpg", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(all->window, 60);
    all->clocks.clock = sfClock_create();
    all->coll.clock = sfClock_create();
    init_all_bis(all);
    set_enter_text(all);
}