/*
** EPITECH PROJECT, 2020
** rpg
** File description:
** spell.c
*/

#include "../../include/my_rpg.h"

void event_spell_bis(all_t *all)
{
    if (((all->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyNum3) == 1) ||
    sfJoystick_isButtonPressed(0, 4) == sfTrue) && all->colspell3 == 0) {
        set_pos(&all->spelloverlay[3], 752, 1005);
        spell_tree(all);
        add_particle_bis(&all->particle_environment, all->particle, 6, pp);
        all->s = 3;
        all->colpart[2] = 2;
    }
    if (((all->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyNum4) == 1) ||
    sfJoystick_isButtonPressed(0, 5) == sfTrue) && all->colspell4 == 0 &&
    all->p.mana >= 100) {
        set_pos(&all->spelloverlay[3], 812, 1005);
        spell_four(all);
        add_particle_bis(&all->particle_environment, all->particle, 6, pp);
        all->s = 4;
        all->colpart[3] = 2;
    }
}

void event_spell(all_t *all)
{
    if (((all->event.type == sfEvtKeyPressed &&
        sfKeyboard_isKeyPressed(sfKeySpace) == 1) ||
        sfJoystick_isButtonPressed(0, 0) == sfTrue) && all->collattack == 0) {
            attack(all);
            all->p.finish = 1;
    }
    if (((all->event.type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyNum1) == 1) ||
    sfJoystick_isButtonPressed(0, 6) == sfTrue) && all->colspell1 == 0 &&
    all->p.mana >= 100) {
        set_pos(&all->spelloverlay[3], 632, 1005);
        spell_one(all);
        add_particle(&all->particle_environment_bis, all->particle_bis, 25, pp);
        all->s = 1;
        all->colpart[0] = 2;
    }
    even_spellb(all);
    event_spell_bis(all);
}

void init_spell_bis(all_t *all, int a, char **info)
{
    all->spell[a].id = my_atoi(info[0]);
    all->spell[a].damage = my_atoi(info[1]);
    all->spell[a].range = my_atoi(info[2]);
    all->spell[a].cooldown.nbr = my_atoi(info[3]);
    all->spell[a].cooldown.text = sfText_create();
    all->spell[a].cooldown.my_font =
    sfFont_createFromFile("assets/Alamak.ttf");
    sfText_setFont(all->spell[a].cooldown.text,
    all->spell[a].cooldown.my_font);
}

int init_spell(all_t *all)
{
    unsigned long len;
    char *buffer = NULL;
    char **info;
    int i;

    FILE *fd = fopen("assets/spell.txt", "r");
    for (int a = 0; getline(&buffer, &len, fd) != -1; a++) {
        if (a >= 4) break;
        info = my_str_to_word_array2(buffer, ':');
        init_spell_bis(all, a, info);
        my_strcpy(all->spell[a].cooldown.str, info[3]);
        for (i = 0; info[i] != NULL; i++)
            free(info[i]);
        free(info);
    }
    free(buffer);
    fclose(fd);
    init_spell_lvl(all);
    return (0);
}

void init_spell_lvl(all_t *all)
{
    for (int i = 0; i < INDEX_SPELL; i++) {
        all->spell_lvl[i].nbr = 1;
        my_int_str(all->spell_lvl[i].str, all->spell_lvl[i].nbr);
        all->spell_lvl[i].text = sfText_create();
        all->spell_lvl[i].my_font = sfFont_createFromFile("assets/Alamak.ttf");
        sfText_setFont(all->spell_lvl[i].text, all->spell_lvl[i].my_font);
        sfText_setString(all->spell_lvl[i].text, all->spell_lvl[i].str);
        sfText_setColor(all->spell_lvl[i].text, sfBlack);
        sfText_setCharacterSize(all->spell_lvl[i].text, 20);
        all->spell_lvl[i].position.x = 1227;
        all->spell_lvl[i].position.y = 580;
        sfText_setPosition(all->spell_lvl[i].text, all->spell_lvl[i].position);
    }
    all->spell_lvl[1].position.x = 1380;
    all->spell_lvl[2].position.y = 707;
    all->spell_lvl[3].position.x = 1380;
    all->spell_lvl[3].position.y = 707;
    sfText_setPosition(all->spell_lvl[1].text, all->spell_lvl[1].position);
    sfText_setPosition(all->spell_lvl[2].text, all->spell_lvl[2].position);
    sfText_setPosition(all->spell_lvl[3].text, all->spell_lvl[3].position);
}