/*
** EPITECH PROJECT, 2022
** main_rpg.c
** File description:
** Main file (contain main) for my_rpg project
*/

#include "../include/rpg.h"

void listen_events(game_t *game)
{
    manage_mouse(game);
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.key.code == sfKeyEscape && game->state == PLAY) {
            game->state = PAUSE;
        }
        if (game->event.type == sfEvtKeyPressed && game->state == PLAY) {
            manage_keyboard_perso(game);
            inventory_pop(game);
        }
    }
}

void draw_sprites(game_t *game)
{
    sfRenderWindow_display(game->window);
    sfRenderWindow_clear(game->window, sfBlack);
    if (game->state == MENU)
        draw_menu(game);
    if (game->state == HELP)
        draw_help(game);
    if (game->state == OPTION || game->state == SETTINGS)
        draw_option(game);
    if (game->state == PLAY)
        draw_game(game);
    if (game->state == PAUSE)
        draw_pause(game);
    if (game->state == LOADING)
        draw_load(game);
}

int main_game(int mode)
{
    time_t t;
    srand((unsigned) time(&t));
    game_t game = assign_game_s();
    if (mode == 1)
        set_eric_mode(&game);
    music(&game);
    while (sfRenderWindow_isOpen(game.window)) {
        listen_events(&game);
        play_event(&game);
        credits_loop(&game.play.credits, &game);
        manage_loading(&game);
        draw_sprites(&game);
    }
    destroy_game(&game);
}

int main(int ac, char **av)
{
    if (ac > 2) {
        my_putstr(RED BOLD"Too many arguments.\n"UNBOLD WHITE);
        manual();
        my_putstr(RED BOLD"\nToo many arguments.\n"UNBOLD WHITE);
        return 84;
    }
    if (ac == 2 && my_strcmp("-h", av[1]) == 0)
        manual();
    else if (ac == 2 && my_strcmp("emode", av[1]) == 0)
        main_game(1);
    else
        main_game(0);
}
