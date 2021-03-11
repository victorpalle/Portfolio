/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-1-myrunner-victor.palle
** File description:
** score
*/

#include "runner.h"

char *itostr(int nb)
{
    char base[11] = "0123456789";
    char *score = malloc(sizeof(char)*20);
    int i = 0;
    int buff = 0;

    while (nb > 9) {
        buff = nb % 10;
        score[i] = base[buff];
        i++;
        nb = nb / 10;
    }
    buff = nb % 10;
    score[i] = base[buff];
    score[i + 1] = '\0';
    my_revstr(score);
    return (score);
}

void print_finaltext(sfRenderWindow *window, game_t *game)
{
    game->text = sfText_create();
    sfText_setFont(game->text, game->font);
    sfText_setString(game->text, "Press Echap to quit");
    sfText_setPosition(game->text, (sfVector2f){175, 500});
    sfText_setCharacterSize(game->text, 40);
    sfText_setColor(game->text, game->color);
    sfRenderWindow_drawText(window, game->text, NULL);
}

void print_finalscore(sfRenderWindow *window, game_t *game)
{
    char *score = itostr(game->win);
    char text[60] = "    You win !\n\n\nYour Score :\n\n        ";

    my_strcat(text, score);
    game->text = sfText_create();
    sfText_setFont(game->text, game->font);
    sfText_setString(game->text, text);
    sfText_setPosition(game->text, (sfVector2f){270, 40});
    sfText_setCharacterSize(game->text, 40);
    sfText_setColor(game->text, game->color);
    sfRenderWindow_drawText(window, game->text, NULL);
    print_finaltext(window, game);
    free(score);
}

void update_score(obj_t **obj, game_t *game)
{
    int i = 5;
    int cpt = 0;

    while (i <= 4 + game->nb_enemy) {
        if (obj[i]->pos.x < -50)
            cpt++;
        i++;
    }
    game->win = cpt;
}

void print_score(sfRenderWindow *window, game_t *game)
{
    char *score = itostr(game->win);
    char text[16] = "Score  :  ";

    my_strcat(text, itostr(game->win));
    sfText_setFont(game->text, game->font);
    sfText_setString(game->text, text);
    sfText_setPosition(game->text, (sfVector2f){290, 40});
    sfText_setCharacterSize(game->text, 40);
    sfText_setColor(game->text, game->color);
    sfRenderWindow_drawText(window, game->text, NULL);
    free(score);
}