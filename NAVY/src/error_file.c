/*
** EPITECH PROJECT, 2020
** SEMESTRE 1
** File description:
** error_file
*/

#include "my_navy.h"

int check_numbers(char *buffer)
{
    if (buffer[3] != '1' && buffer[3] != '2' && buffer[3] != '3'
    && buffer[3] != '4' && buffer[3] != '5' && buffer[3] != '6'
    && buffer[3] != '7' && buffer[3] != '8')
        return (84);
    if (buffer[11] != '1' && buffer[11] != '2' && buffer[11] != '3'
    && buffer[11] != '4' && buffer[11] != '5' && buffer[11] != '6'
    && buffer[11] != '7' && buffer[11] != '8')
        return (84);
    if (buffer[19] != '1' && buffer[19] != '2' && buffer[19] != '3'
    && buffer[19] != '4' && buffer[19] != '5' && buffer[19] != '6'
    && buffer[19] != '7' && buffer[19] != '8')
        return (84);
    if (buffer[27] != '1' && buffer[27] != '2' && buffer[27] != '3'
    && buffer[27] != '4' && buffer[27] != '5' && buffer[27] != '6'
    && buffer[27] != '7' && buffer[27] != '8')
        return (84);
}

int check_numbers_bis(char *buffer)
{
    if (buffer[6] != '1' && buffer[6] != '2' && buffer[6] != '3'
    && buffer[6] != '4' && buffer[6] != '5' && buffer[6] != '6'
    && buffer[6] != '7' && buffer[6] != '8')
        return (84);
    if (buffer[14] != '1' && buffer[14] != '2' && buffer[14] != '3'
    && buffer[14] != '4' && buffer[14] != '5' && buffer[14] != '6'
    && buffer[14] != '7' && buffer[14] != '8')
        return (84);
    if (buffer[22] != '1' && buffer[22] != '2' && buffer[22] != '3'
    && buffer[22] != '4' && buffer[22] != '5' && buffer[22] != '6'
    && buffer[22] != '7' && buffer[22] != '8')
        return (84);
    if (buffer[30] != '1' && buffer[30] != '2' && buffer[30] != '3'
    && buffer[30] != '4' && buffer[30] != '5' && buffer[30] != '6'
    && buffer[30] != '7' && buffer[30] != '8')
        return (84);
}

int check_letters(char *buffer)
{
    if (buffer[2] != 'A' && buffer[2] != 'B' && buffer[2] != 'C'
    && buffer[2] != 'D' && buffer[2] != 'E' && buffer[2] != 'F'
    && buffer[2] != 'G' && buffer[2] != 'H')
        return (84);
    if (buffer[10] != 'A' && buffer[10] != 'B' && buffer[10] != 'C'
    && buffer[10] != 'D' && buffer[10] != 'E' && buffer[10] != 'F'
    && buffer[10] != 'G' && buffer[10] != 'H')
        return (84);
    if (buffer[18] != 'A' && buffer[18] != 'B' && buffer[18] != 'C'
    && buffer[18] != 'D' && buffer[18] != 'E' && buffer[18] != 'F'
    && buffer[18] != 'G' && buffer[18] != 'H')
        return (84);
    if (buffer[26] != 'A' && buffer[26] != 'B' && buffer[26] != 'C'
    && buffer[26] != 'D' && buffer[26] != 'E' && buffer[26] != 'F'
    && buffer[26] != 'G' && buffer[26] != 'H')
        return (84);
}

int check_letters_bis(char *buffer)
{
    if (buffer[5] != 'A' && buffer[5] != 'B' && buffer[5] != 'C'
    && buffer[5] != 'D' && buffer[5] != 'E' && buffer[5] != 'F'
    && buffer[5] != 'G' && buffer[5] != 'H')
        return (84);
    if (buffer[13] != 'A' && buffer[13] != 'B' && buffer[13] != 'C'
    && buffer[13] != 'D' && buffer[13] != 'E' && buffer[13] != 'F'
    && buffer[13] != 'G' && buffer[13] != 'H')
        return (84);
    if (buffer[21] != 'A' && buffer[21] != 'B' && buffer[21] != 'C'
    && buffer[21] != 'D' && buffer[21] != 'E' && buffer[21] != 'F'
    && buffer[21] != 'G' && buffer[21] != 'H')
        return (84);
    if (buffer[29] != 'A' && buffer[29] != 'B' && buffer[29] != 'C'
    && buffer[29] != 'D' && buffer[29] != 'E' && buffer[29] != 'F'
    && buffer[29] != 'G' && buffer[29] != 'H')
        return (84);
}
