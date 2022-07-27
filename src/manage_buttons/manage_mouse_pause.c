/*
** EPITECH PROJECT, 2022
** manage_mouse_sound.c
** File description:
** manage_mouse_sound
*/

#include "../../include/rpg.h"

void manage_pause_quit_button(game_t *game, sfVector2i mouse_pos)
{
    sfFloatRect hitbox_quit = {game->pause.quit.pos.x,
    game->pause.quit.pos.y, 180, 70};
    if (sfFloatRect_contains(&hitbox_quit, mouse_pos.x, mouse_pos.y)) {
        game->pause.quit.rect.top = 70;
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->pause.quit.rect.top = 70 * 2;
            game->pause.quit.status = 1;
        }
        if (game->event.type == sfEvtMouseButtonReleased &&
        game->pause.quit.status == 1)
            sfRenderWindow_close(game->window);
    } else {
        game->pause.quit.rect.top = 0;
        game->pause.quit.status = 0;
    }
    sfSprite_setTextureRect(game->pause.quit.sprite,
    game->pause.quit.rect);
}

void manage_pause_resume_button(game_t *game, sfVector2i mouse_pos)
{
    sfFloatRect hitbox_resume = {game->pause.resume.pos.x,
    game->pause.resume.pos.y, 260, 70};
    if (sfFloatRect_contains(&hitbox_resume, mouse_pos.x, mouse_pos.y)) {
        game->pause.resume.rect.top = 70;
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->pause.resume.rect.top = 70 * 2;
            game->pause.resume.status = 1;
        }
        if (game->event.type == sfEvtMouseButtonReleased &&
        game->pause.resume.status == 1)
            game->state = PLAY;
    } else {
        game->pause.resume.rect.top = 0;
        game->pause.resume.status = 0;
    }
    sfSprite_setTextureRect(game->pause.resume.sprite,
    game->pause.resume.rect);
}

void manage_pause_menu_button(game_t *game, sfVector2i mouse_pos)
{
    sfFloatRect hitbox_menu = {game->pause.menu.pos.x,
    game->pause.menu.pos.y, 180, 70};
    if (sfFloatRect_contains(&hitbox_menu, mouse_pos.x, mouse_pos.y)) {
        game->pause.menu.rect.top = 70;
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->pause.menu.rect.top = 70 * 2;
            game->pause.menu.status = 1;
        }
        if (game->event.type == sfEvtMouseButtonReleased &&
        game->pause.menu.status == 1) {
            game->state = MENU;
            sfMusic_stop(game->explo_m);
            sfMusic_play(game->menu.music);
        }
    } else {
        game->pause.menu.rect.top = 0;
        game->pause.menu.status = 0;
    }
    sfSprite_setTextureRect(game->pause.menu.sprite,
    game->pause.menu.rect);
}

void manage_pause_settings_button(game_t *game, sfVector2i mouse_pos)
{
    sfFloatRect hitbox_settings = {game->pause.settings.pos.x,
    game->pause.settings.pos.y, 340, 70};
    if (sfFloatRect_contains(&hitbox_settings, mouse_pos.x, mouse_pos.y)) {
        game->pause.settings.rect.top = 70;
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->pause.settings.rect.top = 70 * 2;
            game->pause.settings.status = 1;
        }
        if (game->event.type == sfEvtMouseButtonReleased &&
        game->pause.settings.status == 1) {
            game->state = SETTINGS;
            sfSound_setVolume(game->sound.click, game->soundvol);
            sfSound_play(game->sound.click);
        }
    } else {
        game->pause.settings.rect.top = 0;
        game->pause.settings.status = 0;
    }
    sfSprite_setTextureRect(game->pause.settings.sprite,
    game->pause.settings.rect);
}
