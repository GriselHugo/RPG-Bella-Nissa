/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** car
*/

#include "../../include/rpg.h"

void render_car(game_t *game, list *render)
{
    for (; render != NULL; render = render->next) {
        if (is_in_window((entity_t *) {render->value}->pos))
            sfRenderWindow_drawSprite(game->window, (entity_t *) {render->value}->sprite, NULL);
    }
}

void set_color(entity_t *car, cartext_t *cartext)
{
    int color = rand() % 5;
    if (color == 0)
        car->texture = cartext->black;
    if (color == 1)
        car->texture = cartext->blue;
    if (color == 2)
        car->texture = cartext->green;
    if (color == 3)
        car->texture = cartext->red;
    if (color  == 4)
        car->texture = cartext->white;
    if (color == 5)
        car->texture = cartext->yellow;
    sfSprite_setTexture(car->sprite, car->texture, sfFalse);
}

entity_t *create_car(game_t *game, int dir)
{
    entity_t *car;
    car = malloc(sizeof(entity_t));
    car->sprite = sfSprite_create();
    car->texture = sfTexture_createFromFile("assets/car/carred.png", NULL);
    car->speed = my_getnbr(find_in_config("car_SPD", game->config));
    car->damage = my_getnbr(find_in_config("car_DMG", game->config));
    sfSprite_setTexture(car->sprite, car->texture, sfFalse);
    sfSprite_setScale(car->sprite, (sfVector2f) {0.4, 0.4});
    sfFloatRect rect = sfSprite_getLocalBounds(car->sprite);
    if (dir == RIGHT) {
        car->dir = RIGHT;
        car->pos = (sfVector2f) {-320, -20};
        sfSprite_setTextureRect(car->sprite, (sfIntRect) {rect.width, 0, -rect.width, rect.height});
    } else {
        car->dir = LEFT;
        car->pos = (sfVector2f) {1700, -320};
    }
    sfSprite_setPosition(car->sprite, car->pos);
    return (car);
}

void create_cars_list(play_t *play, game_t *game)
{
    play->cars = add_end(play->cars, create_car(game, RIGHT));
    play->cars = add_end(play->cars, create_car(game, LEFT));
}
