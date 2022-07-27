/*
** EPITECH PROJECT, 2022
** inventory.c
** File description:
** All concerning the inventory is here
*/

#include "../../include/rpg.h"

void check_inventory(inv_t *inv, char **config)
{
    char *line = find_in_config("INV", config);
    inv->items = str_to_word_array(line, ',');
    if (inv->items[0][0] == '1')
        inv->gun.obtained = true;
    if (inv->items[1][0] == '1')
        inv->potion.obtained = true;
    if (inv->items[2][0] == '1')
        inv->cycle.obtained = true;
    if (inv->items[3][0] == '1')
        inv->card.obtained = true;
    if (inv->items[4][0] == '1')
        inv->map.obtained = true;
}

inv_t assign_inventory(void)
{
    inv_t inv;
    inv.open = false; inv.pizza = false;
    inv.sprite = sfSprite_create();
    inv.texture = sfTexture_createFromFile("assets/inventory.png", NULL);
    sfSprite_setTexture(inv.sprite, inv.texture, sfTrue);
    sfSprite_setScale(inv.sprite, (sfVector2f) {0.5, 0.5});
    sfSprite_setPosition(inv.sprite, (sfVector2f) {480, 270});
    inv.gun = create_item("assets/items/gun.png", (sfVector2f) {651, 493});
    inv.potion = create_item("assets/items/potion.png",
    (sfVector2f) {783, 493});
    inv.cycle = create_item("assets/items/velo.png", (sfVector2f) {915, 493});
    inv.card = create_item("assets/items/access.png", (sfVector2f) {1047,493});
    inv.map = create_item("assets/items/map.png", (sfVector2f) {1179, 493});
    return inv;
}

void inventory_pop(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) && game->play.inv.open == false) {
        game->play.inv.open = true;
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyE) && game->play.inv.open == true) {
        game->play.inv.open = false;
        return;
    }
}

void render_stats(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->play.inv.speed.stat, NULL);
    sfRenderWindow_drawText(game->window, game->play.inv.dmg.stat, NULL);
    sfRenderWindow_drawText(game->window, game->play.inv.rst.stat, NULL);
}

void check_display_inv(game_t *game)
{
    if (game->play.inv.open == true) {
        sfRenderWindow_drawSprite(game->window, game->play.inv.sprite, NULL);
        render_stats(game);
        if (game->play.inv.gun.obtained == true)
            sfRenderWindow_drawSprite(game->window,
            game->play.inv.gun.sprite, NULL);
        if (game->play.inv.potion.obtained == true)
            sfRenderWindow_drawSprite(game->window,
            game->play.inv.potion.sprite, NULL);
        if (game->play.inv.cycle.obtained == true)
            sfRenderWindow_drawSprite(game->window,
            game->play.inv.cycle.sprite, NULL);
        if (game->play.inv.card.obtained == true)
            sfRenderWindow_drawSprite(game->window,
            game->play.inv.card.sprite, NULL);
        if (game->play.inv.map.obtained == true)
            sfRenderWindow_drawSprite(game->window,
            game->play.inv.map.sprite, NULL);
    }
}
