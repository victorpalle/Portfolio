/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** task02
*/


#ifndef MY_H_
#define MY_H_

#include "runner.h"

void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char * my_strncpy(char *dest, char const *src, int n);
int my_getnbr(char *str);
int my_putnbr(int n);
char *my_strdup(char const *c);
int analyse_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite);

#endif

