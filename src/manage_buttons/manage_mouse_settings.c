/*
** EPITECH PROJECT, 2022
** manage_mouse_sound.c
** File description:
** manage_mouse_sound
*/

#include "../../include/rpg.h"

void manage_game_music_minus_button(game_t *game, sfVector2i mouse_pos)
{
    sfFloatRect hitbox_m_m = {game->option.musicminus.pos.x,
    game->option.musicminus.pos.y, 80, 80};
    if (sfFloatRect_contains(&hitbox_m_m, mouse_pos.x, mouse_pos.y)) {
        game->option.musicminus.rect.top = 80;
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->option.musicminus.rect.top = 80 * 2;
            game->option.musicminus.status = 1;
        }
        if (game->event.type == sfEvtMouseButtonReleased &&
        game->option.musicminus.status == 1) {
            change_volume(game, 'm', -10);
            sfMusic_setVolume(game->explo_m, game->musicvol);
            game->option.musicminus.status = 0;
        }
    } else {
        game->option.musicminus.rect.top = 0;
        game->option.musicminus.status = 0;
    }
    sfSprite_setTextureRect(game->option.musicminus.sprite,
    game->option.musicminus.rect);
}

void manage_game_music_plus_button(game_t *game, sfVector2i mouse_pos)
{
    sfFloatRect hitbox_m_p = {game->option.musicplus.pos.x,
    game->option.musicplus.pos.y, 80, 80};
    if (sfFloatRect_contains(&hitbox_m_p, mouse_pos.x, mouse_pos.y)) {
        game->option.musicplus.rect.top = 80;
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->option.musicplus.rect.top = 80 * 2;
            game->option.musicplus.status = 1;
        }
        if (game->event.type == sfEvtMouseButtonReleased &&
        game->option.musicplus.status == 1) {
            change_volume(game, 'm', 10);
            sfMusic_setVolume(game->explo_m, game->musicvol);
            game->option.musicplus.status = 0;
        }
    } else {
        game->option.musicplus.rect.top = 0;
        game->option.musicplus.status = 0;
    }
    sfSprite_setTextureRect(game->option.musicplus.sprite,
    game->option.musicplus.rect);
}

void manage_back_to_game_button(game_t *game, sfVector2i mouse_pos)
{
    sfFloatRect hitbox_back = {game->option.back.pos.x,
    game->option.back.pos.y, 80, 80};
    if (sfFloatRect_contains(&hitbox_back, mouse_pos.x, mouse_pos.y)) {
        game->option.back.rect.top = 80;
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->option.back.rect.top = 80 * 2;
            game->option.back.status = 1;
        }
        if (game->event.type == sfEvtMouseButtonReleased &&
        game->option.back.status == 1) {
            game->state = PLAY;
        }
    } else {
        game->option.back.rect.top = 0;
        game->option.back.status = 0;
    }
    sfSprite_setTextureRect(game->option.back.sprite,
    game->option.back.rect);
}
