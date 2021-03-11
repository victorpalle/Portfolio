/*
** EPITECH PROJECT, 2021
** sokoban_test
** File description:
** map_handling
*/

#include "sokoban.h"

int len_of_line(param_t *param)
{
    int i = 0;

    while (param->map[0][i]) {
        i++;
    }
    return (i);
}

int tab_len(param_t *param)
{
    int i = 0;

    while (param->map[i])
        i++;
    return (i);
}

char *read_fd(int fd, int size)
{
    char *buffer;

    if ((buffer = malloc(size + 1)) == NULL)
        exit(84);
    if (read(fd, buffer, size) == -1)
        exit(84);
    buffer[size] = 0;
    return (buffer);

}

char *file_to_buffer(char *file)
{
    int fd;
    struct stat info;
    int size;
    char *buffer;

    if ((fd = open(file, O_RDONLY)) == -1)
        exit(84);
    if (stat(file, &info) == -1)
        exit(84);
    size = info.st_size;
    buffer = read_fd(fd, size);
    return (buffer);
}
