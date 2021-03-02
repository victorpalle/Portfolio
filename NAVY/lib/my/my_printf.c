/*
** EPITECH PROJECT, 2020
** $MY_PRINTF
** File description:
** my_printf
*/

#include "my_lib.h"

int my_printf(char *src, ...)
{
    va_list args;
    int i = 0, blank = 0;

    va_start(args, src);
    while (src[i] != '\0') {
        if (src[i] == '%') {
            for (i; src[i + 1] == ' '; ++i) {
                my_handler(src, args, i);
            } if (src[i + 1] == '#') {
                i++;
                my_hash_specfifiers_library(src, args, i);
            }
            i++;
            my_parser(src, args, i);
        } else
            my_putchar(src[i]);
        i++;
    }
    va_end(args);
    return (0);
}