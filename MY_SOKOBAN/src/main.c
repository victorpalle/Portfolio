/*
** EPITECH PROJECT, 2021
** sokoban_test
** File description:
** main
*/

#include "sokoban.h"

static void helper(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    map  file representing the warehouse map, containing");
    my_putstr(" '#' for walls, 'P' for the player, 'X' for boxes");
    my_putstr(" and 'O' for storage locations.\n");
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (my_strcmp(av[1], "-h") == 0) {
            helper();
            exit(0);
        }
        sokoban(av[1]);
    } else {
        my_putstr("Wrong usage. \n\nUsage : ./my_sokoban map\n");
        return (84);
    }
}