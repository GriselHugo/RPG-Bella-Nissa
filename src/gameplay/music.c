/*
** EPITECH PROJECT, 2022
** music.c
** File description:
** Music management file for rpg project
*/

#include "../../include/rpg.h"

void music(game_t *game)
{
    if (game->state == MENU) {
        sfMusic_play(game->menu.music);
    }
}

void change_volume(game_t *game, char channel, int vol)
{
    char str[4];
    if (channel == 'm') {
        game->musicvol += vol;
        if (game->musicvol < 0)
            game->musicvol = 0;
        else if (game->musicvol > 100)
            game->musicvol = 100;
        sfText_setString(game->option.music, my_itoa(game->musicvol, str));
    }
    if (channel == 's') {
        game->soundvol += vol;
        if (game->soundvol < 0)
            game->soundvol = 0;
        else if (game->soundvol > 100)
            game->soundvol = 100;
        sfText_setString(game->option.sound, my_itoa(game->soundvol, str));
    }
}

void fight_management(game_t *game, entity_t *ennemy, float distance)
{
    sfMusic_setVolume(game->play.fight_m, game->musicvol);
    if (distance <= ennemy->range && distance >= 35 &&
        ennemy->type != DEAD) {
            game->play.fight = true;
            return;
    } else {
        game->play.fight = false;
    }
}
