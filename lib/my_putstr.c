/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** Put characters one by one
*/

#include "../include/rpg.h"

int my_putstr(char const *str)
{
    int i;
    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    return (i);
}
