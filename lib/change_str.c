/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-romain.oeil
** File description:
** change a str by an another (both need to be the same len)
*/

void change_str(char *dest, char *src)
{
    for (int i = 0; dest[i] != '\0'; i++) {
        dest[i] = '\0';
    }
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
}
