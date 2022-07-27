/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** play_event
*/

#include "../../include/rpg.h"

void check_pizza(game_t *game)
{
    if (sprite_collision(game->play.perso.sprite, game->play.pizza_s))
        game->play.inv.pizza = true;
}

void manage_sword_sprite(attack_t *attack)
{
    if (attack->attckng == false)
        return;
    attack->time = sfClock_getElapsedTime(attack->clock);
    attack->seconds = attack->time.microseconds / 1000000.0;
    if (attack->seconds > 0.3) {
        attack->attckng = false;
        sfClock_destroy(attack->clock);
    }
}

void mouse_play(game_t *game, sfVector2i mouse_pos)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        perso_attack(game);
    } else if (sfMouse_isButtonPressed(sfMouseRight))
        use_potion(game);
}

void player_remove_color(charac_t *perso)
{
    perso->time = sfClock_getElapsedTime(perso->effect);
    perso->seconds = perso->time.microseconds / 1000000.0;
    if (perso->seconds > 0.3)
        sfSprite_setColor(perso->sprite, BASE);
}

void move_sea(game_t *game) {
    sfTime time = sfClock_getElapsedTime(game->play.sea_clk);
    float seconds = time.microseconds / 1000000.0;
    if (seconds > 0.02 && game->play.sea_up) {
        sfSprite_move(game->play.sea_spr, game->play.sea_spd);
        game->play.pos_sea_cur.y += game->play.sea_spd.y;
        sfClock_restart(game->play.sea_clk);
        if (game->play.pos_sea_cur.y <= game->play.pos_sea_end.y) {
            game->play.sea_up = false;
        }
    } else if (seconds > 0.03 && game->play.sea_up == false) {
        sfSprite_move(game->play.sea_spr, game->play.sea_spd_inv);
        game->play.pos_sea_cur.y += game->play.sea_spd_inv.y;
        sfClock_restart(game->play.sea_clk);
        if (game->play.pos_sea_cur.y >= game->play.pos_sea_str.y) {
            game->play.sea_up = true;
        }
    }
}

void move_car(game_t *game)
{
    list *mvcar = game->play.cars;
    for (; mvcar != NULL; mvcar = mvcar->next) {
        if ((entity_t *) {mvcar->value}->dir == RIGHT) {
           sfVector2f dir = {(entity_t *) {mvcar->value}->speed, 0};
           sfSprite_move((entity_t *) {mvcar->value}->sprite, dir);
           (entity_t *) {mvcar->value}->pos.x += dir.x;
           if ((entity_t *) {mvcar->value}->pos.x > 2300) {
                set_color(mvcar->value, &game->play.cartext);
               (entity_t *) {mvcar->value}->pos.x = -320;
               sfSprite_setPosition((entity_t *) {mvcar->value}->sprite, (entity_t *) {mvcar->value}->pos);
            }
        } else {
            sfVector2f dir = {-((entity_t *) {mvcar->value}->speed), 0};
            sfSprite_move((entity_t *) {mvcar->value}->sprite, dir);
            (entity_t *) {mvcar->value}->pos.x += dir.x;
            if ((entity_t *) {mvcar->value}->pos.x < -700) {
                set_color(mvcar->value, &game->play.cartext);
                (entity_t *) {mvcar->value}->pos.x = 2200;
                sfSprite_setPosition((entity_t *) {mvcar->value}->sprite, (entity_t *) {mvcar->value}->pos);
            }
        }
    }
}

void move_old(game_t *game)
{
    list *oldNpc = game->play.old_npc;
    for (; oldNpc != NULL; oldNpc = oldNpc->next) {
        if ((entity_t *) {oldNpc->value}->dir == RIGHT) {
           sfVector2f dir = {(entity_t *) {oldNpc->value}->speed, 0};
           sfSprite_move((entity_t *) {oldNpc->value}->sprite, dir);
           (entity_t *) {oldNpc->value}->pos.x += dir.x;
           if ((entity_t *) {oldNpc->value}->pos.x > 2300) {
               (entity_t *) {oldNpc->value}->pos.x = -320;
               sfSprite_setPosition((entity_t *) {oldNpc->value}->sprite, (entity_t *) {oldNpc->value}->pos);
            }
        } else {
            sfVector2f dir = {-((entity_t *) {oldNpc->value}->speed), 0};
            sfSprite_move((entity_t *) {oldNpc->value}->sprite, dir);
            (entity_t *) {oldNpc->value}->pos.x += dir.x;
            if ((entity_t *) {oldNpc->value}->pos.x < -300) {
                (entity_t *) {oldNpc->value}->pos.x = 2200;
                sfSprite_setPosition((entity_t *) {oldNpc->value}->sprite, (entity_t *) {oldNpc->value}->pos);
            }
        }
    }
}

void play_event(game_t *game)
{
    if (game->state != PLAY)
        return;
    move_ennemies_to_player(game);
    anim_old(game);
    manage_sword_sprite(&game->play.perso.atk);
    manage_weather(&game->play.weather);
    move_sea(game);
    move_car(game);
    move_old(game);
    player_remove_color(&game->play.perso);
    check_pizza(game);
    is_alive(game);
    if (game->play.fight == true &&
    sfMusic_getStatus(game->explo_m) == sfPlaying) {
        sfMusic_stop(game->explo_m);
        sfMusic_play(game->play.fight_m);
    }
    if (game->play.fight == false &&
    sfMusic_getStatus(game->play.fight_m) == sfPlaying) {
        sfMusic_stop(game->play.fight_m);
        sfMusic_play(game->explo_m);
    }
}
