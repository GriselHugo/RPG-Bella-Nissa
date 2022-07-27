/*
** EPITECH PROJECT, 2022
** destroy_struct_3.c
** File description:
** destroy struct for rpg
*/

#include "../../include/rpg.h"

void destroy_musics(sound_t *sound)
{
    sfSound_destroy(sound->heal);
    sfSound_destroy(sound->quest);
    sfSoundBuffer_destroy(sound->heal_b);
    sfSoundBuffer_destroy(sound->quest_b);
}
