/*
** EPITECH PROJECT, 2020
** SEMESTRE 1
** File description:
** my_navy
*/

#ifndef MY_NAVY_H_
#define MY_NAVY_H_

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_music.h"
#include "my_lib.h"

typedef struct navy_s {
    char **map;
    char **map_adv;
    char *buffer;
    int pid;
    int pid_adv;
    int win;
    int win_adv;
    int error;
} navy_t;

typedef struct core_s {
    int ppid;
    int start;
    int cpt;
    int cpt_l;
    int cpt_n;
    int cpt_sig2;
    int cpt_resp;
    int received;
    int response;
} core_t;

typedef struct coord_s {
    int ltr;
    int nbr;
} coord_t;

void fill_global(void);
void navy_help(void);
void fill_map_and_struct(navy_t *s, int ac, char **av);
int fill_map_with_boat(char *file, navy_t *s);
void add_boat(char **map, char *buffer);
char **fill_map(void);
void get_response(void);
void signal_handler_response(int sig, siginfo_t *info, void *secret);
void get_message(void);
void signal_handler(int sig, siginfo_t *info, void *secret);
void get_first_signal(void);
void first_signal_handler(int sig, siginfo_t *info, void *secret);
void player_one(navy_t *s);
void manage_player_one(navy_t *s);
void player_two(navy_t *s, char *pid);
void manage_player_two(navy_t *s);
coord_t *read_message_and_send(navy_t *s);
void send_message(navy_t *s, int letter, int number);
void modif_map(navy_t *s);
void modif_adv_map(navy_t *s, coord_t *coord);
void print_gameboard(navy_t *s);
void print_map(char **map);
int check_buffer(char *buffer);
void fill_struct(navy_t *s);
int parser(int ac, char **av);
void win(navy_t *s);
int isnum(char num);
int is_validchar(char *message);
int is_validnum(char *message);
int is_validmessage(char *message);
void print_first_message_player_two(void);
void print_first_message_player_one(void);
int navy(int ac, char **av, navy_t *s);
int check_positions(char *buffer);
int check_syntax(char *buffer);
int check_numbers(char *buffer);
int check_numbers_bis(char *buffer);
int check_letters(char *buffer);
int check_letters_bis(char *buffer);

#endif /* !MY_NAVY_H_ */
