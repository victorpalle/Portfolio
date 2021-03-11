/*
** EPITECH PROJECT, 2020
** first_win.c
** File description:
** first window
*/

#include "hunter.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left = rect->left + 110;
    if (rect->left == max_value)
        rect->left = 0;
}

void move_duck(sfSprite *sprite)
{
    sfVector2f offset = {50, 0};
    sfVector2f position = {0, 0};
    sfVector2f location;

    sfSprite_move(sprite, offset);
    location = sfSprite_getPosition(sprite);
    if (location.x == 800) {
        srand(time(NULL));
        position.y = rand()%500;
        sfSprite_setPosition(sprite, position);
    }
}

void print_background(sfRenderWindow *window)
{
    sfTexture *text = sfTexture_createFromFile("re/sky.png", NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, text, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

int run_window(sfRenderWindow *window, sfSprite *sprite, sfEvent event, sfIntRect rect)
{
    sfClock *clock;
    sfTime time;
    float seconds;
    sfMusic *music = sfMusic_createFromFile("re/music.ogg");

    clock = sfClock_create();
    background_music(music);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_setMouseCursorVisible(window, sfFalse);
        mouse_target(window);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        sfRenderWindow_display(window);
        analyse_events(window, event, sprite);
        if (seconds > 0.09) {
            move_duck(sprite);
            sfRenderWindow_clear(window, sfBlack);
            move_rect(&rect, 110, 330);
            sfRenderWindow_clear(window, sfBlack);
            sfSprite_setTextureRect(sprite, rect);
            sfClock_restart(clock);
        }
        print_background(window);
    }
    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
    sfMusic_destroy(music);
    return (0);
}
