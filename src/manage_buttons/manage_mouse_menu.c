/*
** EPITECH PROJECT, 2022
** manage_mouse_menu.c
** File description:
** manage_mouse_menu
*/

#include "../../include/rpg.h"

void manage_play_button(game_t *game, sfVector2i mouse_pos)
{
    sfFloatRect hitbox_play = {game->menu.play.pos.x,
    game->menu.play.pos.y, 180, 70};
    if (sfFloatRect_contains(&hitbox_play, mouse_pos.x, mouse_pos.y)) {
        game->menu.play.rect.top = 70;
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->menu.play.rect.top = 70 * 2; game->menu.play.status = 1;
        }
        if (game->event.type == sfEvtMouseButtonReleased &&
        game->menu.play.status == 1) {
            sfSound_setVolume(game->sound.click, game->soundvol);
            sfSound_play(game->sound.click);
            sfMusic_stop(game->menu.music); sfMusic_play(game->explo_m);
            sfMusic_setVolume(game->explo_m, game->musicvol);
            game->nextload = L_NICE;
            game->loading.clock = sfClock_create();
        }
    } else {
        game->menu.play.rect.top = 0; game->menu.play.status = 0;
    }
    sfSprite_setTextureRect(game->menu.play.sprite, game->menu.play.rect);
}

void manage_help_button(game_t *game, sfVector2i mouse_pos)
{
    sfFloatRect hitbox_help = {game->menu.help.pos.x,
    game->menu.help.pos.y, 80, 80};
    if (sfFloatRect_contains(&hitbox_help, mouse_pos.x, mouse_pos.y)) {
        game->menu.help.rect.top = 80;
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->menu.help.rect.top = 80 * 2;
            game->menu.help.status = 1;
            game->help = assign_help_s(game);
        }
        if (game->event.type == sfEvtMouseButtonReleased &&
        game->menu.help.status == 1) {
            sfSound_setVolume(game->sound.click, game->soundvol);
            sfSound_play(game->sound.click);
            game->state = HELP;
        }
    } else {
        game->menu.help.rect.top = 0;
        game->menu.help.status = 0;
    }
    sfSprite_setTextureRect(game->menu.help.sprite,game->menu.help.rect);
}

void manage_option_button(game_t *game, sfVector2i mouse_pos)
{
    sfFloatRect hitbox_option = {game->menu.option.pos.x,
    game->menu.option.pos.y, 80, 80};
    if (sfFloatRect_contains(&hitbox_option, mouse_pos.x, mouse_pos.y)) {
        game->menu.option.rect.top = 80;
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->menu.option.rect.top = 80 * 2;
            game->menu.option.status = 1;
        }
        if (game->event.type == sfEvtMouseButtonReleased &&
        game->menu.option.status == 1) {
            game->state = OPTION;
            sfSound_setVolume(game->sound.click, game->soundvol);
            sfSound_play(game->sound.click);
        }
    } else {
        game->menu.option.rect.top = 0;
        game->menu.option.status = 0;
    }
    sfSprite_setTextureRect(game->menu.option.sprite,game->menu.option.rect);
}

void manage_exit_button(game_t *game, sfVector2i mouse_pos)
{
    sfFloatRect hitbox_exit = {game->menu.exit.pos.x,
    game->menu.exit.pos.y, 180, 70};
    if (sfFloatRect_contains(&hitbox_exit, mouse_pos.x, mouse_pos.y)) {
        game->menu.exit.rect.top = 70;
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->menu.exit.rect.top = 70 * 2;
            game->menu.exit.status = 1;
        }
        if (game->event.type == sfEvtMouseButtonReleased &&
        game->menu.exit.status == 1) {
            sfSound_setVolume(game->sound.click, game->soundvol);
            sfSound_play(game->sound.click);
            sfRenderWindow_close(game->window);
        }
    } else {
        game->menu.exit.rect.top = 0;
        game->menu.exit.status = 0;
    }
    sfSprite_setTextureRect(game->menu.exit.sprite,game->menu.exit.rect);
}

void mouse_help(game_t *game, sfVector2i mouse_pos)
{
    sfFloatRect hitbox_back = {game->help.back.pos.x,
    game->help.back.pos.y, 80, 80};
    if (sfFloatRect_contains(&hitbox_back, mouse_pos.x, mouse_pos.y)) {
        game->help.back.rect.top = 80;
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->help.back.rect.top = 80 * 2;
            game->help.back.status = 1;
        }
        if (game->event.type == sfEvtMouseButtonReleased &&
        game->help.back.status == 1) {
            sfSound_setVolume(game->sound.click, game->soundvol);
            sfSound_play(game->sound.click);
            game->state = MENU;
        }
    } else {
        game->help.back.rect.top = 0;
        game->help.back.status = 0;
    }
    sfSprite_setTextureRect(game->help.back.sprite,game->help.back.rect);
    destroy_help(&game->help, game->state);
}
