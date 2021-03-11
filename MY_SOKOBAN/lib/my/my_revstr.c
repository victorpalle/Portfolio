/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** day06
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int i = my_strlen(str);
    int j = 0;
    char c;

    while (j < i / 2) {
        c = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = c;
        j++;
    }
    return (str);
}