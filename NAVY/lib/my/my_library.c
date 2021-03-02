/*
** EPITECH PROJECT, 2020
** $MY_LIBRARY
** File description:
** my_library
*/

#include "my_lib.h"

void my_library(char *src, va_list args, int i)
{
    if (src[i] == 'i' || src[i] == 'd')
        my_putnbr(va_arg(args, int));
    if (src[i] == 's')
        my_putstr(va_arg(args, char *));
    if (src[i] == 'p')
        my_put_address(va_arg(args, int));
    if (src[i] == 'x')
        my_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
    if (src[i] == 'X')
        my_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
}

void my_other_library(char *src, va_list args, int i)
{
    if (src[i] == 'o')
        my_putnbr_base(va_arg(args, unsigned int), "01234567");
    if (src[i] == 'b')
        my_putnbr_base(va_arg(args, unsigned int), "01");
    if (src[i] == 'u')
        my_putnbr(va_arg(args, unsigned int));
    if (src[i] == 'S')
        my_putstr_isprintable(va_arg(args, char *));
    if (src[i] == 'c')
        my_putchar(va_arg(args, int));
}

void my_other_other_library(char *src, va_list args, int i)
{
    if (src[i] == '%' && src[i - 1] == '%')
        my_putchar('%');
    if (src[i] == 'f' || src[i] == 'F')
        my_float(va_arg(args, double));
    if (src[i] == 'e')
        my_scientific(va_arg(args, double), 0);
    if (src[i] == 'E')
        my_scientific(va_arg(args, double), 1);
    if (src[i] == 'm')
        my_error();
}

void my_other_other_other_library(char *src, va_list args, int i)
{
    if (src[i] == 'n')
        my_putstr(src - 2);
}