/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** chained_list_mid
*/

#include "../include/rpg.h"

list *rem_mid(list *lst)
{
    if (lst->prev == NULL && lst->next == NULL) {
        return (NULL);
    }
    if (lst->prev == NULL) {
        lst = rem_front(lst);
        return (lst);
    }
    if (lst->next == NULL) {
        lst = rem_end(lst);
        return (lst);
    }
    list *prev = lst->prev;
    if (lst->next == NULL)
        prev->next = NULL;
    else {
        prev->next = lst->next;
        lst->next->prev = prev;
    }
    free(lst);
    return (prev);
}
