/*
** EPITECH PROJECT, 2020
** SEMESTRE 1
** File description:
** error_syntax
*/

#include "my_navy.h"

int check_syntax(char *buffer)
{
    if (buffer[0] != '2' || buffer[8] != '3' || buffer[16] != '4'
    || buffer[24] != '5')
        return (84);
    if (buffer[1] != ':' || buffer[9] != ':' || buffer[17] != ':'
    || buffer[25] != ':')
        return (84);
    if (buffer[4] != ':' || buffer[12] != ':' || buffer[20] != ':'
    || buffer[28] != ':')
        return (84);
}