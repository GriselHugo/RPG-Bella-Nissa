/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** render_play
*/

#include "../../include/rpg.h"

void render_nice(game_t *game)
{
    list *renderl = game->play.ennemy, *renderNpc = game->play.npc, *renderCar = game->play.cars;
    list *bossl = game->play.boss, *renderOld = game->play.old_npc;
    sfRenderWindow_drawSprite(game->window, game->play.map_spr, NULL);
    sfRenderWindow_drawSprite(game->window, game->play.sea_spr, NULL);
    draw_npc(game, renderNpc); draw_ennemies(game, renderl);
    draw_boss(game,bossl);
    draw_olds(game, renderOld);
    sfRenderWindow_drawSprite(game->window, game->play.perso.sprite, NULL);
    render_car(game, renderCar);
    sfRenderWindow_drawSprite(game->window, game->play.details_s, NULL);
    if (game->play.inv.pizza != true)
        sfRenderWindow_drawSprite(game->window,game->play.pizza_s, NULL);
    if (game->play.perso.atk.attckng == true) {
        sfRenderWindow_drawSprite(game->window,
        game->play.perso.atk.sprite, NULL);
    }
    check_display_inv(game);
    sfRenderWindow_drawSprite(game->window, game->play.perso.health_bar.sprite,
    NULL);
    sfRenderWindow_drawSprite(game->window,game->play.perso.hp.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->play.weather.sprite, NULL);
}

void render_mcdo(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->play.map_spr, NULL);
    sfRenderWindow_drawSprite(game->window, game->play.perso.sprite, NULL);
    if (game->play.perso.atk.attckng == true) {
        sfRenderWindow_drawSprite(game->window,
        game->play.perso.atk.sprite, NULL);
    }
    check_display_inv(game);
    sfRenderWindow_drawSprite(game->window, game->play.perso.health_bar.sprite,
    NULL);
    sfRenderWindow_drawSprite(game->window,game->play.perso.hp.sprite, NULL);
}

void render_epitech(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->play.map_spr, NULL);
    sfRenderWindow_drawSprite(game->window, game->play.perso.sprite, NULL);
    if (game->play.perso.atk.attckng == true) {
        sfRenderWindow_drawSprite(game->window,
        game->play.perso.atk.sprite, NULL);
    }
    check_display_inv(game);
    sfRenderWindow_drawSprite(game->window, game->play.perso.health_bar.sprite,
    NULL);
    sfRenderWindow_drawSprite(game->window,game->play.perso.hp.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->damien.sprite, NULL);
}

void render_credits(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->play.credits.sprite, NULL);
    sfRenderWindow_drawText(game->window, game->play.credits.text, NULL);
}
