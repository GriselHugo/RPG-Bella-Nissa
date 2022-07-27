/*
** EPITECH PROJECT, 2022
** struct_assign_4.c
** File description:
** struct_assign_4 for assign struct values
*/

#include "../../include/rpg.h"

cartext_t assign_car_text(void)
{
    cartext_t cartext;
    cartext.red = sfTexture_createFromFile("assets/car/carred.png", NULL);
    cartext.green = sfTexture_createFromFile("assets/car/cargreen.png", NULL);
    cartext.blue = sfTexture_createFromFile("assets/car/carblue.png", NULL);
    cartext.yellow = sfTexture_createFromFile("assets/car/caryellow.png", NULL);
    cartext.black = sfTexture_createFromFile("assets/car/carblack.png", NULL);
    cartext.white = sfTexture_createFromFile("assets/car/carwhite.png", NULL);
    return (cartext);
}

void assign_play_s_2(play_t *play)
{
    play->scene = S_NICE;
    play->pos_nice = (sfVector2f) {896, 486};
    play->pos_mcdo = (sfVector2f) {1800, 800};
    play->nice_x = 16000; play->nice_y = 16000;
    play->mcdo_x = 1920; play->mcdo_y = 1080;
    play->map_x = play->nice_x; play->map_y = play->nice_y;
    play->mcdo_rct = set_rect(50, 0, 1080, 1920);
    play->mcdo_bw = sfImage_createFromFile("assets/map/mcdo_in_col.png");
    play->details_s = sfSprite_create();
    play->details_t = sfTexture_createFromFile("assets/map/palm_rpg.png",NULL);
    play->palm_t = play->details_t;
    play->credits = assign_credits_s();
    play->epitech_tex = sfTexture_createFromFile("assets/map/tech_inside.png",
    NULL);
    play->epitech_bw = sfImage_createFromFile("assets/map/tech_in_col.png");
    play->epitech_x = 1920; play->epitech_y = 1080;
    play->epitech_rct = set_rect(50, 0, 1080, 1920);
    play->pos_epitech = (sfVector2f) {1800, 800};
    play->sea_spr = sfSprite_create();
    play->sea_tex = sfTexture_createFromFile("assets/sea.png", NULL);
    play->pos_sea_str = (sfVector2f) {0, 1200};
    play->pos_sea_cur = (sfVector2f) {0, 1200};
    play->pos_sea_end = (sfVector2f) {0, 1100};
    sfSprite_setTexture(play->sea_spr, play->sea_tex, sfFalse);
    play->sea_spd = (sfVector2f) {0, -2};
    play->sea_spd_inv = (sfVector2f) {0, 3};
    play->sea_up = true;
    play->sea_tick = 0;
    play->sea_clk = sfClock_create();
    play->cartext = assign_car_text();
    play->cars = new_list(); play->old_npc = new_list();
    sfSprite_setPosition(play->sea_spr, play->pos_sea_str);
}

sfText *create_text(char *str, int dist, sfFont *font)
{
    sfText *text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f) {200, 400 + dist * 100});
    return (text);

}

weather_t assign_weather_s(void)
{
    weather_t weather;
    weather.clock = sfClock_create();
    weather.change = sfClock_create();
    weather.sprite = sfSprite_create();
    weather.rect = (sfIntRect){0, 0, 1920, 1080};
    weather.sun_tex = sfTexture_createFromFile("assets/weather/sun.png",
    NULL);
    weather.rain_tex = sfTexture_createFromFile("assets/weather/rain.png",
    NULL);
    weather.fog_tex = sfTexture_createFromFile("assets/weather/fog.png",
    NULL);
    weather.type = -1;
    weather.timer = 0;
    weather.speed_mod = 0;
    weather.manual = true;
    sfSprite_setTextureRect(weather.sprite, weather.rect);
    return (weather);
}

attack_t assign_attack_s(void)
{
    attack_t attack;
    attack.sprite = sfSprite_create();
    attack.texture = sfTexture_createFromFile("assets/items/sword_attck.png",
    NULL);
    attack.attckng = false;
    sfSprite_setTexture(attack.sprite, attack.texture, sfFalse);
    return (attack);
}

void assign_perso_misc(charac_t *perso)
{
    perso->health_bar = create_item("assets/health_bar.png",
    (sfVector2f) {700, 970});
    perso->hp = create_item("assets/hp.png", (sfVector2f) {710, 980});
    perso->rect_hp = set_rect(0, 0, 50, 500);
    perso->potion_cldwn = sfClock_create();
    perso->effect = sfClock_create();
    perso->attck_cldwn = sfClock_create();
    perso->atk = assign_attack_s();
    perso->is_running = false;
}
