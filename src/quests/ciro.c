/*
** EPITECH PROJECT, 2022
** ciro.c
** File description:
** Ciro quest here
*/

#include "../../include/rpg.h"

entity_t *assign_npc(char *name, int type, game_t *game, sfVector2f pos)
{
    entity_t *entity = malloc(sizeof(entity_t));
    entity->pos = pos;
    entity->text_s = sfSprite_create();
    entity->text_t = sfTexture_createFromFile(my_strcat(my_strcat
    ("assets/quest/", name), "_start.png"),NULL);
    sfSprite_setTexture(entity->text_s, entity->text_t, sfTrue);
    entity->type = type;
    entity->sprite = sfSprite_create();
    entity->texture = sfTexture_createFromFile(my_strcat(my_strcat
    ("assets/perso/", name), ".png"), NULL);
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    sfSprite_setPosition(entity->sprite, entity->pos);
    sfSprite_setScale(entity->sprite, (sfVector2f) {1.525, 1.525});
    return entity;
}

list *generate_npc(game_t *game)
{
    list *npc = new_list();
    entity_t *entity = assign_npc("ciro", NPC, game,
    (sfVector2f) {4400, -1380});
    npc = add_end(npc, entity);
    npc = boss_defeat(game, npc);
    return npc;
}

void ciro_quest(game_t *game, list *render)
{
    sfTexture *texture = sfTexture_createFromFile("assets/quest/ciro_end.png",
    NULL);
    float dist = get_distance(&game->play.perso, game->play.npc->value);
    if (dist <= 150 && game->play.quest == READY) {
        sfSound_play(game->sound.quest);
        game->play.quest = PROGRESS;
    }
    if (dist <= 150 && game->play.quest == PROGRESS
    && game->play.inv.pizza == true) {
        sfSprite_setTexture((entity_t *) {game->play.npc->value}->text_s,
        texture,sfTrue);
        game->play.quest = END;
        game->play.inv.items[0][0] = '1';
        game->play.inv.gun.obtained = true;
    }
}

void draw_npc(game_t *game, list *renderNpc)
{
    if (game->play.scene != S_NICE)
        return;
    for (; renderNpc != NULL; renderNpc = renderNpc->next) {
        float dist = get_distance(&game->play.perso, renderNpc->value);
        if (dist <= 150 && (game->play.quest == READY || game->play.quest
        == END))
            sfRenderWindow_drawSprite(game->window,(entity_t *)
            {renderNpc->value}->text_s, NULL);
        if (is_in_window((entity_t *) {renderNpc->value}->pos)) {
            sfSprite_setPosition((entity_t *) {renderNpc->value}->text_s,
            (sfVector2f) {(entity_t *) {renderNpc->value}->pos.x - 32,
            (entity_t *) {renderNpc->value}->pos.y - 74});
            sfRenderWindow_drawSprite((sfRenderWindow *) game->window,
            ((entity_t *) {renderNpc->value})->sprite, NULL);
        }
    }
}
