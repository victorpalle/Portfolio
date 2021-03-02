/*
** EPITECH PROJECT, 2020
** SEMESTRE 1
** File description:
** navy_helper
*/

#include "my_navy.h"

void navy_help(void)
{
    my_printf("  USAGE\n");
    my_printf("/Player 1/   ./navy [navy positions]...\n\n");
    my_printf("/Player 2/   ./nave [player pid]...");
    my_printf("[navy positions]...\n\n");
    my_printf("  DESCRIPTION\n");
    my_printf("[player pid]\n");
    my_printf("pid of the ennemy player\n");
    my_printf("[navy positions] (as a file)\n");
    my_printf("file representing the positions of the ships\n");
    my_printf("the file must contains three parameters :\n");
    my_printf("LENGTH   FIRST SQUARE    LAST SQUARE\n");
    my_printf("note : the board must have 4 ships from size 2 to size 5\n");
}