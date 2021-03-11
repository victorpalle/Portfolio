/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-1-myrunner-victor.palle
** File description:
** enemy
*/

#include "runner.h"

int *fill_spec(void)
{
    int *spec = malloc(sizeof(int) * 4);

    spec[I] = 0;
    spec[POS] = 800;
    spec[OBJ] = 5;
    spec[RESET] = 0;
    return (spec);
}

obj_t **create_enemy(obj_t **objects, game_t *game)
{
    int *spec = fill_spec();

    while (game->map[spec[I]] != '\0') {
        spec[RESET] = 0;
        if (game->map[spec[I]] == '1') {
            objects[spec[OBJ]] = create_object("res/obstacle.png", 10,
            (sfVector2f){spec[POS], 420}, (sfVector2f){0.35, 0.35});
            spec[OBJ] += 1;
            spec[POS] += 90;
            spec[RESET] += 1;
        }
        if (spec[RESET] == 0)
            spec[POS] += 100;
        spec[I] += 1;
    }
    free(spec);
    return (objects);
}