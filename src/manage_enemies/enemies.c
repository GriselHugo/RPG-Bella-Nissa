/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** generate_ennemies
*/

#include "../../include/rpg.h"

void move_vertical(entity_t *entity, charac_t *player, game_t *game)
{
    sfFloatRect ent_rect = sfSprite_getGlobalBounds(entity->sprite);
    sfFloatRect plr_rect = sfSprite_getGlobalBounds(player->sprite);
    float player_mid = player->pos.y + plr_rect.height / 2;
    float entity_mid = entity->pos.y + ent_rect.height / 2;
    if (entity_mid < player_mid && player_mid - entity_mid > 1) {
        if (!ennemy_can_move(entity, game, BACKWARD))
            return;
        sfSprite_move(entity->sprite, (sfVector2f) {0, entity->speed});
        entity->pos.y += entity->speed; entity->rect.top = 0;
        anim_ennemy(entity);
        sfSprite_setTextureRect(entity->sprite, entity->rect);
    } else if (entity_mid > player_mid && entity_mid - player_mid > 1) {
        if (!ennemy_can_move(entity, game, FORWARD))
            return;
        sfSprite_move(entity->sprite, (sfVector2f) {0, -entity->speed});
        entity->pos.y -= entity->speed;
        entity->rect.top = 192;
        anim_ennemy(entity);
        sfSprite_setTextureRect(entity->sprite, entity->rect);
    }
}

void move_horizontal(entity_t *entity, charac_t *player, game_t *game)
{
    sfFloatRect ent_rect = sfSprite_getGlobalBounds(entity->sprite);
    sfFloatRect plr_rect = sfSprite_getGlobalBounds(player->sprite);
    float player_mid = player->pos.x + plr_rect.width / 2;
    float entity_mid = entity->pos.x + ent_rect.width / 2;
    if (entity_mid < player_mid && player_mid - entity_mid > 1) {
        sfSprite_move(entity->sprite, (sfVector2f) {entity->speed, 0});
        entity->pos.x += entity->speed;
        entity->rect.top = 128;
        anim_ennemy(entity);
        sfSprite_setTextureRect(entity->sprite, entity->rect);
    } else if (entity_mid > player_mid && entity_mid - player_mid > 1) {
        sfSprite_move(entity->sprite, (sfVector2f) {-entity->speed, 0});
        entity->pos.x -= entity->speed;
        entity->rect.top = 64;
        anim_ennemy(entity);
        sfSprite_setTextureRect(entity->sprite, entity->rect);
    }
}

void move_ennemies_to_player(game_t *game)
{
    list *movel = game->play.ennemy; float distance;
    for (; movel != NULL; movel = movel->next) {
        entity_t *ennemy = movel->value;
        distance = get_distance(&game->play.perso, ennemy);
        fight_management(game, ennemy, distance);
        if (distance <= ennemy->range && distance >= 35 &&
        ennemy->type != DEAD) {
            move_vertical(ennemy, &game->play.perso, game);
            move_horizontal(ennemy, &game->play.perso, game);
        } else if (distance < 35 && ennemy->type != DEAD)
            attack_player(&game->play.perso, ennemy, game);
    }
}

void move_ennemies_wnd(game_t *game, sfVector2f direction)
{
    list *renderl = game->play.ennemy;
    list *renderNpc = game->play.npc;
    list *bossl = game->play.boss;
    list *carsl = game->play.cars;
    list *oldNpc = game->play.old_npc;
    sfSprite_move(game->play.pizza_s, direction);
    game->play.pos_pizza.x += direction.x;
    game->play.pos_pizza.y += direction.y;
    for (; renderNpc != NULL; renderNpc = renderNpc->next) {
        sfSprite_move(((entity_t *) {renderNpc->value})->sprite, direction);
        (entity_t *) {renderNpc->value}->pos.x += direction.x;
        (entity_t *) {renderNpc->value}->pos.y += direction.y;
    }
    for (; renderl != NULL; renderl = renderl->next) {
        if ((entity_t *) {renderl->value}->type != DEAD) {
            sfSprite_move(((entity_t *) {renderl->value})->sprite, direction);
            (entity_t *) {renderl->value}->pos.x += direction.x;
            (entity_t *) {renderl->value}->pos.y += direction.y;
        }
    }
    for (; carsl != NULL; carsl = carsl->next) {
        if ((entity_t *) {carsl->value}->type != DEAD) {
            sfSprite_move(((entity_t *) {carsl->value})->sprite, direction);
            (entity_t *) {carsl->value}->pos.x += direction.x;
            (entity_t *) {carsl->value}->pos.y += direction.y;
        }
    }
    for (; oldNpc != NULL; oldNpc = oldNpc->next) {
        if ((entity_t *) {oldNpc->value}->type != DEAD) {
            sfSprite_move(((entity_t *) {oldNpc->value})->sprite, direction);
            (entity_t *) {oldNpc->value}->pos.x += direction.x;
            (entity_t *) {oldNpc->value}->pos.y += direction.y;
        }
    }
    sfSprite_move(game->play.sea_spr, direction);
    game->play.pos_sea_cur.x += direction.x;
    game->play.pos_sea_cur.y += direction.y;
    game->play.pos_sea_str.x += direction.x;
    game->play.pos_sea_str.y += direction.y;
    game->play.pos_sea_end.x += direction.x;
    game->play.pos_sea_end.y += direction.y;
    move_boss(bossl, direction);
    if (game->play.scene == S_EPI) {
        game->damien.pos.x += direction.x;
        game->damien.pos.y += direction.y;
        sfSprite_move(game->damien.sprite, direction);
    }
}

list *generate_ennemies(game_t *game, char *type)
{
    list *tlst = new_list();
    tlst = create_ennemis_garden(game, tlst);
    tlst = create_ennemis_prom(game, tlst);
    tlst = create_ennemis_place(game, tlst);
    return (tlst);
}
