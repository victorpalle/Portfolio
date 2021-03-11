/*
** EPITECH PROJECT, 2020
** buff_to_arr.c
** File description:
** buff to arr
*/

#include "sokoban.h"

int count_line(char *buffer)
{
    int i = 0;
    int l = 0;

    while (buffer[i]) {
        if (buffer[i] == '\n')
            l++;
        i++;
    }
    return (l);
}

int count_col(char *buff)
{
    int i = 0;
    int j = 0;

    while (buff[i] != '\n') {
        i = i + 1;
        j = j + 1;
    }
    i = i + 1;
    j = j + 1;
    while (buff[i] != '\n' && buff[i] != '\0')
        i = i + 1;
    return (i - j);
}

char **buffer_to_arr(char **arr, char *buff)
{
    int cpt = 0, i = 0, j = 0;

    while (buff[cpt] != '\0') {
        if (buff[cpt] == '\n' || buff[cpt] == '\0') {
            arr[i][j] = '\0';
            i++;
            j = 0;
        }
        else {
            arr[i][j] = buff[cpt];
            j++;
        }
        cpt++;
    }
    return (arr);
}

char **malloc_arr(char *buff)
{
    char **arr;
    int i = 0;

    arr = malloc(sizeof(arr) * (count_line(buff) + 1));
    if (arr == NULL)
        exit(84);
    while (i < count_line(buff)) {
        arr[i] = malloc(sizeof(arr) * (count_col(buff) + 1));
        if (arr[i] == NULL)
            exit(84);
        i++;
    }
    arr = buffer_to_arr(arr, buff);
    return (arr);
}
