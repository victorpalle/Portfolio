/*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-1-navy-martin.vanaud
** File description:
** modif_map
*/

#include "my_navy.h"

extern core_t *global;

int isnum(char num)
{
    if (num >= '2' && num <= '5')
        return (1);
    else
        return (0);
}

void modif_map(navy_t *s)
{
    if (isnum(s->map[(global->cpt_n) - 1][(global->cpt_l) - 1]) == 1) {
        s->map[(global->cpt_n) - 1][(global->cpt_l) - 1] = 'x';
        usleep(100);
        kill(s->pid_adv, SIGUSR1);
        my_printf("hit\n");
        s->win_adv += 1;
    } else {
        s->map[(global->cpt_n) - 1][(global->cpt_l) - 1] = 'o';
        usleep(100);
        kill(s->pid_adv, SIGUSR2);
        my_printf("missed\n");
    }
}