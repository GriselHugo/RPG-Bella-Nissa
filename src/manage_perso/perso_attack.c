/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** perso_attack
*/

#include "../../include/rpg.h"

void show_sword_sprite(game_t *game)
{
    game->play.perso.atk.attckng = true;
    game->play.perso.atk.clock = sfClock_create();
    sfSprite_setPosition(game->play.perso.atk.sprite, (sfVector2f) {
    game->play.perso.pos.x + game->play.perso.rect.width / 2,
    game->play.perso.pos.y + game->play.perso.rect.height / 2});
    if (game->play.perso.move == FORWARD) {
        sfSprite_move(game->play.perso.atk.sprite, (sfVector2f) {0, 45});
        sfSprite_setRotation(game->play.perso.atk.sprite, -90);
    }
    if (game->play.perso.move == BACKWARD) {
        sfSprite_move(game->play.perso.atk.sprite, (sfVector2f) {35, 30});
        sfSprite_setRotation(game->play.perso.atk.sprite, 90);
    }
    if (game->play.perso.move == LEFT) {
        sfSprite_move(game->play.perso.atk.sprite, (sfVector2f) {10, 60});
        sfSprite_setRotation(game->play.perso.atk.sprite, 180);
    }
    if (game->play.perso.move == RIGHT) {
        sfSprite_move(game->play.perso.atk.sprite, (sfVector2f) {30, 0});
        sfSprite_setRotation(game->play.perso.atk.sprite, 0);
    }
}

void knockback(charac_t *player, entity_t *ennemy)
{
    if (player->move == FORWARD) {
        sfSprite_move(ennemy->sprite, (sfVector2f){0, -150});
        ennemy->pos.y -= 150;
    }
    if (player->move == BACKWARD) {
        sfSprite_move(ennemy->sprite, (sfVector2f){0, 150});
        ennemy->pos.y += 150;
    }
    if (player->move == LEFT) {
        sfSprite_move(ennemy->sprite, (sfVector2f){-150, 0});
        ennemy->pos.x -= 150;
    }
    if (player->move == RIGHT) {
        sfSprite_move(ennemy->sprite, (sfVector2f){150, 0});
        ennemy->pos.x += 150;
    }
}

bool check_orientation(charac_t *perso, entity_t *ennemy)
{
    if (perso->move == FORWARD && ennemy->pos.y <= perso->pos.y)
        return (true);
    if (perso->move == BACKWARD && ennemy->pos.y >= perso->pos.y)
        return (true);
    if (perso->move == LEFT && ennemy->pos.x <= perso->pos.x)
        return (true);
    if (perso->move == RIGHT && ennemy->pos.x >= perso->pos.x)
        return (true);
    return (false);
}

void is_hit(game_t *game, list *ennemies, float dist)
{
    if (dist <= 110 && check_orientation(&game->play.perso, ennemies->value)) {
        (entity_t *) {ennemies->value}->health -= game->play.perso.damage;
        knockback(&game->play.perso, ennemies->value);
        if ((entity_t *) {ennemies->value}->health <= 0) {
            game->play.perso.kill++;
            (entity_t *) {ennemies->value}->type = DEAD;
        }
    }
}

void perso_attack(game_t *game)
{
    float distance;
    game->play.perso.time = sfClock_getElapsedTime(
    game->play.perso.attck_cldwn);
    game->play.perso.seconds = game->play.perso.time.microseconds / 1000000.0;
    if (game->play.perso.seconds < 0.3 || game->play.inv.gun.obtained == false)
        return;
    list *attacklst = game->play.ennemy;
    list *attackboss = game->play.boss;
    show_sword_sprite(game);
    for (; attacklst != NULL; attacklst = attacklst->next) {
        distance = get_distance(&game->play.perso, attacklst->value);
        is_hit(game, attacklst, distance);
    }
    for (;attackboss != NULL; attackboss = attackboss->next) {
        distance = get_distance(&game->play.perso,attackboss->value);
        is_hit(game, attackboss, distance);
    }
    sfClock_restart(game->play.perso.attck_cldwn);
}
