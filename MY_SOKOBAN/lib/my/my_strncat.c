/*
** EPITECH PROJECT, 2020
** my_strncat.c
** File description:
** task03
*/

#include <stdio.h>
#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;
    int j;

    i = my_strlen(dest);
    j = 0;
    while (j < nb && src[j] != '\0') {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return (dest);
}
