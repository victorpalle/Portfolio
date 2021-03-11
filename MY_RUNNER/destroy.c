/*
** EPITECH PROJECT, 2020
** destroy.c
** File description:
** destroy
*/

#include "runner.h"

void free_obj(obj_t **obj, game_t *game)
{
    int i = 0;

    while (i <= 4 + game->nb_enemy) {
        free(obj[i]);
        i++;
    }
    free(game->map);
}

void destroy_object(obj_t **obj, game_t *game)
{
    int i = 0;

    while (i < 4 + game->nb_enemy) {
        sfTexture_destroy(obj[i]->texture);
        sfSprite_destroy(obj[i]->sprite);
        i++;
    }
    sfText_destroy(game->text);
    sfClock_destroy(game->clock);
    sfFont_destroy(game->font);
    sfMusic_destroy(game->music);
}