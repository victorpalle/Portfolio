/*
** EPITECH PROJECT, 2020
** $SPECIAL
** File description:
** special
*/

#include "my_lib.h"

void my_float(double nbr)
{
    int dec = nbr * (double)1000000, integer = nbr, i = 0;
    double final_dec;

    dec -= integer * 1000000;
    final_dec = (double)dec;
    i += my_putnbr(integer);
    i++;
    my_putchar('.');
    i += my_putnbr((int)final_dec);
}

void my_scientific(double nbr, int maj)
{
    int i = 0;

    while (!(nbr < 10 && nbr > -10)) {
        nbr /= 10;
        i++;
    }
    my_float(nbr);
    if (maj == 1)
        my_putchar('E');
    else
        my_putchar('e');
    my_putchar('+');
    if (i < 10)
        my_putchar('0');
    my_putnbr(i);
}

void my_error(void)
{
    write(2, "Success", 7);
}