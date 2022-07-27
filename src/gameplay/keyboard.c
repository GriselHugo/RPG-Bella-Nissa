/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** keyboard
*/

#include "../../include/rpg.h"

void player_move(game_t *game)
{
    switch (game->event.key.code) {
    case sfKeyZ: game->play.perso.move = FORWARD;
                game->play.perso.rect.top = 192;
                perso_anim(game);
        break;
    case sfKeyS: game->play.perso.move = BACKWARD;
                game->play.perso.rect.top = 0;
                perso_anim(game);
        break;
    case sfKeyQ: game->play.perso.move = LEFT; game->play.perso.rect.top = 64;
                perso_anim(game);
        break;
    case sfKeyD: game->play.perso.move = RIGHT;game->play.perso.rect.top = 128;
                perso_anim(game);
        break;
    case sfKeyLShift: player_run(game);
        break;
    }
}

void manage_keyboard_perso(game_t *game)
{
    if (!(game->play.scene == S_CREDITS))
        player_move(game);
    switch (game->event.key.code) {
    case sfKeyF: ciro_quest(game, game->play.npc->value);
                boss_fight(game);
        break;
    case sfKeyL: game->play.scene = S_CREDITS;
        sfMusic_stop(game->explo_m);
        break;
    case sfKeyEnter:
        if (game->play.scene == S_CREDITS)
            game->play.credits.skip = true;
        break;
    }
}
