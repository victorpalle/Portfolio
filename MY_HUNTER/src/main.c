/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "hunter.h"

int display(void)
{
    my_putstr("GAME RULES :\n");
    my_putstr("The goal of this game is to shoot the ducks that will\n");
    my_putstr("appear on the screen.\n");
    my_putstr("Left click on the screen with your mouse to shoot.\n");
    my_putstr("\n");
    my_putstr("Click on the upper right corner to exit.\n\n");
}

sfRenderWindow * create_window(int x, int y, int bpp, char *title)
{
    sfVideoMode mode = {x, y, bpp};

    return (sfRenderWindow_create(mode, title, sfResize | sfClose, NULL));
}

int declare(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {800, 600, 32};
    sfTexture *text = sfTexture_createFromFile("re/my_hunter_sheet.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfEvent event;
    sfIntRect rect = { .top = 0, .left = 0, .width = 110, .height = 110};

    sfSprite_setTexture(sprite, text, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    window = create_window(800, 600, 32, "My awesome window");
    sfRenderWindow_setFramerateLimit(window, 30);
    run_window(window, sprite, event, rect);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        display();
    else
        declare();
}
