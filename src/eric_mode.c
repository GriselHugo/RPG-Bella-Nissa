/*
** EPITECH PROJECT, 2022
** eric_mode.c
** File description:
** Set eric mode with full inventory and cheated stats
*/

#include "../include/rpg.h"

void set_eric_mode(game_t *game)
{
    game->play.perso.health = 1000;
    game->play.perso.damage = 1000;
    game->play.perso.resist = 1000;
    game->play.perso.speed = 20;
}
