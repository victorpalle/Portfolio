/*
** EPITECH PROJECT, 2020
** event.c
** File description:
** analyse event
*/

#include "runner.h"

void print_pause(sfRenderWindow *window, game_t *game, obj_t **obj)
{
    if (game->pause == 1) {
        game->text = sfText_create();
        sfText_setFont(game->text, game->font);
        sfText_setString(game->text, "Pause");
        sfText_setPosition(game->text, (sfVector2f){290, 200});
        sfText_setCharacterSize(game->text, 60);
        sfText_setColor(game->text, game->color);
        sfRenderWindow_drawText(window, game->text, NULL);
    }
}

void pause_game(sfRenderWindow *window, game_t *game)
{
    if (game->pause == 1)
        game->pause = 0;
    else {
        game->pause = 1;
    }
}

void hit(sfVector2i mouse, sfRenderWindow *window, game_t *game, obj_t **obj)
{
    int i = 200;
    int y = 200;

    if ((mouse.x >= 90 && mouse.x <= 220)
    && (mouse.y >= 400 && mouse.y <= y + 500)) {
        game->color = sfGreen;
    }
    if ((mouse.x >= 600 && mouse.x <= 750) &&
    (mouse.y >= 400 && mouse.y <= y + 500))
        game->color = sfRed;
}

void analyse_event_menu(sfRenderWindow *window, game_t *game, obj_t **obj)
{
    sfEvent event;
    sfVector2i mouse = {0, 0};

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeySpace)
                run_game(window, game, obj);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            mouse = sfMouse_getPositionRenderWindow(window);
            hit(mouse, window, game, obj);
        }
    }
}

void analyse_event(sfRenderWindow *window, game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeyEscape)
                sfRenderWindow_close(window);
            if (event.key.code == sfKeyP)
                pause_game(window, game);
            if (event.key.code == sfKeySpace) {
                game->jump = 1;
            }
        }

    }
}
