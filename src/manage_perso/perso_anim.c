/*
** EPITECH PROJECT, 2022
** perso_anim.c
** File description:
** Main character animation
*/

#include "../../include/rpg.h"

void move_boss(list *bossl, sfVector2f direction)
{
    for (; bossl != NULL; bossl = bossl->next) {
        sfSprite_move(((entity_t *) {bossl->value})->sprite, direction);
        (entity_t *) {bossl->value}->pos.x += direction.x;
        (entity_t *) {bossl->value}->pos.y += direction.y;
    }
}

void move_character(game_t *game)
{
    if (!can_move(game)) return;
    if (game->play.perso.move == FORWARD && game->play.perso.pos.y > 0) {
        if (game->play.map_rct.top <= 0 || game->play.perso.pos.y > 450)
            game->play.perso.pos.y -= game->play.perso.speed;
        else {
            game->play.map_rct.top -= game->play.perso.speed;
            move_ennemies_wnd(game, (sfVector2f) {0, game->play.perso.speed});
        }
    }
    if (game->play.perso.move == BACKWARD && game->play.perso.pos.y < 900) {
        if (game->play.map_rct.top + game->play.map_rct.height >=
        game->play.map_y || game->play.perso.pos.y < 550)
            game->play.perso.pos.y += game->play.perso.speed;
        else {
            game->play.map_rct.top += game->play.perso.speed;
            move_ennemies_wnd(game, (sfVector2f) {0, -game->play.perso.speed});
        }
    }
    move_directions(game);
}

void move_directions(game_t *game)
{
    if (game->play.perso.move == LEFT && game->play.perso.pos.x > 0) {
        if (game->play.map_rct.left <= 0 || game->play.perso.pos.x > 850)
            game->play.perso.pos.x -= game->play.perso.speed;
        else {
            game->play.map_rct.left -= game->play.perso.speed;
            move_ennemies_wnd(game, (sfVector2f) {game->play.perso.speed, 0});
        }
    }
    if (game->play.perso.move == RIGHT && game->play.perso.pos.x < 1820) {
        if (game->play.map_rct.left + game->play.map_rct.width >=
        game->play.map_x || game->play.perso.pos.x < 950)
            game->play.perso.pos.x += game->play.perso.speed;
        else {
            game->play.map_rct.left += game->play.perso.speed;
            move_ennemies_wnd(game, (sfVector2f) {-game->play.perso.speed, 0});
        }
    }
}

bool can_move(game_t *game)
{
    int pos_x = (game->play.map_rct.left + game->play.perso.pos.x) + 31;
    unsigned int pos_y = (game->play.map_rct.top + game->play.perso.pos.y)+ 64;
    if (game->play.perso.move == FORWARD) {
        sfColor color_px = sfImage_getPixel(game->play.map_bw_img,
        pos_x, pos_y - 10); int color = sfColor_toInteger(color_px);
        if (color == game->black)
            return false;
    }
    if (game->play.perso.move == BACKWARD) {
        sfColor color_px = sfImage_getPixel(game->play.map_bw_img,
        pos_x, pos_y + 60);
        int color = sfColor_toInteger(color_px);
        if (color == game->black)
            return false;
    }
    if (!can_move_hori(game,pos_x,pos_y,game->black))
        return false;
    else
        true;
    return true;
}

void perso_anim(game_t *game)
{
    sfTime time; float sec;
    move_character(game);
    sfSprite_setTextureRect(game->play.map_spr, game->play.map_rct);
    sfSprite_setTextureRect(game->play.details_s, game->play.map_rct);
    sfSprite_setPosition(game->play.perso.sprite, game->play.perso.pos);
    time = sfClock_getElapsedTime(game->play.perso.clock);
    sec = time.microseconds / 1000000.0;
    if (sec >= 0.2) {
        if (game->play.perso.rect.left == 192)
            game->play.perso.rect.left = 0;
        else {
            game->play.perso.rect.left += 64;
            move_character(game);
            sfClock_restart(game->play.perso.clock);
        }
    }
    change_scene(game);
    sfSprite_setTextureRect(game->play.perso.sprite, game->play.perso.rect);
}
