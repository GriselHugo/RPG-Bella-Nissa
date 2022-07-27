/*
** EPITECH PROJECT, 2022
** my_tab_to_str
** File description:
** transform an array into an str
*/

#include "../include/rpg.h"

char *my_tab_to_str(char **tab, char *str, char delim)
{
    char str_delim[2];
    str_delim[0] = delim;
    str_delim[1] = '\0';
    int i = 0;
    for (i = 0; tab[i] != NULL; i++) {
        str = my_strcat(str, tab[i]);
        str = my_strcat(str, str_delim);
    }
    return str;
}

char *item_tab_to_str(char **tab, char *str, char delim)
{
    char str_delim[2];
    str_delim[0] = delim;
    str_delim[1] = '\0';
    int j = 0;
    for (int i = 0; j < 9; j++) {
        if (j == 0 || j % 2 == 0) {
            str[j] = tab[i][0];
            i++;
        } else
            str[j] = delim;
    }
    str[j] = '\0';
    return (str);
}
