/*
** EPITECH PROJECT, 2022
** old npc
** File description:
** old pnjs
*/

#include "../../include/rpg.h"

void draw_olds(game_t *game, list *oldNpc)
{
    for (; oldNpc != NULL; oldNpc = oldNpc->next) {
        if (is_in_window((entity_t *) {oldNpc->value}->pos))
            sfRenderWindow_drawSprite(game->window, (entity_t *) {oldNpc->value}->sprite, NULL);
    }
}

void anim_old(game_t *game)
{
    list *oldNpc = game->play.old_npc;
    for (; oldNpc != NULL; oldNpc = oldNpc->next) {
        entity_t *old = oldNpc->value;

        old->time = sfClock_getElapsedTime(old->clock);
        old->seconds = old->time.microseconds / 1000000.0;
        if (old->seconds > 0.2) {
            move_rect(&old->rect, 64, 255);
            sfClock_restart(old->clock);
        }
        sfSprite_setTextureRect(old->sprite, old->rect);
        }
}

entity_t *create_old(game_t *game, int dir, sfVector2f pos)
{
    entity_t *old;
    old = malloc(sizeof(entity_t));
    old->sprite = sfSprite_create();
    old->texture = sfTexture_createFromFile("assets/perso/vieux.png", NULL);
    old->speed = 2;
    old->pos = pos;
    sfSprite_setTexture(old->sprite, old->texture, sfFalse);
    if (dir == RIGHT) {
        old->dir = RIGHT;
        old->rect = set_rect(128, 0 , 64, 64);
        sfSprite_setScale(old->sprite, (sfVector2f) {1.525, 1.525});
        sfSprite_setTextureRect(old->sprite, old->rect);
    } else {
        old->dir = LEFT;
        old->rect = set_rect(64, 0 , 64, 64);
        sfSprite_setScale(old->sprite, (sfVector2f) {1.425, 1.425});
        sfSprite_setTextureRect(old->sprite, (sfIntRect) {0, 64, 64, 64});
    }
    sfSprite_setPosition(old->sprite, old->pos);
    old->clock = sfClock_create();
    return (old);
}

void create_old_list(play_t *play, game_t *game)
{
    play->old_npc = add_end(play->old_npc, create_old(game, RIGHT, (sfVector2f) {320, 300}));
    play->old_npc = add_end(play->old_npc, create_old(game, RIGHT, (sfVector2f) {-620, 350}));
    play->old_npc = add_end(play->old_npc, create_old(game, RIGHT, (sfVector2f) {600, 500}));
    play->old_npc = add_end(play->old_npc, create_old(game, LEFT, (sfVector2f) {1700, 400}));
    play->old_npc = add_end(play->old_npc, create_old(game, LEFT, (sfVector2f) {1400, 600}));
    play->old_npc = add_end(play->old_npc, create_old(game, LEFT, (sfVector2f) {1900, 600}));
}
