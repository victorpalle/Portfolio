/*
** EPITECH PROJECT, 2020
** SEMESTRE 1
** File description:
** handle_map
*/

#include "my_navy.h"

void print_map(char **map)
{
    int count = 0, rows = 0, cols = 0;

    my_printf("\n");
    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (count = 0; count < 8; count++) {
        rows = 0;
        my_printf("%d|", count + 1);
        for (rows = 0; rows <= 7; rows++)
            my_printf("%c ", map[cols][rows]);
        cols++;
        my_printf("\n");
    }
}

void print_gameboard(navy_t *s)
{
    my_printf("\nmy positions:");
    print_map(s->map);
    my_printf("\nenemy's positions:");
    print_map(s->map_adv);
}