/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** getnbr
*/

#include <stdio.h>
#include "../../include/my.h"

int my_getnbr(char *str)
{
    int i = 0;
    int n = 0;
    int neg = 1;

    while (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-') {
            neg = neg * (-1);
        }
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        n = n * 10;
        n = str[i] - '0' + n;
        i++;
    }
    n = n * neg;
    return (n);
}
