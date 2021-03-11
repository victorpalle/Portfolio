/*
** EPITECH PROJECT, 2020
** bsq.h
** File description:
** bsq
*/

#ifndef SOKOBAN_H
#define SOKOBAN_H

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define EXIT_USAGE 84
#define EXIT_BASE 84
#define EXIT_SIZE_NEG 84
#define EXIT_MALLOC 84
#define EXIT_READ 84
#define EXIT_OPS 84
#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG "error"


typedef struct param_s {
    char **map;
    char *buffer;
    char *file;
    int x;
    int y;
    int col;
    int row;
    int nbr_o;
} param_t;

typedef struct coord_s {
    int x;
    int y;
} coord_t;

//sokoban.c

void sokoban(char *file);
void init_game(param_t *param);
void print_screen(param_t *param);

//map_handling.c

char *file_to_buffer(char *file);
int count_line(char *buffer);
int count_col(char *buff);
int tab_len(param_t *param);
int len_of_line(param_t *param);

//str_to_tab.c

char **malloc_arr(char *buff);

//analyze.c

int get_nbr_o(param_t *param);
int get_pos_p(param_t *param);
int get_nbr_x(param_t *param);

//move.c

int check_move(param_t *param);

//win_loose.c

int check_win(param_t *param, coord_t **xy);
int check_loose(param_t *param);

//o_handling.c

coord_t **get_coord_o(coord_t **xy, param_t *param);
int manage_dot(param_t *param, coord_t **xy);

//error.c

int error_handling(param_t *param);

//win_bis.c

int get_nbr_real_o(param_t *param, coord_t **xy);

#endif
