/*
** EPITECH PROJECT, 2021
** sokoban_test
** File description:
** sokoban
*/

#include "sokoban.h"

void check_size_term(param_t *param)
{
    while (COLS < len_of_line(param) || LINES < tab_len(param)) {
        clear();
        mvprintw(LINES / 2, COLS / 2 - 27, "Careful terminal too small !\n");
        mvprintw(LINES / 2 + 1, COLS / 2 - 5, "Resize !\n");
        refresh();
    }
}

void print_screen(param_t *param)
{
    int cpt = 0;

    clear();
    while (param->map[cpt]) {
        mvprintw(LINES / 2 - tab_len(param) / 2 + cpt, \
        COLS / 2 - my_strlen(param->map[cpt]) / 2, param->map[cpt]);
        curs_set(0);
        cpt++;
    }
    refresh();
}

void init_game(param_t *param)
{
    coord_t **xy;

    param->map = malloc_arr(param->file);
    error_handling(param);
    xy = get_coord_o(xy, param);
    get_pos_p(param);
    initscr();
    while (1) {
        curs_set(0);
        print_screen(param);
        check_size_term(param);
        check_move(param);
        manage_dot(param, xy);
        check_loose(param);
        check_win(param, xy);
    }
    endwin();
    free(param->map);
    free(xy);
}

void sokoban(char *file)
{
    char *buffer;
    int i = 0;
    param_t *param;

    buffer = file_to_buffer(file);
    param->file = buffer;
    param->col = count_col(buffer);
    param->row = count_line(buffer);
    init_game(param);
    free(buffer);
}