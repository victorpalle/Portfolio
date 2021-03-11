/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-1-myrunner-victor.palle
** File description:
** map
*/

#include "runner.h"

int nb_enemy(char *map)
{
    int i = 0;
    int cpt = 0;

    while (map[i] != '\0') {
        if (map[i] == '1')
            cpt++;
        i++;
    }
    return (cpt);
}

char *fill_map(char *file)
{
    char *buffer = malloc(50);
    int fd;
    int offset = 0;
    int len;
    struct stat param;

    if ((fd = open(file, O_RDONLY)) == -1) {
        my_putstr("Couldn't open file");
    }
    while ((len = read(fd, buffer + offset, 50 - offset)) > 0) {
        offset = offset + len;
    }
    buffer[offset] = '\0';
    close(fd);
    return (buffer);
}