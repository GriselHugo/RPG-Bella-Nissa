/*
** EPITECH PROJECT, 2022
** set foreground
** File description:
** for rpg
*/

#include "../../include/rpg.h"

void set_foreground_transparenty(game_t *game, int color)
{
    if (color == sfColor_toInteger(sfGreen))
        sfSprite_setColor(game->play.details_s, TRANSPARENT);
    else
        sfSprite_setColor(game->play.details_s, BASE);
}
