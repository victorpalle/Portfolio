/*
** EPITECH PROJECT, 2020
** SEMESTRE 1
** File description:
** modif_map_adv
*/

#include "my_navy.h"

extern core_t *global;

void modif_adv_map(navy_t *s, coord_t *coord)
{
    if (global->cpt_resp == 1) {
        s->map_adv[coord->nbr - 1][coord->ltr - 1] = 'x';
        s->win += 1;
    }
    if (global->cpt_resp == 2)
        s->map_adv[coord->nbr - 1][coord->ltr - 1] = 'o';
}