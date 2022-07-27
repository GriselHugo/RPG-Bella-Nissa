/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** scenes
*/

#include "../../include/rpg.h"

void nice_to_mcdo(game_t *game)
{
    game->play.map_tex = game->play.mcdo_t;
    sfSprite_setTexture(game->play.map_spr, game->play.map_tex, sfFalse);
    game->play.pos_nice = sfSprite_getPosition(game->play.perso.sprite);
    game->play.nice_rct = game->play.map_rct;
    game->play.map_rct = game->play.mcdo_rct;
    game->play.perso.pos = game->play.pos_mcdo;
    game->play.map_bw_img = game->play.mcdo_bw;
    game->play.map_x = game->play.mcdo_x;
    game->play.map_y = game->play.mcdo_y;
    sfSprite_setPosition(game->play.perso.sprite, game->play.perso.pos);
    sfSprite_setTextureRect(game->play.map_spr, game->play.map_rct);
    game->play.scene = S_MCDO;
    game->play.change_scn = true;
}

void mcdo_to_nice(game_t *game)
{
    game->play.map_tex = game->play.nice_tex;
    sfSprite_setTexture(game->play.map_spr, game->play.map_tex, sfFalse);
    game->play.pos_mcdo = sfSprite_getPosition(game->play.perso.sprite);
    game->play.mcdo_rct = game->play.map_rct;
    game->play.map_rct = game->play.nice_rct;
    game->play.perso.pos = game->play.pos_nice;
    game->play.map_bw_img = game->play.nice_bw;
    game->play.map_x = game->play.nice_x;
    game->play.map_y = game->play.nice_y;
    sfSprite_setPosition(game->play.perso.sprite,game->play.perso.pos);
    sfSprite_setTextureRect(game->play.map_spr, game->play.map_rct);
    change_weather(&game->play.weather, -1);
    game->play.scene = S_NICE;
    game->play.change_scn = true;
}

void nice_to_epitech(game_t *game)
{
    game->play.map_tex = game->play.epitech_tex;
    sfSprite_setTexture(game->play.map_spr, game->play.map_tex, sfFalse);
    game->play.pos_nice = sfSprite_getPosition(game->play.perso.sprite);
    game->play.nice_rct = game->play.map_rct;
    game->play.map_rct = game->play.epitech_rct;
    game->play.perso.pos = game->play.pos_epitech;
    game->play.map_bw_img = game->play.epitech_bw;
    game->play.map_x = game->play.epitech_x;
    game->play.map_y = game->play.epitech_y;
    sfSprite_setPosition(game->play.perso.sprite, game->play.perso.pos);
    sfSprite_setTextureRect(game->play.map_spr, game->play.map_rct);
    game->play.scene = S_EPI;
    game->play.change_scn = true;
}

void epitech_to_nice(game_t *game)
{
    game->play.map_tex = game->play.nice_tex;
    sfSprite_setTexture(game->play.map_spr, game->play.map_tex, sfFalse);
    game->play.pos_epitech = sfSprite_getPosition(game->play.perso.sprite);
    game->play.epitech_rct = game->play.map_rct;
    game->play.map_rct = game->play.nice_rct;
    game->play.perso.pos = game->play.pos_nice;
    game->play.map_bw_img = game->play.nice_bw;
    game->play.map_x = game->play.nice_x;
    game->play.map_y = game->play.nice_y;
    sfSprite_setPosition(game->play.perso.sprite, game->play.perso.pos);
    sfSprite_setTextureRect(game->play.map_spr, game->play.map_rct);
    game->play.scene = S_NICE;
    game->play.change_scn = true;
    change_weather(&game->play.weather, -1);
}

void change_scene(game_t *game)
{
    unsigned int pos_x = (game->play.map_rct.left + game->play.perso.pos.x)+31;
    unsigned int pos_y = (game->play.map_rct.top + game->play.perso.pos.y)+ 64;
    sfColor pixel = sfImage_getPixel(game->play.map_bw_img, pos_x, pos_y);
    int color = sfColor_toInteger(pixel);
    if (color == game->red && game->play.change_scn == false) {
        if (game->play.scene == S_NICE)
            nice_to_mcdo(game);
        else
            mcdo_to_nice(game);
    }
    if (color == game->blue && game->play.change_scn == false) {
        if (game->play.scene == S_NICE)
            nice_to_epitech(game);
        else
            epitech_to_nice(game);
    }
    if (color == game->white)
        game->play.change_scn = false;
    set_foreground_transparenty(game, color);
}
