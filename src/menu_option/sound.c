/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** sound.c
*/

#include "../../include/my_rpg.h"

void init_sound(all_t *all)
{
    all->click.sound = sfSound_create();
    all->click.sbuffer =
    sfSoundBuffer_createFromFile("./assets/click.ogg");
    sfSound_setVolume(all->click.sound, 50);
    sfSound_setBuffer(all->click.sound, all->click.sbuffer);
}

void init_music(all_t *all)
{
    all->volume_music = 10;
    all->volume_sound = 50;
    all->music_game =
    sfMusic_createFromFile("./assets/Zelda__Chill.ogg");
    sfMusic_setVolume(all->music_game, all->volume_music);
    sfMusic_setLoop(all->music_game, sfTrue);
    init_sound(all);
}

void music_volume(all_t *all, int button)
{
    if (button == 2) {
        all->volume_music -= 5;
        all->option[1].rect.width -= 19;
        if (all->option[1].rect.width < 0) {
            all->option[1].rect.width = 0;
            all->volume_music = 0;
        }
    }
    if (button == 1) {
        all->volume_music += 5;
        all->option[1].rect.width += 19;
        if (all->option[1].rect.width > 362)
            all->option[1].rect.width = 362;
    }
    sound_volume(all, button);
    for (int i = 1; i <= 2; i++)
        sfSprite_setTextureRect(all->option[i].sprite, all->option[i].rect);
    sfMusic_setVolume(all->music_game, all->volume_music);
    sfSound_setVolume(all->click.sound, all->volume_sound);
}

void sound_volume(all_t *all, int button)
{
    if (button == 4) {
        all->volume_sound -= 5;
        all->option[2].rect.width -= 19;
        if (all->option[2].rect.width < 0) {
            all->option[2].rect.width = 0;
            all->volume_sound = 0;
        }
    }
    if (button == 3) {
        all->volume_sound += 5;
        all->option[2].rect.width += 19;
        if (all->option[2].rect.width > 362)
            all->option[2].rect.width = 362;
    }
}

void destroy_sound(all_t *all)
{
    sfMusic_stop(all->music_game);
    sfMusic_destroy(all->music_game);
    sfSound_destroy(all->click.sound);
    sfSoundBuffer_destroy(all->click.sbuffer);
}