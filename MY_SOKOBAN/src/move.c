/*
** EPITECH PROJECT, 2021
** sokoban_test
** File description:
** move
*/

#include "sokoban.h"

int move_right(param_t *param)
{
    if (param->map[param->x][param->y + 1] != '#' && \
    param->map[param->x][param->y + 1] != 'X')
    {
        param->map[param->x][param->y] = ' ';
        param->map[param->x][param->y + 1] = 'P';
    }
    else if (param->map[param->x][param->y + 1] == 'X' && \
    param->map[param->x][param->y + 2] != '#' && \
    param->map[param->x][param->y + 2] != 'X')
    {
        param->map[param->x][param->y] = ' ';
        param->map[param->x][param->y + 1] = 'P';
        param->map[param->x][param->y + 2] = 'X';
    }
}

int move_left(param_t *param)
{
    if (param->map[param->x][param->y - 1] != '#' && \
    param->map[param->x][param->y - 1] != 'X')
    {
        param->map[param->x][param->y] = ' ';
        param->map[param->x][param->y - 1] = 'P';
    }
    else if (param->map[param->x][param->y - 1] == 'X' && \
    param->map[param->x][param->y - 2] != '#' && \
    param->map[param->x][param->y - 2] != 'X')
    {
        param->map[param->x][param->y] = ' ';
        param->map[param->x][param->y - 1] = 'P';
        param->map[param->x][param->y - 2] = 'X';
    }
}

int move_down(param_t *param)
{
    if (param->map[param->x + 1][param->y] != '#' && \
    param->map[param->x + 1][param->y] != 'X')
    {
        param->map[param->x][param->y] = ' ';
        param->map[param->x + 1][param->y] = 'P';
    }
    else if (param->map[param->x + 1][param->y] == 'X' && \
    param->map[param->x + 2][param->y] != '#' && \
    param->map[param->x + 2][param->y] != 'X')
    {
        param->map[param->x][param->y] = ' ';
        param->map[param->x + 1][param->y] = 'P';
        param->map[param->x + 2][param->y] = 'X';
    }
}

int move_up(param_t *param)
{
    if (param->map[param->x - 1][param->y] != '#' && \
    param->map[param->x - 1][param->y] != 'X')
    {
        param->map[param->x][param->y] = ' ';
        param->map[param->x - 1][param->y] = 'P';
    }
    else if (param->map[param->x - 1][param->y] == 'X' && \
    param->map[param->x - 2][param->y] != '#' && \
    param->map[param->x - 2][param->y] != 'X')
    {
        param->map[param->x][param->y] = ' ';
        param->map[param->x - 1][param->y] = 'P';
        param->map[param->x - 2][param->y] = 'X';
    }
}

int check_move(param_t *param)
{
    int move;

    keypad(stdscr, TRUE);
    move = getch();
    if (move == KEY_DOWN)
        move_down(param);
    if (move == KEY_UP)
        move_up(param);
    if (move == KEY_LEFT)
        move_left(param);
    if (move == KEY_RIGHT)
        move_right(param);
    if (move == 'q') {
        endwin();
        exit(0);
    }
    if (move == ' ') {
        init_game(param);
    }
    get_pos_p(param);
}