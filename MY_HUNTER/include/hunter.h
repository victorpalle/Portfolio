/*
** EPITECH PROJECT, 2020
** hunter.h
** File description:
** hunter
*/

#ifndef HUNTER_H_
#define HUNTER_H_

#include <stddef.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include "my.h"
#include <stdlib.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/System.h>
#include <SFML/Audio/Listener.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/SoundBufferRecorder.h>
#include <SFML/Audio/SoundRecorder.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/SoundStream.h>
#include <SFML/Config.h>

int analyse_events(sfRenderWindow *window, sfEvent event, sfSprite *sprite);

void create_dead_duck(sfVector2f position, sfRenderWindow *window);

void mouse_target(sfRenderWindow *window);

void background_music(sfMusic *music);

void add_text(sfRenderWindow *window);

int run_window(sfRenderWindow *window, sfSprite *sprite, sfEvent event, sfIntRect rect);

sfRenderWindow * create_window(int x, int y, int bpp, char *title);

typedef struct score_t
{
    int score;
} score;

#endif
