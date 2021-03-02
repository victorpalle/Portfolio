/*
** EPITECH PROJECT, 2020
** handle_signal.c
** File description:
** handle signal
*/

#include "my_navy.h"

extern core_t *global;

void first_signal_handler(int sig, siginfo_t *info, void *secret)
{
    global->ppid = info->si_pid;

    if (sig == SIGUSR1 && global->start == 0)
        global->start = 1;
}

void get_first_signal(void)
{
    struct sigaction action;
    sigset_t mask;

    sigemptyset(&mask);
    action.sa_mask = mask;
    action.sa_sigaction = first_signal_handler;
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &action, NULL);
    while (global->start == 0)
        ;
}

void signal_handler(int sig, siginfo_t *info, void *secret)
{
    if (sig == SIGUSR1)
        global->cpt = (global->cpt) + 1;
    if (sig == SIGUSR2) {
        global->cpt_sig2 += 1;
        if (global->cpt_sig2 == 2) {
            global->cpt_n = global->cpt;
            global->received = 1;
        }
        if (global->cpt_sig2 == 1) {
            global->cpt_l = global->cpt;
            global->cpt = 0;
        }
    }
}

void get_message(void)
{
    struct sigaction action;
    sigset_t mask;

    sigemptyset(&mask);
    action.sa_mask = mask;
    action.sa_sigaction = signal_handler;
    action.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    while (global->received != 1)
        ;
}