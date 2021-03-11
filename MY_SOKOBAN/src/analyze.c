/*
** EPITECH PROJECT, 2021
** sokoban_test
** File description:
** analyze
*/

#include "sokoban.h"

int get_nbr_x(param_t *param)
{
    int i = 0;
    int j = 0;
    int cpt = 0;

    while (param->map[i]) {
        j = 0;
        while (param->map[i][j]) {
            if (param->map[i][j] == 'X')
                cpt++;
            j++;
        }
        i++;
    }
    return (cpt);
}

int get_nbr_o(param_t *param)
{
    int i = 0;
    int j = 0;
    int cpt = 0;

    while (param->map[i]) {
        j = 0;
        while (param->map[i][j]) {
            if (param->map[i][j] == 'O')
                cpt++;
            j++;
        }
        i++;
    }
    return (cpt);
}

int get_pos_p(param_t *param)
{
    int i = 0;
    int j = 0;
    int cpt = 0;

    while (param->map[i]) {
        j = 0;
        while (param->map[i][j]) {
            if (param->map[i][j] == 'P') {
                param->x = i;
                param->y = j;
                cpt++;
            }
            j++;
        }
        i++;
    }
    if (cpt != 1)
        exit(84);
}