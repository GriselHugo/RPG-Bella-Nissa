/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** Count and return numbers of characters in string passed as commenter
*/

#include "../include/rpg.h"

int my_strlen(char const *str)
{
    int i;
    i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
