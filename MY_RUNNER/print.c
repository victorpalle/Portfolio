/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-1-myrunner-victor.palle
** File description:
** print
*/

#include "runner.h"

void print_bird(sfRenderWindow *window, obj_t *obj)
{
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfRenderWindow_drawSprite(window, obj->sprite, NULL);
}

void print_enemys(sfRenderWindow *window, obj_t **obj, game_t *game)
{
    int j = 5;

    while (j <= 4 + game->nb_enemy) {
        sfSprite_setPosition(obj[j]->sprite, obj[j]->pos);
        sfRenderWindow_drawSprite(window, obj[j]->sprite, NULL);
        j++;
    }
}

void print_obj(sfRenderWindow *window, obj_t **obj, game_t *game)
{
    int i = 0;

    while (i < 3) {
        sfSprite_setPosition(obj[i]->sprite, obj[i]->pos);
        sfRenderWindow_drawSprite(window, obj[i]->sprite, NULL);
        i++;
    }
    print_enemys(window, obj, game);
    if (game->jump == 0)
        print_bird(window, obj[3]);
    if (game->jump != 0)
        print_bird(window, obj[4]);
    print_pause(window, game, obj);
}