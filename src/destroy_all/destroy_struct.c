/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** functions to destroy structures
*/

#include "../../include/rpg.h"

void destroy_button(button_t *button)
{
    sfSprite_destroy(button->sprite);
    sfTexture_destroy(button->texture);
}

void destroy_option(option_t *option)
{
    sfSprite_destroy(option->sprite);
    sfTexture_destroy(option->texture);
    sfFont_destroy(option->font);
    sfText_destroy(option->music);
    sfText_destroy(option->sound);
    destroy_button(&option->back);
    destroy_button(&option->musicminus);
    destroy_button(&option->musicplus);
    destroy_button(&option->soundminus);
    destroy_button(&option->soundplus);
}

void destroy_help(help_t *help, int state)
{
    if (state != MENU)
        return;
    sfSprite_destroy(help->sprite);
    sfTexture_destroy(help->texture);
    sfFont_destroy(help->font);
    destroy_button(&help->back);
    for (; help->text != NULL;) {
        list *tlst = help->text;
        help->text = help->text->next;
        sfText_destroy(tlst->value);
        free(tlst);
    }
}

void destroy_charac_t(charac_t *perso)
{
    sfSprite_destroy(perso->sprite);
    sfTexture_destroy(perso->texture);
    sfClock_destroy(perso->clock);
}

void destroy_game(game_t *game)
{
    change_config(game);
    if (game->state == HELP)
        destroy_help(&game->help, MENU);
    if (game->play_loaded == true)
        destroy_play(&game->play);
    sfSound_destroy(game->sound.click);
    sfSoundBuffer_destroy(game->sound.click_b);
    sfMusic_destroy(game->explo_m);
    sfRenderWindow_destroy(game->window);
    sfImage_destroy(game->icon);
    destroy_musics(&game->sound);
    destroy_menu(&game->menu);
    destroy_pause(&game->pause);
    destroy_loading(&game->loading);
    for (int i = 0; game->config[i] != NULL; i++)
        free(game->config[i]);
    free(game->config);
}
