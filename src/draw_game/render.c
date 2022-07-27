/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** render different states
*/

#include "../../include/rpg.h"

void draw_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->menu.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.play.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.option.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.exit.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.help.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.select_r.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.select_l.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->menu.preview_s, NULL);
}

void draw_help(game_t *game)
{
    list *renderl = game->help.text;
    sfRenderWindow_drawSprite(game->window, game->help.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->help.back.sprite, NULL);
    sfRenderWindow_drawText(game->window, renderl->value, NULL);
    for (; renderl != NULL; renderl = renderl->next) {
        sfRenderWindow_drawText(game->window, renderl->value, NULL);
    }
}

void draw_option(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->option.sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->option.back.sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->option.musicminus.sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->option.musicplus.sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->option.soundminus.sprite, NULL);
    sfRenderWindow_drawSprite(game->window,
    game->option.soundplus.sprite, NULL);
    sfRenderWindow_drawText(game->window, game->option.music, NULL);
    sfRenderWindow_drawText(game->window, game->option.sound, NULL);
}

void draw_game(game_t *game)
{
    if (game->play.scene == S_NICE)
        render_nice(game);
    if (game->play.scene == S_MCDO)
        render_mcdo(game);
    if (game->play.scene == S_EPI)
        render_epitech(game);
    if (game->play.scene == S_CREDITS)
        render_credits(game);
}
