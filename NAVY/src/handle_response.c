/*
** EPITECH PROJECT, 2020
** SEMESTRE 1
** File description:
** handle_response
*/

#include "my_navy.h"

extern core_t *global;

void signal_handler_response(int sig, siginfo_t *info, void *secret)
{
    if (sig == SIGUSR1) {
        global->cpt_resp = 1;
        my_printf("hit\n");
        global->response = 1;
    }
    if (sig == SIGUSR2) {
        global->cpt_resp = 2;
        my_printf("missed\n");
        global->response = 1;
    }
}

void get_response(void)
{
    struct sigaction action;
    sigset_t mask;

    sigemptyset(&mask);
    action.sa_mask = mask;
    action.sa_sigaction = signal_handler_response;
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    while (global->response != 1)
        ;
}