/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** destroy_struct_2
*/

#include "../../include/rpg.h"

void destroy_inv(inv_t *inv)
{
    sfSprite_destroy(inv->sprite);
    sfTexture_destroy(inv->texture);
}

void destroy_play(play_t *play)
{
    destroy_charac_t(&play->perso);
    sfSprite_destroy(play->map_spr);
    destroy_list(play->ennemy);
    destroy_list(play->npc);
    destroy_inv(&play->inv);
    sfSprite_destroy(play->map_spr);
    sfTexture_destroy(play->map_tex);
    sfMusic_destroy(play->fight_m);
}

void destroy_menu(menu_t *menu)
{
    sfMusic_destroy(menu->music);
    destroy_button(&menu->play);
    destroy_button(&menu->option);
    destroy_button(&menu->help);
    destroy_button(&menu->exit);
    destroy_button(&menu->select_l);
    destroy_button(&menu->select_r);
    sfSprite_destroy(menu->sprite);
    sfTexture_destroy(menu->texture);
    sfSprite_destroy(menu->preview_s);
    sfTexture_destroy(menu->preview_t);
}

void destroy_pause(pause_t *pause)
{
    destroy_button(&pause->menu);
    destroy_button(&pause->quit);
    destroy_button(&pause->resume);
    destroy_button(&pause->settings);
}

void destroy_loading(loading_t *loading)
{
    sfSprite_destroy(loading->sprite);
    sfTexture_destroy(loading->texture);
    sfSprite_destroy(loading->planet_s);
    sfTexture_destroy(loading->planet_t);
}
