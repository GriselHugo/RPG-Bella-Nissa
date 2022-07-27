/*
** EPITECH PROJECT, 2022
** my_itoa.c
** File description:
** Convert an int to string
*/

#include "../include/rpg.h"

void *my_itoa(int n, char *s)
{
    int i = 0;
    int nega;

    if ((nega = n) < 0)
        n = -n;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (nega < 0)
        s[i++] = '-';
    s[i] = '\0';
    my_revstr(s);
}
