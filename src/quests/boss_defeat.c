/*
** EPITECH PROJECT, 2022
** boss_defeat.c
** File description:
** Boss deafeat quest
*/

#include "../../include/rpg.h"

entity_t *assign_boss(char *name, int type, game_t *game, sfVector2f pos)
{
    entity_t *entity = malloc(sizeof(entity_t));
    entity->type = type;
    entity->sprite = sfSprite_create();
    entity->pos = pos;
    entity->texture = sfTexture_createFromFile(my_strcat(my_strcat
    ("assets/ennemies/", name), ".png"), NULL);
    sfSprite_setTexture(entity->sprite, entity->texture, sfFalse);
    sfSprite_setPosition(entity->sprite, entity->pos);
    entity->health = my_getnbr(find_in_config(my_strcat(name, "_HP"),
    game->config));
    entity->damage = my_getnbr(find_in_config(my_strcat(name, "_DMG"),
    game->config));
    entity->speed = my_getnbr(find_in_config(my_strcat(name, "_SPD"),
    game->config));
    entity->range = my_getnbr(find_in_config(my_strcat(name, "_RNG"),
    game->config));
    return entity;
}

list *boss_defeat(game_t *game, list *npc)
{
    entity_t *boss = assign_npc("pnj_boss",NPC, game, (sfVector2f)
    {4800, -2800});
    npc = add_end(npc, boss);
    return npc;
}

void boss_fight(game_t *game)
{
    list *tmp = game->play.npc;
    float dist = get_distance(&game->play.perso, tmp->next->value);
    if (dist <= 150 && game->play.quest == READY) {
        sfSound_play(game->sound.quest);
        game->play.quest = PROGRESS;
        entity_t *boss = assign_boss("boss", BOSS, game,
        (sfVector2f) {0,300});
        game->play.boss = add_end(game->play.boss, boss);
    }
}

void draw_boss(game_t *game, list *bossl)
{
    for (; bossl != NULL; bossl = bossl->next) {
        if (is_in_window((entity_t *) {bossl->value}->pos) && (entity_t *)
        {bossl->value}->type != DEAD) {
            sfRenderWindow_drawSprite((sfRenderWindow *) game->window,
            ((entity_t *) {bossl->value})->sprite, NULL);
        }
    }
}
