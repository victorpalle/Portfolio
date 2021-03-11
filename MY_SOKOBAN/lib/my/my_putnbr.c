/*
** EPITECH PROJECT, 2020
** $MY_PUT_NBR
** File description:
** No file there, just an epitech header example
*/

#include <unistd.h>
#include "../../include/my.h"

int my_putnbr(int nb)
{
    int var = nb, i = 0, res = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    else if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    for (i = 0; var > 0; i++) {
        var /= 10;
        res *= 10;
    }
    var = nb * 10;
    for (i = i; i > 0; i--) {
        my_putchar((var / res) % 10 + 48);
        res /= 10;
    }
    return (0);
}
