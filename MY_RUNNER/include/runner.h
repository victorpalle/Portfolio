/*
** EPITECH PROJECT, 2020
** hunter.h
** File description:
** hunter
*/

#ifndef RUNNER_H_
#define RUNNER_H_

#include <stddef.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Sensor.h>
#include <SFML/Window/Mouse.h>
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
#include <SFML/System/Vector3.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

enum {I, POS, OBJ, RESET};

typedef struct object
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    int speed;
    int weight;
} obj_t;

typedef struct game
{
    sfClock *clock;
    sfTime time;
    sfMusic *music;
    float seconds;
    int pause;
    int jump;
    int win;
    int loose;
    int score;
    sfText *text;
    sfFont *font;
    sfColor color;
    char *map;
    int nb_enemy;
} game_t;

sfRenderWindow * create_window(int x, int y, int bpp, char *title);
void analyse_event(sfRenderWindow *window, game_t *game);
obj_t *create_object(char *file, float speed, sfVector2f pos, sfVector2f scale);
void destroy_object(obj_t **obj, game_t *game);
void move_obj(obj_t **obj, game_t *game);
void get_time(game_t *game);
void destroy_game(game_t *g);
void run_game(sfRenderWindow *window, game_t *game, obj_t **obj);
void print_obj(sfRenderWindow *window, obj_t **obj, game_t *game);
obj_t **create_objects(game_t *game);
game_t *fill_game(char *file);
void move_bird(obj_t **obj, game_t *game);
void check_win(obj_t **obj, game_t *game, sfRenderWindow *window);
void print_score(sfRenderWindow *window, game_t *game);
void print_finalscore(sfRenderWindow *window, game_t *game);
void analyse_event_menu(sfRenderWindow *window, game_t *game, obj_t **obj);
void game_menu(sfRenderWindow *window, game_t *game, obj_t **obj);
void print_colors_text(sfRenderWindow *window, game_t *game);
void print_menu_sprite(sfRenderWindow *window, game_t *game);
void print_pause(sfRenderWindow *window, game_t *game, obj_t **obj);
char *fill_map(char *file);
int nb_enemy(char *map);
obj_t *create_object(char *file, float speed, sfVector2f pos, sfVector2f scale);
obj_t **create_enemy(obj_t **objects, game_t *game);
void free_obj(obj_t **obj, game_t *game);
void colision(obj_t **obj, game_t *game, sfRenderWindow *window);
void print_finaltext(sfRenderWindow *window, game_t *game);
char *itostr(int nb);
void update_score(obj_t **obj, game_t *game);
void play_music(sfRenderWindow *window, game_t *game);

#endif
