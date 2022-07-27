/*
** EPITECH PROJECT, 2022
** manual.c
** File description:
** manual for runner
*/

#include "../include/rpg.h"

void manual(void)
{
    my_putstr(GREEN"\nUSAGE\n");
    my_putstr(CYAN"./my_rpg\n\n");
    my_putstr(GREEN"OPTIONS\n");
    my_putstr(CYAN"-h\tprint the usage and quit\nemode\t\
activate eric mode\n\n");
    my_putstr(GREEN"USER INTERACTIONS\n");
    my_putstr(CYAN"Key Z\tMove UP\nKey S\tMove Down\nKey Q\tMove Left\n");
    my_putstr(CYAN"Key D\tMove Right\nKey E\tInventory\nEscape\tMenu\n\n");
    my_putstr(GREEN"DESCRIPTION\n");
    my_putstr(CYAN"Rpg game with open world and quests\n\n"RESET);
}
