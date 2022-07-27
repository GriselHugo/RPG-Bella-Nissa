/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** diverses functions for the programs
*/

#include "../include/rpg.h"

bool sprite_collision(sfSprite *sprite1, sfSprite *sprite2)
{
    sfFloatRect rect1 = sfSprite_getGlobalBounds(sprite1);
    sfFloatRect rect2 = sfSprite_getGlobalBounds(sprite2);

    if (sfFloatRect_intersects(&rect1, &rect2, NULL))
        return (true);
    else
        return (false);
}

bool is_in_window(sfVector2f pos)
{
    if (pos.x > -600 && pos.x < 1920 && pos.y > -600 && pos.y < 1080)
        return (true);
    return (false);
}

sfIntRect set_rect(int top, int left, int height, int width)
{
    sfIntRect rect;
    rect.top = top;
    rect.left = left;
    rect.height = height;
    rect.width = width;
    return (rect);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left >= max_value) {
        rect->left = 0;
    }
}

void move_rect_vert(sfIntRect *rect, int offset, int max_value)
{
    rect->top = rect->top + offset;
    if (rect->top >= max_value) {
        rect->top = 0;
    }
}

text_t create_text_stats(char *font, game_t *game, sfVector2f pos, char *stat)
{
    text_t text;
    int nbr = my_getnbr(find_in_config(stat,game->config));
    text.string = malloc(sizeof(char) * 1000);
    text.stat = sfText_create();
    text.font = sfFont_createFromFile(font);
    sfText_setColor(text.stat, sfBlack);
    sfText_setFont(text.stat, text.font);
    sfText_setString(text.stat, my_itoa(nbr, text.string));
    sfText_setPosition(text.stat, pos);
    sfText_setCharacterSize(text.stat, 40);
    return text;
}
