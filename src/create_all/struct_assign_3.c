/*
** EPITECH PROJECT, 2022
** crete pause
** File description:
** struct_assigns_3
*/

#include "../../include/rpg.h"

void set_entity_s(entity_t *entity)
{
    sfSprite_setTexture(entity->sprite, entity->texture, sfFalse);
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setPosition(entity->sprite, entity->pos);
}

loading_t assign_loading_s(void)
{
    loading_t loading;
    loading.sprite = sfSprite_create();
    loading.texture = sfTexture_createFromFile("assets/loading.png", NULL);
    sfSprite_setTexture(loading.sprite, loading.texture, sfFalse);
    loading.planet_s = sfSprite_create();
    loading.planet_t = sfTexture_createFromFile("assets/planet.png", NULL);
    sfSprite_setTexture(loading.planet_s, loading.planet_t, sfFalse);
    sfSprite_setScale(loading.planet_s, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(loading.planet_s, (sfVector2f){700, 450});
    return loading;
}

pause_t assign_pause_s(game_t *game)
{
    pause_t pause;
    pause.quit = assign_button("assets/buttons.png", (sfVector2f)
    {870, 785}, set_rect(0, 180, 70, 180));
    pause.resume = assign_button("assets/buttons.png", (sfVector2f)
    {830, 435}, set_rect(0, 1340, 70, 260));
    pause.menu = assign_button("assets/buttons.png", (sfVector2f)
    {870, 260}, set_rect(0, 1160, 70, 180));
    pause.settings = assign_button("assets/buttons.png", (sfVector2f)
    {790, 610}, set_rect(0, 1600, 70, 340));
    return (pause);
}

sound_t assign_sounds(void)
{
    sound_t sound;
    sound.click = sfSound_create(); sound.heal = sfSound_create();
    sound.quest = sfSound_create();
    sound.quest_b = sfSoundBuffer_createFromFile("assets/music/quest_\
accepted.ogg");
    sound.click_b = sfSoundBuffer_createFromFile("assets/click.ogg");
    sound.heal_b = sfSoundBuffer_createFromFile("assets/music/heal_sound.ogg");
    sfSound_setBuffer(sound.quest, sound.quest_b);
    sfSound_setBuffer(sound.heal, sound.heal_b);
    sfSound_setBuffer(sound.click, sound.click_b);
    return sound;
}

void preview_create(menu_t *menu)
{
    menu->status = 0;
    menu->pre = set_rect(0, 0, 64, 64);
    sfVector2f pos = {925, 835};
    sfVector2f scale = {2, 2};
    menu->preview_s = sfSprite_create();
    menu->preview_t =
    sfTexture_createFromFile("assets/perso/preview.png", NULL);
    sfSprite_setTexture(menu->preview_s, menu->preview_t, sfFalse);
    sfSprite_setTextureRect(menu->preview_s, menu->pre);
    sfSprite_setPosition(menu->preview_s, pos);
    sfSprite_setScale(menu->preview_s, scale);
}
