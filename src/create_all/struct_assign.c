/*
** EPITECH PROJECT, 2022
** struct_assign.c
** File description:
** file for assign values of struct
*/

#include "../../include/rpg.h"

button_t assign_button(char *path, sfVector2f pos, sfIntRect rect)
{
    button_t tbutton;
    tbutton.texture = sfTexture_createFromFile(path, NULL);
    tbutton.sprite = sfSprite_create();
    sfSprite_setTexture(tbutton.sprite, tbutton.texture, sfFalse);
    tbutton.rect.left = rect.left;
    tbutton.rect.top = rect.top;
    tbutton.rect.height = rect.height;
    tbutton.rect.width = rect.width;
    sfSprite_setTextureRect(tbutton.sprite, tbutton.rect);
    tbutton.pos.x = pos.x;
    tbutton.pos.y = pos.y;
    sfSprite_setPosition(tbutton.sprite, tbutton.pos);
    return (tbutton);
}

option_t assign_option_s(game_t *game)
{
    option_t option;
    option.sprite = sfSprite_create();
    option.texture = sfTexture_createFromFile("assets/option/opt.png", NULL);
    option.back = assign_button("assets/buttons.png", (sfVector2f)
    {1600, 800}, set_rect(0, 1080, 80, 80));
    sfSprite_setTexture(option.sprite, option.texture, sfFalse);
    option.musicminus = assign_button("assets/buttons.png", (sfVector2f)
    {520, 700}, set_rect(0, 440, 80, 80));
    option.musicplus = assign_button("assets/buttons.png", (sfVector2f)
    {520, 500}, set_rect(0, 360, 80, 80));
    option.soundminus = assign_button("assets/buttons.png", (sfVector2f)
    {1250, 700}, set_rect(0, 440, 80, 80));
    option.soundplus = assign_button("assets/buttons.png", (sfVector2f)
    {1250, 500}, set_rect(0, 360, 80, 80));
    option.font = sfFont_createFromFile("assets/font/gameplay.ttf");
    assigns_option_text(&option, game->musicvol, game->soundvol);
    return option;
}

help_t assign_help_s(game_t *game)
{
    help_t help;
    list *tlist;
    sfText *ttext;
    list *strl = find_in_config("HELP_TEXT", game->config);
    help.font = sfFont_createFromFile("assets/font/gameplay.ttf");
    help.sprite = sfSprite_create();
    help.texture = sfTexture_createFromFile("assets/help/help.png", NULL);
    help.back = assign_button("assets/buttons.png", (sfVector2f)
    {1600, 800}, set_rect(0, 1080, 80, 80));
    sfSprite_setTexture(help.sprite, help.texture, sfFalse);
    help.text = new_list();
    for (int i = 0; strl != NULL; strl = strl->next, i++) {
        help.text = add_end(help.text, create_text(strl->value, i, help.font));
    }
    return (help);
}

menu_t assign_menu_s(void)
{
    menu_t menu; preview_create(&menu);
    menu.music = sfMusic_createFromFile("assets/music/main_menu.ogg");
    sfMusic_setLoop(menu.music, sfTrue); menu.sprite = sfSprite_create();
    menu.texture = sfTexture_createFromFile("assets/menu/menu.png", NULL);
    sfSprite_setTexture(menu.sprite, menu.texture, sfFalse);
    menu.play = assign_button("assets/buttons.png", (sfVector2f)
    {450, 600}, set_rect(0, 0, 70, 180));
    menu.help = assign_button("assets/buttons.png", (sfVector2f)
    {800, 600}, set_rect(0, 840, 80, 80));
    menu.option = assign_button("assets/buttons.png", (sfVector2f)
    {1050, 600}, set_rect(0, 760, 80, 80));
    menu.exit = assign_button("assets/buttons.png", (sfVector2f)
    {1300, 600}, set_rect(0, 180, 70, 180));
    menu.select_r = assign_button("assets/buttons.png",(sfVector2f) {1050,850},
    set_rect(0, 920, 80, 80));
    menu.select_l = assign_button("assets/buttons.png",(sfVector2f) {800,850},
    set_rect(0, 1000, 80, 80));
    menu.reset = assign_button("assets/buttons.png",(sfVector2f) {452,700},
    set_rect(0, 1940, 56, 176));
    return menu;
}

sprite_t create_damien()
{
    sprite_t damien;
    damien.texture = sfTexture_createFromFile("assets/perso/damsweb.png", NULL);
    damien.sprite = sfSprite_create();
    sfSprite_setTexture(damien.sprite, damien.texture, sfFalse);
    damien.pos.x = 1700;
    damien.pos.y = 200;
    sfSprite_setPosition(damien.sprite, damien.pos);
    sfVector2f scale = {1.5625, 1.5625};
    sfSprite_setScale(damien.sprite, scale);
    return (damien);
}

game_t assign_game_s(void)
{
    game_t game; sfVideoMode VM = {1920 , 1080, 0};
    game.index = 0; game.black = sfColor_toInteger((sfColor) sfBlack);
    game.red = sfColor_toInteger(sfRed);
    game.white = sfColor_toInteger(sfWhite);
    game.config = create_config_arr(); game.blue = sfColor_toInteger(sfBlue);
    char *title = find_in_config("TITLE", game.config);
    game.window = sfRenderWindow_create(VM,title, sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(game.window, 60);
    game.icon = sfImage_createFromFile("assets/icone.png");
    sfRenderWindow_setIcon(game.window,32,32,sfImage_getPixelsPtr(game.icon));
    game.musicvol = my_getnbr(find_in_config("MUSIC", game.config));
    game.soundvol = my_getnbr(find_in_config("SOUND", game.config));
    game.menu = assign_menu_s();
    sfMusic_setVolume(game.menu.music, game.musicvol);
    game.state = MENU; assign_game_s_second(&game);
    game.pause = assign_pause_s(&game); game.sound = assign_sounds();
    sfSound_setVolume(game.sound.click, game.soundvol);
    sfSound_setVolume(game.sound.heal, game.soundvol);
    sfSound_setVolume(game.sound.quest, game.soundvol);
    game.damien = create_damien();
    return game;
}
