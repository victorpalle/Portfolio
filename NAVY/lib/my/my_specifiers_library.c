/*
** EPITECH PROJECT, 2020
** $MY_SPECIFIERS_LIBRARY
** File description:
** my_specifiers_library
*/

#include "my_lib.h"

void my_hash_specfifiers_library(char *src, va_list args, int i)
{
    if (src[i + 1] == 'o')
        my_putchar('0');
    if (src[i + 1] == 'x')
        my_putstr("0x");
    if (src[i + 1] == 'X')
        my_putstr("0X");
    if (src[i + 1] == 'f')
        i++;
    if (src[i + 1] == 'e')
        i++;
    if (src[i + 1] == 'E')
        i++;
}