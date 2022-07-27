/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** function when the mouse is used
*/

#include "../../include/rpg.h"

void mouse_menu(game_t *game, sfVector2i mouse_pos)
{
    manage_play_button(game, mouse_pos);
    manage_help_button(game, mouse_pos);
    manage_option_button(game, mouse_pos);
    manage_exit_button(game, mouse_pos);
    perso_selection(game, mouse_pos);
}

void mouse_option(game_t *game, sfVector2i mouse_pos)
{
    manage_music_minus_button(game, mouse_pos);
    manage_music_plus_button(game, mouse_pos);
    manage_sound_minus_button(game, mouse_pos);
    manage_sound_plus_button(game, mouse_pos);
    manage_back_button(game, mouse_pos);
}

void mouse_pause(game_t *game, sfVector2i mouse_pos)
{
    manage_pause_quit_button(game, mouse_pos);
    manage_pause_resume_button(game, mouse_pos);
    manage_pause_menu_button(game, mouse_pos);
    manage_pause_settings_button(game, mouse_pos);
}

void mouse_settings(game_t *game, sfVector2i mouse_pos)
{
    manage_game_music_minus_button(game, mouse_pos);
    manage_game_music_plus_button(game, mouse_pos);
    manage_sound_minus_button(game, mouse_pos);
    manage_sound_plus_button(game, mouse_pos);
    manage_back_to_game_button(game, mouse_pos);
}

void manage_mouse(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    if (game->state == MENU)
        mouse_menu(game, mouse_pos);
    if (game->state == HELP)
        mouse_help(game, mouse_pos);
    if (game->state == OPTION)
        mouse_option(game, mouse_pos);
    if (game->state == PAUSE)
        mouse_pause(game, mouse_pos);
    if (game->state == SETTINGS)
        mouse_settings(game, mouse_pos);
    if (game->state == PLAY)
        mouse_play(game, mouse_pos);
}
