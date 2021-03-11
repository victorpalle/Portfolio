/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-1-myrunner-victor.palle
** File description:
** win
*/

#include "runner.h"

void print_win(obj_t **obj, game_t *game, sfRenderWindow *window)
{
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, obj[0]->sprite, NULL);
        print_finalscore(window, game);
        analyse_event(window, game);
        sfRenderWindow_display(window);
    }

}

void print_text_loose(sfRenderWindow *window, game_t *game)
{
    char *score = itostr(game->win);
    char text[60] = "    You lost ...\n\n\nYour Score :\n\n        ";

    my_strcat(text, score);
    game->text = sfText_create();
    sfText_setFont(game->text, game->font);
    sfText_setString(game->text, text);
    sfText_setPosition(game->text, (sfVector2f){270, 40});
    sfText_setCharacterSize(game->text, 40);
    sfText_setColor(game->text, game->color);
    sfRenderWindow_drawText(window, game->text, NULL);
    free(score);
}

static void print_loose(obj_t **obj, game_t *game, sfRenderWindow *window)
{
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, obj[0]->sprite, NULL);
        print_finaltext(window, game);
        print_text_loose(window, game);
        analyse_event(window, game);
        sfRenderWindow_display(window);
    }
}

void check_win(obj_t **obj, game_t *game, sfRenderWindow *window)
{
    if (game->loose != 0) {
        print_loose(obj, game, window);
    }
    if (game->win >= game->nb_enemy && obj[4 + game->nb_enemy]->pos.x < -150) {
        print_win(obj, game, window);
    }
}