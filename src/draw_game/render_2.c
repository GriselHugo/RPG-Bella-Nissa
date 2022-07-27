/*
** EPITECH PROJECT, 2022
** render_2.c
** File description:
** render the game
*/

#include "../../include/rpg.h"

void draw_pause(game_t *game)
{
    list *renderl = game->play.ennemy; list *renderNpc = game->play.npc;
    list *bossl = game->play.boss;
    sfRenderWindow_drawSprite(game->window, game->play.map_spr, NULL);
    draw_npc(game, renderNpc); draw_ennemies(game, renderl);
    draw_boss(game,bossl);
    if (game->play.scene == S_EPI)
        sfRenderWindow_drawSprite(game->window, game->damien.sprite, NULL);
    sfRenderWindow_drawSprite(game->window,game->play.perso.sprite, NULL);
    if (game->play.scene == S_NICE) {
        sfRenderWindow_drawSprite(game->window, game->play.weather.sprite,
        NULL);
        sfRenderWindow_drawSprite(game->window , game->play.details_s, NULL);
    }
    sfRenderWindow_drawSprite(game->window, game->pause.menu.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->pause.resume.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->pause.quit.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->pause.settings.sprite, NULL);
}

void draw_load(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->loading.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->loading.planet_s, NULL);
}
