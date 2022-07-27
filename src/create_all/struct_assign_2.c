/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** additionnal file for assigning struct
*/

#include "../../include/rpg.h"

charac_t assign_perso(game_t *game)
{
    charac_t perso;
    perso.move = FORWARD;
    perso.clock = sfClock_create();
    perso.sprite = sfSprite_create();
    perso.texture = assign_texture(game);
    perso.rect = set_rect(192, 0 , 64 ,64);
    sfVector2f scale = {1.5625, 1.5625};
    perso.pos = (sfVector2f) {896, 486};
    perso.health = my_getnbr(find_in_config("P_HP", game->config));
    perso.damage = my_getnbr(find_in_config("P_DMG", game->config));
    perso.resist = my_getnbr(find_in_config("P_RST", game->config));
    perso.speed = my_getnbr(find_in_config("P_SPD", game->config));
    perso.ivcblt = sfClock_create();
    perso.kill = 0;
    sfSprite_setScale(perso.sprite,scale);
    sfSprite_setPosition(perso.sprite,perso.pos);
    sfSprite_setTexture(perso.sprite, perso.texture, sfTrue);
    sfSprite_setTextureRect(perso.sprite, perso.rect);
    assign_perso_misc(&perso);
    return perso;
}

void assigns_option_text(option_t *option, int musicvol, int soundvol)
{
    char music[4];
    char sound[4];
    option->music = sfText_create();
    sfText_setString(option->music, my_itoa(musicvol, music));
    sfText_setFont(option->music, option->font);
    sfText_setFillColor(option->music, sfBlack);
    sfText_setPosition(option->music, (sfVector2f) {512, 610});
    sfText_setCharacterSize(option->music, 50);
    option->sound = sfText_create();
    sfText_setString(option->sound, my_itoa(soundvol, sound));
    sfText_setFont(option->sound, option->font);
    sfText_setFillColor(option->sound, sfBlack);
    sfText_setPosition(option->sound, (sfVector2f) {1242, 610});
    sfText_setCharacterSize(option->sound, 50);
}

entity_t *assign_entity_s(char *name, int type, game_t *game, sfVector2f pos)
{
    entity_t *entity = malloc(sizeof(entity_t));
    entity->rect = set_rect(192, 0 , 64 ,64);
    entity->type = type;
    entity->sprite = sfSprite_create();
    entity->texture = sfTexture_createFromFile(my_strcat(my_strcat
    ("assets/ennemies/", name), ".png"), NULL);
    entity->health = my_getnbr(find_in_config(my_strcat(name, "_HP"),
    game->config));
    entity->damage = my_getnbr(find_in_config(my_strcat(name, "_DMG"),
    game->config));
    entity->resist = my_getnbr(find_in_config(my_strcat(name, "_RST"),
    game->config));
    entity->speed = my_getnbr(find_in_config(my_strcat(name, "_SPD"),
    game->config)); entity->pos = pos;
    entity->range = my_getnbr(find_in_config(my_strcat(name, "_RNG"),
    game->config));
    entity->clock = sfClock_create();
    sfSprite_setScale(entity->sprite, (sfVector2f) {1.525, 1.525});
    set_entity_s(entity);
    return (entity);
}

play_t assign_play_s(game_t *game)
{
    play_t play; play.fight = false; game->play_loaded = true;
    play.quest = READY; play.npc = new_list();
    play.nice_bw = sfImage_createFromFile("assets/map/map_bw.png");
    play.map_bw_img = play.nice_bw; play.map_spr = sfSprite_create();
    play.nice_tex = sfTexture_createFromFile("assets/map/map_rpg.png", NULL);
    play.map_tex = play.nice_tex;
    play.fight_m = sfMusic_createFromFile("assets/music/fight.ogg");
    play.perso = assign_perso(game); play.inv = assign_inventory();
    play.map_rct = set_rect(14700, 0, 1080, 1920);
    play.nice_rct = set_rect(14700, 0, 1080, 1920);
    play.ennemy = generate_ennemies(game,"human");
    play.boss = new_list();
    play.npc = generate_npc(game); play.weather = assign_weather_s();
    play.pizza_s = sfSprite_create(); play.pos_pizza = (sfVector2f) {900,-500};
    play.pizza_t = sfTexture_createFromFile("assets/quest/pizza.png",NULL);
    play.mcdo_t = sfTexture_createFromFile("assets/map/mcdo_inside.png",NULL);
    assign_play_s_2(&play); set_play(&play, game);
    create_cars_list(&play, game);
    create_old_list(&play, game);
    return play;
}

void assign_game_s_second(game_t *game)
{
    game->explo_m = sfMusic_createFromFile("assets/music/exploration.ogg");
    sfMusic_setLoop(game->explo_m, sfTrue);
    sfMusic_setVolume(game->explo_m, game->musicvol);
    game->loading = assign_loading_s();
    game->nextload = L_NONE;
    game->option = assign_option_s(game);
    game->play_loaded = false;
}
