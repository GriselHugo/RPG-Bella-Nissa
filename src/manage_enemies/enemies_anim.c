/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** ennemies_anim
*/

#include "../../include/rpg.h"

bool ennemy_can_move_hori(entity_t *entity, game_t *game, sfVector2f pos,
int dir)
{
    if (dir == LEFT) {
        sfColor color_px = sfImage_getPixel(game->play.map_bw_img,
        pos.x - 32 , pos.y);
        int color = sfColor_toInteger(color_px);
        if (color == 0)
            return false;
    }
    if (dir == RIGHT) {
        sfColor color_px = sfImage_getPixel(game->play.map_bw_img,
        pos.x + 32, pos.y);
        int color = sfColor_toInteger(color_px);
        if (color == game->black)
            return false;
    }
    return true;
}

bool ennemy_can_move(entity_t *entity, game_t *game, int dir)
{
    unsigned int pos_x = (game->play.map_rct.left + entity->pos.x) + 31;
    unsigned int pos_y = (game->play.map_rct.top + entity->pos.y) + 31;
    if (dir == FORWARD) {
        sfColor color_px = sfImage_getPixel(game->play.map_bw_img, pos_x,
        pos_y - 10);
        int color = sfColor_toInteger(color_px);
        if (color == game->black)
            return false;
    }
    if (dir == BACKWARD) {
        sfColor color_px = sfImage_getPixel(game->play.map_bw_img, pos_x,
        pos_y + 60);
        int color = sfColor_toInteger(color_px);
        if (color == game->black)
            return false;
    }
    if (!ennemy_can_move_hori(entity, game, (sfVector2f) {pos_x, pos_y}, dir))
        return false;
    else
        return true;
}

void anim_ennemy(entity_t *ennemy)
{
    ennemy->time = sfClock_getElapsedTime(ennemy->clock);
    ennemy->seconds = ennemy->time.microseconds / 1000000.0;
    if (ennemy->seconds > 0.1) {
        move_rect(&ennemy->rect, 64, 255);
        sfClock_restart(ennemy->clock);
    }
    sfSprite_setTextureRect(ennemy->sprite, ennemy->rect);
}

void draw_ennemies(game_t *game, list *renderl)
{
    for (; renderl != NULL; renderl = renderl->next) {
        if (is_in_window((entity_t *) {renderl->value}->pos) && (entity_t *)
        {renderl->value}->type != DEAD) {
            sfRenderWindow_drawSprite((sfRenderWindow *) game->window,
            ((entity_t *) {renderl->value})->sprite, NULL);
        }
    }
}
