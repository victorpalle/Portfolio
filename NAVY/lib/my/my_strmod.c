/*
** EPITECH PROJECT, 2020
** SEMESTRE 1
** File description:
** my_strmod
*/

#include "my_lib.h"

char *my_strdup(char *src)
{
    char *dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    dest = my_strcpy(dest, src);
    return (dest);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while ((s1[i] == s2[i]) && s1[i] && s2[i])
        i++;
    return (s1[i] - s2[i]);
}

char *my_strcat(char *dest, char *src)
{
    int i = 0, count = 0;
    int length = my_strlen(dest) + my_strlen(src);
    char *res = malloc(sizeof(char) * (length + 1));

    for (i = 0; res[i] = dest[i]; i++);
    while (src[count]) {
        res[i + count] = src[count];
        count++;
    }
    res[i + count] = '\0';
    return (res);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}