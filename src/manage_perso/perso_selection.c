/*
** EPITECH PROJECT, 2022
** perso_selection.c
** File description:
** Select perso in menu
*/

#include "../../include/rpg.h"

sfTexture *assign_texture(game_t *game)
{
    sfTexture *texture;
    if (game->index == 0)
        texture = sfTexture_createFromFile("assets/perso/romain.png", NULL);
    if (game->index == 1)
        texture = sfTexture_createFromFile("assets/perso/grizou.png", NULL);
    if (game->index == 2)
        texture = sfTexture_createFromFile("assets/perso/jeremy.png", NULL);
    if (game->index == 3)
        texture = sfTexture_createFromFile("assets/perso/benj.png", NULL);
    return texture;
}

void select_skin(game_t *game, int i)
{
    if (i == 1) {
        game->menu.pre.left += 64;
        game->menu.pre.left == 256 ? game->menu.pre.left = 0 : 0;
        game->index += 1;
        game->index == 4 ? game->index = 0 : 0;
    } else {
        game->menu.pre.left -= 64;
        game->menu.pre.left == -64 ? game->menu.pre.left = 192 : 0;
        game->index -= 1;
        game->index == -1 ? game->index = 3 : 0;
    }
    sfSprite_setTextureRect(game->menu.preview_s,game->menu.pre);
    game->menu.status = 0;
}

void perso_selection(game_t *game, sfVector2i mouse_pos)
{
    sfFloatRect hitbox_back = {game->menu.select_r.pos.x,
    game->menu.select_r.pos.y, 64, 64};
    if (sfFloatRect_contains(&hitbox_back, mouse_pos.x, mouse_pos.y)) {
        game->menu.select_r.rect.top = 80;
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->menu.select_r.rect.top = 80 * 2;
            game->menu.status = 1;
        }
        if (game->event.type == sfEvtMouseButtonReleased &&
        game->menu.status == 1) {
            select_skin(game, 1);
        }
    } else
        game->menu.select_r.rect.top = 0; game->menu.select_r.status = 0;
    sfSprite_setTextureRect(game->menu.select_r.sprite,
    game->menu.select_r.rect);
    perso_selection_back(game, mouse_pos);
}

void perso_selection_back(game_t *game, sfVector2i mouse_pos)
{
    sfFloatRect hitbox_back = {game->menu.select_l.pos.x,
    game->menu.select_l.pos.y, 64, 64};
    if (sfFloatRect_contains(&hitbox_back, mouse_pos.x, mouse_pos.y)) {
        game->menu.select_l.rect.top = 80;
        if (game->event.type == sfEvtMouseButtonPressed) {
            game->menu.select_l.rect.top = 80 * 2;
            game->menu.status = 1;
        }
        if (game->event.type == sfEvtMouseButtonReleased &&
        game->menu.status == 1) {
            select_skin(game, -1);
        }
    } else
        game->menu.select_l.rect.top = 0; game->menu.select_l.status = 0;
    sfSprite_setTextureRect(game->menu.select_l.sprite,
    game->menu.select_l.rect);
}
