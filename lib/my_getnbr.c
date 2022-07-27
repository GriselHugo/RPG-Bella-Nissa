/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** return a number sent as a string
*/

int signe(char const *str, int nb)
{
    int x = 0;

    while (str[x] < 48 || str[x] > 57) {
        if (str[x] == 45) {
            nb *= -1;
        } else if (str[x] == 43 && nb < 0) {
            nb = nb - nb * 2;
        }
        x++;
    }
    return (nb);
}

int find_nbr(char c)
{
    if (c >= 48 && c <= 57) {
        return (c - 48);
    }
    return (0);
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int i = 0;

    while (str[i] != '\0') {
        nb += find_nbr(str[i]);
        if (str[i + 1] < 58 && str[i + 1] > 47) {
            nb *= 10;
        } else if (nb != 0) {
            break;
        }
        i++;
    }
    nb = signe(str, nb);
    return (nb);
}
