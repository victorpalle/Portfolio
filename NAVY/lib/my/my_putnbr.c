/*
** EPITECH PROJECT, 2020
** $MY_PUTNBR
** File description:
** my_putnbr//base//address
*/

#include "my_lib.h"

int my_putnbr(int nb)
{
    int digit;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        digit = nb % 10;
        nb = (nb - digit) / 10;
        my_putnbr(nb);
        my_putchar('0' + digit);
    }
    else
        my_putchar('0' + nb);
    return (0);
}

int my_putnbr_base(unsigned int nb, char *base)
{
    unsigned int result, rest;

    result = nb / my_strlen(base);
    rest = nb % my_strlen(base);
    if (result > 0)
        my_putnbr_base(result, base);
    my_putchar(base[rest]);
    return (0);
}

int my_put_address(int nbr)
{
    int address = 0;

    if (nbr == 0)
        address = my_putstr("0x00000000");
    else {
        address = my_putstr("0x");
        address = my_putnbr_base(nbr, "0123456789abcdef");
    }
    return (address);
}

int my_getnbr(char *str)
{
    long i = 0;
    long nb = 0;
    long sign = 1;

    while (str[i] < '0' || str[i] > '9')
        i++;
    while (str[i] >= '0' && str[i] <= '9') {
        if (str[i - 1] == 45)
            sign *= -1;
        nb = nb * 10 + str[i++] - '0';
        if (nb > 2147483647 || nb < -2147483648)
            return (0);
    }
    return (nb * sign);
}