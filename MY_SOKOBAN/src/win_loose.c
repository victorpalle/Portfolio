/*
** EPITECH PROJECT, 2021
** sokoban_test
** File description:
** win_loose
*/

#include "sokoban.h"

int check_neighboors(int x, int y, char **map)
{
    if ((map[x + 1][y] == 'X' || map[x + 1][y] == '#')
    && (map[x][y - 1] == 'X' || map[x][y + 1] == 'X'
    || map[x][y - 1] == '#' || map[x][y + 1] == '#')) {
        return (0);
    }
    if ((map[x - 1][y] == 'X' || map[x - 1][y] == '#')
    && (map[x][y - 1] == 'X' || map[x][y + 1] == 'X'
    || map[x][y - 1] == '#' || map[x][y + 1] == '#')) {
        return (0);
    }
    return (1);
}

int loose_screen(param_t *param)
{
    print_screen(param);
    endwin();
    exit(1);
}

int check_loose(param_t *param)
{
    int i = 1;
    int j = 1;
    int cpt = 0;

    while (param->map[i + 1]) {
        j = 1;
        while (param->map[i][j + 1] != '\0') {
            if ((check_neighboors(i, j, param->map) == 0) && \
            (param->map[i][j] == 'X')) {
                cpt++;
            }
            j++;
        }
        i++;
    }
    if (cpt == get_nbr_x(param))
        loose_screen(param);
    return (0);
}

int win_screen(param_t *param)
{
    print_screen(param);
    endwin();
    exit(0);
}

int check_win(param_t *param, coord_t **xy)
{
    int nbr;

    nbr = get_nbr_o(param);
    if (nbr == 0 && (get_nbr_real_o(param, xy) == 0)) {
        win_screen(param);
    }
    return (0);
}