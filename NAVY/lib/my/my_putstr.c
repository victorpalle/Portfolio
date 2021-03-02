/*
** EPITECH PROJECT, 2020
** $MY_PUTSTR
** File description:
** my_putstr//my_strlen//isprintable
*/

#include "my_lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return (0);
}

void my_putstr_isprintable(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] > 32 && str[i] <= 127)
            my_putchar(str[i]);
        else if (str[i] < 8) {
            my_putstr("\\00");
            my_putnbr_base(str[i], "01234567");
        } else {
            my_putstr("\\0");
            my_putnbr_base(str[i], "01234567");
        }
    }
}