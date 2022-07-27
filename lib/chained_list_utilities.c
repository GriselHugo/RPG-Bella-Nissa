/*
** EPITECH PROJECT, 2021
** chained_list_utilities.c
** File description:
** contains utilities functions for chained list
*/

#include "../include/rpg.h"

list *new_list(void)
{
    return (NULL);
}

bool is_empty(list *li)
{
    if (li == NULL)
        return (true);
    return (false);
}

int list_len(list *li)
{
    int size = 0;

    if (!is_empty(li)) {
        while (li != NULL) {
            size++;
            li = li->next;
        }
    }
    return (size);
}

void print_list(list *li)
{
    list *tmp = li;
    if (is_empty(li)) {
        return;
    }
    while (tmp != NULL) {
        tmp = tmp->next;
    }
}

void destroy_list(list *li)
{
    while (!is_empty(li)) {
        li = rem_front(li);
    }
}
