/*
** EPITECH PROJECT, 2022
** perso_anim_2.c
** File description:
** Everything concerning character here
*/

#include "../../include/rpg.h"

void player_run(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed &&
    game->play.inv.items[2][0] == '1')
        if (game->play.perso.is_running == false) {
            game->play.perso.speed *= 2;
            game->play.perso.is_running = true;
        } else {
            game->play.perso.speed *= 0.5;
            game->play.perso.is_running = false;
        }
}

bool can_move_hori(game_t *game, int pos_x, int pos_y, int black)
{
    if (game->play.perso.move == LEFT) {
        sfColor color_px = sfImage_getPixel(game->play.map_bw_img,
        pos_x - 32 , pos_y);
        int color = sfColor_toInteger(color_px);
        if (color == black)
            return false;
    }
    if (game->play.perso.move == RIGHT) {
        sfColor color_px = sfImage_getPixel(game->play.map_bw_img,
        pos_x + 32, pos_y);
        int color = sfColor_toInteger(color_px);
        if (color == black)
            return false;
    }
    return true;
}
