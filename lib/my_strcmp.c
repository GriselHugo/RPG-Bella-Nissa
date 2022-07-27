/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** Compare two strings and return 0 if sames
*/

#include "../include/rpg.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (1);
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (1);
        else
            i++;
    }
    return (0);
}
