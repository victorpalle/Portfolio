/*
** EPITECH PROJECT, 2020
** mouse.c
** File description:
** mouse
*/

#include "hunter.h"

void mouse_target(sfRenderWindow *window)
{
    sfTexture *text = sfTexture_createFromFile("re/coeurvic.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2i mouse = {0, 0};
    sfVector2f pos = {0, 0};

    sfSprite_setTexture(sprite, text, sfTrue);
    mouse = sfMouse_getPositionRenderWindow(window);
    pos.x = mouse.x - 55;
    pos.y = mouse.y - 55;
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void background_music(sfMusic *music)
{
    sfMusic_setVolume(music, 20);
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
}

int *kill_function(sfVector2i mouse, sfRenderWindow *window, sfSprite *sprite)
{
    sfVector2f position = sfSprite_getPosition(sprite);
    sfVector2f pos = {0, 0};
    int i = position.x, j = position.y;

    while (i < position.x + 110) {
        j = position.y;
        while (j < position.y + 110) {
            if (mouse.x == i && mouse.y == j) {
                pos.y = rand()%500;
                sfSprite_setPosition(sprite, pos);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int analyse_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite)
{
    sfVector2i mouse = {0, 0};

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            mouse = sfMouse_getPositionRenderWindow(window);
            kill_function(mouse, window, sprite);
        }
    }
    return (0);
}
