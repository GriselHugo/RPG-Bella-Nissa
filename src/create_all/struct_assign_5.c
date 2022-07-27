/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** struct_assigns_5
*/

#include "../../include/rpg.h"

credits_t assign_credits_s(void)
{
    credits_t credits;
    char *str = "Press Enter to skip";
    credits.sprite = sfSprite_create();
    credits.texture = sfTexture_createFromFile("assets/credits.png", NULL);
    credits.rect = set_rect(0, 0, 1080, 1920);
    credits.clock = sfClock_create();
    credits.skip = false;
    credits.text = sfText_create();
    credits.font = sfFont_createFromFile("assets/font/gameplay.ttf");
    sfText_setString(credits.text, str);
    sfText_setFont(credits.text, credits.font);
    sfText_setCharacterSize(credits.text, 25);
    sfText_setPosition(credits.text, (sfVector2f) {1550, 950});
    sfSprite_setTexture(credits.sprite, credits.texture, sfFalse);
    sfSprite_setTextureRect(credits.sprite, credits.rect);
    return (credits);
}

void set_play(play_t *play, game_t *game)
{
    play->inv.speed = create_text_stats("assets/font/gameplay.ttf", game,
    (sfVector2f) { 800, 660}, "P_SPD");
    play->inv.dmg = create_text_stats("assets/font/gameplay.ttf", game,
    (sfVector2f) { 920, 660}, "P_DMG");
    play->inv.rst = create_text_stats("assets/font/gameplay.ttf", game,
    (sfVector2f) { 1050, 660}, "P_RST");
    sfSprite_setTexture(play->details_s, play->palm_t, sfFalse);
    sfSprite_setTexture(play->pizza_s, play->pizza_t, sfFalse);
    sfSprite_setScale(play->pizza_s, (sfVector2f) {0.05, 0.05});
    sfSprite_setPosition(play->pizza_s, play->pos_pizza);
    change_weather(&play->weather, SUN);
    sfSprite_setTexture(play->map_spr, play->map_tex, sfFalse);
    sfSprite_setTextureRect(play->map_spr, play->map_rct);
    sfSprite_setTextureRect(play->details_s, play->map_rct);
    check_inventory(&play->inv, game->config);
}

object_t create_item(char *path, sfVector2f pos)
{
    object_t obj;
    obj.sprite = sfSprite_create();
    obj.texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(obj.sprite, obj.texture, sfFalse);
    obj.pos.x = pos.x;
    obj.pos.y = pos.y;
    sfSprite_setPosition(obj.sprite, obj.pos);
    obj.obtained = false;
    return obj;
}
