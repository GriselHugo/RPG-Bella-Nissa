/*
** EPITECH PROJECT, 2021
** list_function.c
** File description:
** manage chained list
*/

#include "../include/rpg.h"

list *add_end(list *li, void *value)
{
    list *node;

    node = malloc(sizeof(*node));
    if (node == NULL) {
        return (NULL);
    }
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    if (is_empty(li)) {
        return (node);
    }
    list *temp;
    temp = li;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    node->prev = temp;
    temp->next = node;
    return (li);
}

list *add_front(list *li, void *value)
{
    list *node;

    node = malloc(sizeof(*node));
    if (node == NULL)
        return (NULL);
    node->value = value;
    node->prev = NULL;
    if (is_empty(li))
        node->next = NULL;
    else {
        node->next = li;
        li->prev = node;
    }
    return (node);
}

list *rem_end(list *li)
{
    if (is_empty(li))
        return new_list();
    if (li->next == NULL) {
        free(li);
        li = NULL;
        return new_list();
    }
    list *temp = li;
    list *before = li;
    while (temp->next != NULL) {
        before = temp;
        temp = temp->next;
    }
    before->next = NULL;
    free(temp);
    temp = NULL;
    return (li);
}

list *rem_front(list *li)
{
    list *node;

    if (is_empty(li))
        return (li);
    node = malloc(sizeof(*node));
    if (node == NULL)
        return (NULL);
    node = li->next;
    free(li);
    li = NULL;
    return (node);
}
