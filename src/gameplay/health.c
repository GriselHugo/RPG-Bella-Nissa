/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** health
*/

#include "../../include/rpg.h"

void use_potion(game_t *game)
{
    if (game->play.inv.potion.obtained == false)
        return;
    game->play.perso.time = sfClock_getElapsedTime(
    game->play.perso.potion_cldwn);
    game->play.perso.seconds = game->play.perso.time.microseconds / 1000000.0;
    if (game->play.perso.seconds > 90) {
        game->play.perso.health += 50;
        if (game->play.perso.health >= 100) {
            heal_bar_change(game, -(50 - (game->play.perso.health - 100)));
            game->play.perso.health = 100;
        } else
            heal_bar_change(game, -50);
        sfSprite_setColor(game->play.perso.sprite, sfGreen);
        sfClock_restart(game->play.perso.effect);
        sfClock_restart(game->play.perso.potion_cldwn);
    }
}

void is_alive(game_t *game)
{
    if (game->play.perso.health <= 0) {
        sfMusic_stop(game->explo_m);
        sfMusic_play(game->menu.music);
        game->state = MENU;
    }
}

void heal_bar_change(game_t *game, float damage)
{
    game->play.perso.rect_hp.width -= damage * 5;
    sfSprite_setTextureRect(game->play.perso.hp.sprite,
    game->play.perso.rect_hp);
}
