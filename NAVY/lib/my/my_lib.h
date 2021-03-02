/*
** EPITECH PROJECT, 2020
** $MY_LIB_H_
** File description:
** my_lib_h_
*/

#ifndef MY_LIB_H_
#define MY_LIB_H_

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void my_putchar(char c);
int my_putstr(char *str);
int my_strlen(char *str);
int my_putnbr(int nb);
int my_putnbr_base(unsigned int nb, char *base);
int my_put_address(int nbr);
int my_getnbr(char *str);
int my_printf(char *src, ...);
void my_putstr_isprintable(char *str);
void my_library(char *src, va_list args, int i);
void my_other_library(char *src, va_list args, int i);
void my_other_other_library(char *src, va_list args, int i);
void my_scientific(double nbr, int maj);
void my_float(double nbr);
void my_error(void);
void my_parser(char *src, va_list args, int i);
void my_hash_specfifiers_library(char *src, va_list args, int i);
void my_other_other_other_library(char *src, va_list args, int i);
void my_length_specifiers_library(char *src, va_list args, int i);
void my_number_specifiers_library(char *src, va_list args, int i);
void my_type_specifiers_library(char *src, va_list args, int i);
int my_handler(char *src, va_list args, int i);
char *my_strdup(char *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char *src);
char *my_strcpy(char *dest, char const *src);
void my_swap(int *a, int *b);

#endif /* !MY_LIB_H_ */