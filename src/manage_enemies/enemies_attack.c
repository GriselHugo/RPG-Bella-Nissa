/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** ennemies_attack
*/

#include "../../include/rpg.h"

void attack_player(charac_t *player, entity_t *ennemy, game_t *game)
{
    player->time = sfClock_getElapsedTime(player->ivcblt);
    player->seconds = player->time.microseconds / 1000000.0;
    if (player->seconds > 1) {
        sfClock_restart(player->ivcblt);
        sfClock_restart(player->effect);
        player->health -= ennemy->damage;
        sfSprite_setColor(player->sprite, sfRed);
        heal_bar_change(game, ennemy->damage);
    }
}

float get_distance(charac_t *player, entity_t *ennemy)
{
    sfFloatRect plr_rect = sfSprite_getGlobalBounds(player->sprite);
    sfFloatRect enn_rect = sfSprite_getGlobalBounds(ennemy->sprite);
    sfVector2f plr_mid = {player->pos.x + plr_rect.width / 2,
    player->pos.y + plr_rect.height / 2};
    sfVector2f enn_mid = {ennemy->pos.x + enn_rect.width / 2,
    ennemy->pos.y + enn_rect.height / 2};
    float distance = abs(sqrtf(powf(plr_mid.x - enn_mid.x, 2) +
    powf(plr_mid.y - enn_mid.y, 2)));
    return (distance);
}
