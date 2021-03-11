/*
** EPITECH PROJECT, 2021
** sokoban_test
** File description:
** error
*/

#include "sokoban.h"

int check_map(param_t *param)
{
    int i = 0;
    int cpt = 0;

    while (param->map[0][i]) {
        if (param->map[0][i] != '#')
            cpt++;
        i++;
    }
    i = 0;
    while (param->map[tab_len(param) - 1][i]) {
        if (param->map[tab_len(param) - 1][i] != '#')
            cpt++;
        i++;
    }
    if (cpt != 0)
        return (1);
    return (0);
}

int check_characters(char **map)
{
    int i = 0, j = 0, cpt = 0;

    while (map[i]) {
        j = 0;
        while (map[i][j]) {
            if (map[i][j] != '#' && map[i][j] != 'P' && map[i][j] != 'X' \
            && map[i][j] != 'O' && map[i][j] != ' ')
                cpt++;
            j++;
        }
        i++;
    }
    if (cpt != 0)
        return (1);
    return (0);
}

int error_handling(param_t *param)
{
    if (get_nbr_o(param) != get_nbr_x(param))
        exit(84);
    if (check_characters(param->map) == 1)
        exit(84);
    if (check_map(param) == 1)
        exit (84);
}