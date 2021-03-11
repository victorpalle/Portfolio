/*
** EPITECH PROJECT, 2020
** time.c
** File description:
** time
*/

#include "runner.h"

void get_time(game_t *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
}