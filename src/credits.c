/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** credits
*/

#include "../include/rpg.h"

void credits_loop(credits_t *credits, game_t *game)
{
    if (game->play.scene != S_CREDITS)
        return;
    credits->time = sfClock_getElapsedTime(credits->clock);
    credits->seconds = credits->time.microseconds / 1000000.0;
    if (credits->rect.top + credits->rect.height >= 2160 || credits->skip ==
    true) {
        game->state = MENU;
        return;
    }
    if (credits->seconds > 0.01) {
        credits->rect.top += 2;
        sfSprite_setTextureRect(credits->sprite, credits->rect);
        sfClock_restart(credits->clock);
    }
}
