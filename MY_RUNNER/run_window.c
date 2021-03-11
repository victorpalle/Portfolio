/*
** EPITECH PROJECT, 2020
** run_window.c
** File description:
** run window
*/

#include "runner.h"

void mouse_target(sfRenderWindow *window)
{
    sfTexture *text = sfTexture_createFromFile("res/shuriken.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2i mouse = {0, 0};
    sfVector2f pos = {0, 0};

    sfSprite_setTexture(sprite, text, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){0.2, 0.2});
    mouse = sfMouse_getPositionRenderWindow(window);
    pos.x = mouse.x - 55;
    pos.y = mouse.y - 55;
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void print_menu(sfRenderWindow *window, game_t *game)
{
    sfFont *font = sfFont_createFromFile("res/njnaruto.ttf");
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setString(text, "Press space bar to start or select your color");
    sfText_setPosition(text, (sfVector2f){30, 280});
    sfText_setCharacterSize(text, 30);
    sfText_setColor(text, game->color);
    sfRenderWindow_drawText(window, text, NULL);
    print_colors_text(window, game);
    print_menu_sprite(window, game);

}

void game_menu(sfRenderWindow *window, game_t *game, obj_t **obj)
{
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        sfRenderWindow_drawSprite(window, obj[0]->sprite, NULL);
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        print_menu(window, game);
        mouse_target(window);
        analyse_event_menu(window, game, obj);
    }
}

void play_music(sfRenderWindow *window, game_t *game)
{
    sfMusic_setVolume(game->music, 20);
    sfMusic_play(game->music);
    sfMusic_setLoop(game->music, sfTrue);
}

void run_game(sfRenderWindow *window, game_t *game, obj_t **obj)
{
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_display(window);
        analyse_event(window, game);
        update_score(obj, game);
        print_score(window, game);
        print_obj(window, obj, game);
        move_obj(obj, game);
        move_bird(obj, game);
        check_win(obj, game, window);
        print_score(window, game);
        mouse_target(window);
        colision(obj, game, window);
    }
}

