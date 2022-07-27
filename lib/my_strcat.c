/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** concatene two strings
*/

#include "../include/rpg.h"

char *my_strcat(char *dest, char const *src)
{
    char *str;
    int i = 0;
    int y = 0;

    str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    for (i = 0; dest[i] != '\0'; i++) {
        str[y] = dest[i];
        y++;
    }
    for (i = 0; src[i] != '\0'; i++) {
        str[y] = src[i];
        y++;
    }
    str[y] = '\0';
    return (str);
}
