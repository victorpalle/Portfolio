/*
** EPITECH PROJECT, 2020
** play_one.c
** File description:
** play one
*/

#include "my_navy.h"

extern core_t *global;

void manage_player_one(navy_t *s)
{
    coord_t *coord;

    fill_global();
    print_gameboard(s);
    coord = read_message_and_send(s);
    get_response();
    modif_adv_map(s, coord);
    if (s->win == 14)
        return;
    my_printf("\nwaiting for enemy's attack...\n");
    get_message();
    my_printf("%c%d: ", global->cpt_l + '@', global->cpt_n);
    modif_map(s);
    free(coord);
}

void print_first_message_player_one(void)
{
    int pid = getpid();

    my_printf("my_pid: %d\n", pid);
    my_printf("waiting for enemy connexion...\n");
    get_first_signal();
    my_printf("\nenemy connected\n");
}

void player_one(navy_t *s)
{
    print_first_message_player_one();
    s->pid_adv = global->ppid;
    while (s->win < 14 && s->win_adv < 14)
        manage_player_one(s);
}