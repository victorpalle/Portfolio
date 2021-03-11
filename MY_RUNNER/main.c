/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "runner.h"

sfRenderWindow * create_window(int x, int y, int bpp, char *title)
{
    sfVideoMode mode = {x, y, bpp};

    return (sfRenderWindow_create(mode, title, sfResize | sfClose, NULL));
}

int display(void)
{
    my_putstr("USAGE :\n\n");
    my_putstr("./my_runner maps/map.txt\n\n");
    my_putstr("GAME RULES :\n\n");
    my_putstr("The goal of this game is to jump over enemies that will\n");
    my_putstr("appear on the screen.\n\n");
    my_putstr("Press Spacebar to jump\n");
    my_putstr("\n");
    my_putstr("Click on the upper right corner or press Echap to exit.\n");
}

int main(int ac, char **av)
{
    sfRenderWindow *window;
    game_t *game;
    obj_t **obj;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        display();
    else {
        game = fill_game(av[1]);
        obj = create_objects(game);
        window = create_window(800, 600, 32, "yes");
        sfRenderWindow_setFramerateLimit(window, 32);
        play_music(window, game);
        while (sfRenderWindow_isOpen(window)) {
            game_menu(window, game, obj);
        }
        destroy_object(obj, game);
        free_obj(obj, game);
        sfRenderWindow_destroy(window);
    }
    return (0);
}
