/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** loading_screen
*/

#include "../../include/rpg.h"

void manage_loading(game_t *game)
{
    if (game->nextload == L_NONE)
        return;
    game->loading.time = sfClock_getElapsedTime(game->loading.clock);
    game->loading.seconds = game->loading.time.microseconds / 1000000.0;
    game->state = LOADING;
    if (game->loading.seconds >= 0.1) {
        sfClock_destroy(game->loading.clock);
        if (game->nextload == L_NICE) {
            game->nextload = L_NONE;
            game->state = PLAY;
            game->play = assign_play_s(game);
        }
    }
}
