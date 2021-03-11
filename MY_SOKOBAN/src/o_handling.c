/*
** EPITECH PROJECT, 2021
** sokoban_test
** File description:
** o_handling
*/

#include "sokoban.h"

int manage_dot(param_t *param, coord_t **xy)
{
    int k = 0;
    int i = 0;

    while (xy[k]->y != 199) {
        if (param->map[xy[k]->x][xy[k]->y] == ' ') {
            param->map[xy[k]->x][xy[k]->y] = 'O';
        }
        k++;
    }
}

coord_t *create(int i, int j)
{
    coord_t *xy;

    if ((xy = malloc(sizeof(coord_t))) == NULL)
        exit (84);
    xy->x = i;
    xy->y = j;
}

coord_t **get_coord_o(coord_t **xy, param_t *param)
{
    int i = 0;
    int j = 0;
    int k = 0;

    if ((xy = malloc((sizeof(coord_t) * get_nbr_o(param)) + 1)) == NULL)
        exit(84);
    while (param->map[i]) {
        j = 0;
        while (param->map[i][j]) {
            if (param->map[i][j] == 'O') {
                xy[k] = create(i, j);
                k++;
            }
            j++;
        }
        i++;
    }
    xy[k] = create(199, 199);
    return (xy);
}