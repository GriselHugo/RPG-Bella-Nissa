/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** create_ennemis
*/

#include "../../include/rpg.h"

list *create_ennemis_garden(game_t *game, list *tlst)
{
    entity_t *entity1 = assign_entity_s("human", ENNEMY, game,
    (sfVector2f) {2500, -700});
    tlst = add_end(tlst, entity1);
    entity_t *entity2 = assign_entity_s("human", ENNEMY, game,
    (sfVector2f) {2300, -1400});
    tlst = add_end(tlst, entity2);
    entity_t *entity3 = assign_entity_s("human", ENNEMY, game,
    (sfVector2f) {2700, -1800});
    tlst = add_end(tlst, entity3);
    entity_t *entity4 = assign_entity_s("human", ENNEMY, game,
    (sfVector2f) {2600, -2400});
    tlst = add_end(tlst, entity4);
    entity_t *entity5 = assign_entity_s("human", ENNEMY, game,
    (sfVector2f) {2500, -2800});
    tlst = add_end(tlst, entity5);
    entity_t *entity6 = assign_entity_s("human", ENNEMY, game,
    (sfVector2f) {3400, -2900});
    tlst = add_end(tlst, entity6);
    return (tlst);
}

list *create_ennemis_prom(game_t *game, list *tlst)
{
    entity_t *entity1 = assign_entity_s("human", ENNEMY, game,
    (sfVector2f) {2300, 0});
    tlst = add_end(tlst, entity1);
    entity_t *entity2 = assign_entity_s("human", ENNEMY, game,
    (sfVector2f) {3200, 200});
    tlst = add_end(tlst, entity2);
    entity_t *entity3 = assign_entity_s("human", ENNEMY, game,
    (sfVector2f) {4100, 400});
    tlst = add_end(tlst, entity3);
    entity_t *entity4 = assign_entity_s("human", ENNEMY, game,
    (sfVector2f) {4700, -100});
    tlst = add_end(tlst, entity4);
    return  (tlst);
}

list *create_ennemis_place(game_t *game, list *tlst)
{
    entity_t *entity1 = assign_entity_s("human", ENNEMY, game,
    (sfVector2f) {4500, -3000});
    tlst = add_end(tlst, entity1);
    entity_t *entity2 = assign_entity_s("human", ENNEMY, game,
    (sfVector2f) {4800, -4300});
    tlst = add_end(tlst, entity2);
    entity_t *entity3 = assign_entity_s("human", ENNEMY, game,
    (sfVector2f) {5200, -4000});
    tlst = add_end(tlst, entity3);
    entity_t *entity4 = assign_entity_s("human", ENNEMY, game,
    (sfVector2f) {5400, -2900});
    tlst = add_end(tlst, entity4);
    entity_t *entity5 = assign_entity_s("human", ENNEMY, game,
    (sfVector2f) {4600, -2100});
    tlst = add_end(tlst, entity5);
    return (tlst);
}
