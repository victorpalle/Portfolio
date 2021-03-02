/*
** EPITECH PROJECT, 2020
** SEMESTRE 1
** File description:
** handle_map
*/

#include "my_navy.h"

char **fill_map(void)
{
    char **map;
    int i = 0;

    map = malloc(sizeof(char *) * 9);
    map[8] = NULL;
    while (i <= 7) {
        map[i] = my_strdup("........");
        i++;
    }
    return (map);
}

void add_boat(char **map, char *buffer)
{
    int i = 0;
    int s_char = 0, s_num = 0;
    int e_char = 0, e_num = 0;

    while (i < 32) {
        s_num = buffer[i + 2] - 'A';
        s_char = buffer[i + 3] - '1';
        map[s_char][s_num] = buffer[i];
        e_num = buffer[i + 5] - 'A';
        e_char = buffer[i + 6] - '1';
        while (s_num <= e_num && s_char <= e_char) {
            map[s_char][s_num] = buffer[i];
            (buffer[i + 2] < buffer[i + 5]) ? s_num++ : s_char++;
        }
        i += 8;
    }
}

int check_buffer(char *buffer)
{
    if (check_letters(buffer) == 84)
        return (84);
    if (check_letters_bis(buffer) == 84)
        return (84);
    if (check_numbers(buffer) == 84)
        return (84);
    if (check_numbers_bis(buffer) == 84)
        return (84);
    if (check_syntax(buffer) == 84)
        return (84);
}

int fill_map_with_boat(char *file, navy_t *s)
{
    char *buffer;
    int fd = open(file, O_RDONLY);

    if (fd == -1 && my_strcmp(file, "-h") != 0) {
        my_printf("unknown file\n");
        s->error = 84;
        return (84);
    }
    buffer = malloc(sizeof(char) * 33);
    if (read(fd, buffer, 32) == -1) {
        s->error = 84;
        return (84);
    }
    if (check_buffer(buffer) == 84) {
        s->error = 84;
        return (84);
    }
    s->map = fill_map();
    add_boat(s->map, buffer);
    free(buffer);
    close(fd);
}