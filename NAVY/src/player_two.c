/*
** EPITECH PROJECT, 2020
** play_two.c
** File description:
** play  two
*/

#include "my_navy.h"

extern core_t *global;

void manage_player_two(navy_t *s)
{
    coord_t *coord;

    fill_global();
    print_gameboard(s);
    my_printf("\nwaiting for enemy's attack...\n");
    get_message();
    my_printf("%c%d: ", global->cpt_l + '@', global->cpt_n);
    modif_map(s);
    if (s->win_adv == 14)
        return;
    coord = read_message_and_send(s);
    get_response();
    modif_adv_map(s, coord);
    free(coord);
}

void print_first_message_player_two(void)
{
    int pid = getpid();

    my_printf("my_pid: %d\n", pid);
    my_printf("successfully connected\n");
}

void player_two(navy_t *s, char *pid)
{
    print_first_message_player_two();
    s->pid_adv = my_getnbr(pid);
    kill(s->pid_adv, SIGUSR1);
    while (s->win < 14 && s->win_adv < 14)
        manage_player_two(s);
}