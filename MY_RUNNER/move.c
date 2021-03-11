/*
** EPITECH PROJECT, 2020
** move.c
** File description:
** move
*/

#include "runner.h"

void move_rect_bird(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + offset;
    if (rect->left == max_value)
        rect->left = 0;
}

void jump_bird(obj_t **obj, game_t *game)
{
    if (game->jump >= 120) {
        obj[4]->pos.y += 10;
        game->jump += 10;
        sfClock_restart(game->clock);
    } else {
        obj[4]->pos.y -= 10;
        game->jump += 10;
        sfClock_restart(game->clock);
    }
}

void move_bird(obj_t **obj, game_t *game)
{
    if (game->pause == 1)
        return;

    get_time(game);
    if (game->jump == 0) {
        if (game->seconds > 0.2) {
            obj[3]->rect.top = 244;
            move_rect_bird(&obj[3]->rect, 170, 510);
            sfClock_restart(game->clock);
        }
    }
    if (game->jump != 0) {
        if (game->seconds > 0.01) {
            jump_bird(obj, game);
        }
    }
    if (game->jump == 241) {
        game->jump = 0;
        sfClock_restart(game->clock);
    }
}

void move_obj(obj_t **obj, game_t *game)
{
    int i = 0;
    int j = 5;

    if (game->pause == 1)
        return;
    while (i < 3) {
        if (obj[i]->pos.x <= obj[i]->weight + 800)
            obj[i]->pos.x = 0;
        obj[i]->pos.x -= obj[i]->speed;
        sfSprite_setPosition(obj[i]->sprite, obj[i]->pos);
        i++;
    }
    while (j <= 4 + game->nb_enemy) {
        obj[j]->pos.x -= obj[j]->speed;
        sfSprite_setPosition(obj[j]->sprite, obj[j]->pos);
        j++;
    }
}