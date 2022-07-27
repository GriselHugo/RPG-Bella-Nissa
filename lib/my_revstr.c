/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** Reverse a string
*/

#include "../include/rpg.h"

char *my_revstr(char *str)
{
    char temp;
    int i = 0;
    int j = my_strlen(str) - 1;

    while (i < j) {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        i++;
        j--;
    }
    return (str);
}
