/*
** EPITECH PROJECT, 2022
** str_to_word_array.c
** File description:
** put a string in an array
*/

#include "../include/rpg.h"

char **str_to_word_array(char *str, char delim)
{
    char **arr;
    int words = 0;
    int i, j, letters, index;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim)
            words++;
    }
    arr = malloc(sizeof(char *) * (words + 2));
    for (i = 0, index = 0; index <= words; index++) {
        for (letters = 0, j = i; str[j] != delim; j++, letters++);
        arr[index] = malloc(sizeof(char) * (letters + 1));
        for (j = 0; j < letters; j++, i++)
            arr[index][j] = str[i];
        arr[index][j] == '\0';
        i++;
    }
    arr[words] == NULL;
    return (arr);
}
