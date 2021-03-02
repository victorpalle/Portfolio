/*
** EPITECH PROJECT, 2020
** fill_struct.c
** File description:
** fill_struct.c
*/

#include "my_navy.h"

extern core_t *global;

void fill_global(void)
{
    global = malloc(sizeof(core_t));
    global->start = 0;
    global->received = 0;
    global->response = 0;
    global->cpt_l = 0;
    global->cpt_n = 0;
    global->cpt_sig2 = 0;
    global->cpt = 0;
    global->cpt_resp = 0;
}

void fill_struct(navy_t *s)
{
    s->pid = getpid();
    s->pid_adv = 0;
    s->win = 0;
    s->win_adv = 0;
    s->error = 0;
}

void fill_map_and_struct(navy_t *s, int ac, char **av)
{
    s->map_adv = fill_map();
    if (ac == 2)
        fill_map_with_boat(av[1], s);
    if (ac == 3)
        fill_map_with_boat(av[2], s);
}
