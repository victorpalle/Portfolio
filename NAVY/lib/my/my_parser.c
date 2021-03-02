/*
** EPITECH PROJECT, 2020
** $MY_PARSER
** File description:
** my_parser
*/

#include "my_lib.h"

void my_parser(char *src, va_list args, int i)
{
    my_library(src, args, i);
    my_other_library(src, args, i);
    my_other_other_library(src, args, i);
    my_other_other_other_library(src, args, i);
}