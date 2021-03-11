/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-1-myrunner-victor.palle
** File description:
** hit
*/

#include "runner.h"

void run_hit(sfVector2f ninja, sfVector2f enemy, game_t *game)
{
    if ((ninja.x + 40) > enemy.x && ninja.x < (enemy.x + 80)) {
        game->loose = 1;
        return;
    }

}

void colision(obj_t **obj, game_t *game, sfRenderWindow *window)
{
    sfVector2f ninja = sfSprite_getPosition(obj[3]->sprite);
    sfVector2f enemy;
    int i = 5;

    while (i <= 4 + game->nb_enemy) {
        enemy = sfSprite_getPosition(obj[i]->sprite);
        if (game->jump == 0)
            run_hit(ninja, enemy, game);
        i++;
    }
}