/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** task06
*/

#include <stdio.h>
#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int vrai = 0;
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            vrai = 1;
        }
        i++;
    }
    return (vrai);
}
