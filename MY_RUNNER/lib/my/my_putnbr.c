/*
** EPITECH PROJECT, 2020
** my_putnbr.c
** File description:
** putnbr
*/

#include "../../include/my.h"

int my_putnbr(int n)
{
    int res;

    if (n < 0) {
        n = - n;
        my_putchar('-');
    }
    if (n > 9) {
        my_putnbr(n / 10);
    }
    res = n % 10 + 48;
    my_putchar(res);
    return (0);
}
