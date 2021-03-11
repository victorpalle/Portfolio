/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-victor.palle
** File description:
** win_bis
*/

#include "sokoban.h"

int get_nbr_real_o(param_t *param, coord_t **xy)
{
    int k = 0;
    int i = 0;
    int cpt = 0;

    while (xy[k]->x != 199) {
        if (param->map[xy[k]->x][xy[k]->y] == 'P') {
            cpt++;
        }
        k++;
    }
    return (cpt);
}