/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** weather
*/

#include "../../include/rpg.h"

void set_weather(weather_t *weather)
{
    if (weather->type == SUN) {
        sfSprite_setTexture(weather->sprite, weather->sun_tex, sfFalse);
        weather->rect.top = 0;
        weather->speed_mod = 0;
    }
    if (weather->type == RAIN) {
        sfSprite_setTexture(weather->sprite, weather->rain_tex, sfFalse);
        weather->speed_mod = 7;
    }
    if (weather->type == FOG) {
        sfSprite_setTexture(weather->sprite, weather->fog_tex, sfFalse);
        weather->speed_mod = 2;
    }
}

void anim_weather(weather_t *weather)
{
    weather->time = sfClock_getElapsedTime(weather->clock);
    weather->seconds = weather->time.microseconds / 1000000.0;
    if (weather->seconds > 0.1) {
        sfSprite_setTextureRect(weather->sprite, weather->rect);
        weather->rect.top -= 10 * weather->speed_mod;
        if (weather->rect.top <= 0)
            weather->rect.top = 1080;
        sfClock_restart(weather->clock);
    }
}

void change_weather(weather_t *weather, int type)
{
    if (type >= 0) {
        weather->type = type;
        set_weather(weather);
        return;
    }
    int rand_nb = rand() % 100;
    if (rand_nb < 20)
        weather->type = FOG;
    else if (rand_nb >= 20 && rand_nb < 50)
        weather->type = RAIN;
    else
        weather->type = SUN;
    set_weather(weather);
}

void manage_weather(weather_t *weather)
{
    anim_weather(weather);
    if (weather->manual == true)
        return;
    weather->time = sfClock_getElapsedTime(weather->change);
    weather->seconds = weather->time.microseconds / 1000000.0;
    if (weather->seconds < weather->timer)
        return;
    weather->timer = rand() % 2 + 2;
    sfClock_restart(weather->change);
    change_weather(weather, -1);
}
