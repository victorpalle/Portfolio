/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** task01
*/

#include <stdio.h>
#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int j;

    i = my_strlen(dest);
    j = 0;
    while (src[j] != '\0') {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return (dest);
}
