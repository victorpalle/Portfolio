/*
** EPITECH PROJECT, 2020
** read_and_send.c
** File description:
** read and send
*/

#include "my_navy.h"

int is_validchar(char *message)
{
    if (message[0] >= 'A' && message[0] <= 'H')
        return (1);
    else
        return (0);
}

int is_validnum(char *message)
{
    if (message[1] >= '1' && message[1] <= '8')
        return (1);
    else if (message[2])
        return (0);
    else
        return (0);
}

int is_validmessage(char *message)
{
    if (is_validchar(message) == 1
    && is_validnum(message) == 1 && my_strlen(message) == 3)
        return (1);
    else
        return (0);
}

void send_message(navy_t *s, int letter, int number)
{
    while (letter > 0) {
        kill(s->pid_adv, SIGUSR1);
        usleep(100);
        letter--;
    }
    kill(s->pid_adv, SIGUSR2);
    usleep(100);
    while (number > 0) {
        kill(s->pid_adv, SIGUSR1);
        usleep(100);
        number--;
    }
    kill(s->pid_adv, SIGUSR2);
}

coord_t *read_message_and_send(navy_t *s)
{
    int check = 0;
    int size = 1;
    char buffer[4096] = {0};
    coord_t *coord = malloc(sizeof(coord_t));

    my_putstr("\nattack: ");
    while (size != 0 && (size = read(0, buffer, 4096)) > 0) {
        if (buffer[my_strlen(buffer) - 1] == '\n')
            break;
    }
    if (is_validmessage(buffer) == 1) {
        send_message(s, buffer[0] - '@', buffer[1] - '0');
        coord->ltr = buffer[0] - '@';
        coord->nbr = buffer[1] - '0';
        my_printf("%c%c: ", buffer[0], buffer[1]);
        return (coord);
    } else {
        my_printf("wrong position");
        read_message_and_send(s);
    }
}