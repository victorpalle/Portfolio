/*
** EPITECH PROJECT, 2020
** $MY_HANDLER
** File description:
** my_handler
*/

#include "my_lib.h"

int my_handler(char *src, va_list args, int i)
{
    if (src[i + 2] == 'd' || src[i + 2] == 'i')
        my_putchar(' ');
}