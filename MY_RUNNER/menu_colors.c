/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-1-myrunner-victor.palle
** File description:
** menu_colors
*/

#include "runner.h"

void print_menu_sprite(sfRenderWindow *window, game_t *game)
{
    sfTexture *texture = sfTexture_createFromFile("res/menu.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setPosition(sprite, (sfVector2f){220, 80});
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void print_green_text(sfRenderWindow *window, game_t *game)
{
    game->text = sfText_create();
    sfText_setFont(game->text, game->font);
    sfText_setString(game->text, "Green");
    sfText_setPosition(game->text, (sfVector2f){70, 400});
    sfText_setCharacterSize(game->text, 50);
    sfText_setColor(game->text, sfGreen);
    sfRenderWindow_drawText(window, game->text, NULL);
}

void print_red_text(sfRenderWindow *window, game_t *game)
{
    game->text = sfText_create();
    sfText_setFont(game->text, game->font);
    sfText_setString(game->text, "Red");
    sfText_setPosition(game->text, (sfVector2f){630, 400});
    sfText_setCharacterSize(game->text, 50);
    sfText_setColor(game->text, sfRed);
    sfRenderWindow_drawText(window, game->text, NULL);
}

void print_colors_text(sfRenderWindow *window, game_t *game)
{
    print_red_text(window, game);
    print_green_text(window, game);
}