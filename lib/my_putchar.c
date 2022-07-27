/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** display char.
*/

#include "../include/rpg.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
