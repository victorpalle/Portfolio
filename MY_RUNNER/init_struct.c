/*
** EPITECH PROJECT, 2020
** init_struct.c
** File description:
** init struct
*/

#include "runner.h"

game_t *fill_game(char *file)
{
    game_t *game = malloc(sizeof(game_t));

    game->clock = sfClock_create();
    game->pause = 0;
    game->jump = 0;
    game->win = 0;
    game->loose = 0;
    game->score = 0;
    game->font = sfFont_createFromFile("res/njnaruto.ttf");
    game->text = sfText_create();
    game->color = sfWhite;
    game->map = fill_map(file);
    game->nb_enemy = nb_enemy(game->map);
    game->music = sfMusic_createFromFile("res/RUNNER.ogg");
    my_putnbr(game->nb_enemy);
    return (game);

}

obj_t *create_object(char *file, float speed, sfVector2f pos, sfVector2f scale)
{
    obj_t *obj = malloc(sizeof(obj_t));

    obj->texture = sfTexture_createFromFile(file, NULL);
    obj->sprite = sfSprite_create();
    obj->speed = speed;
    obj->pos = pos;
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setScale(obj->sprite, scale);
    return (obj);
}

sfIntRect create_rect(int width, int height)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = width;
    rect.height = height;
    return (rect);
}

obj_t **create_objects(game_t *game)
{
    obj_t **objects = malloc(sizeof(obj_t) * (5 + game->nb_enemy));

    objects[0] = create_object("res/space.png",
    2, (sfVector2f){0, 0}, (sfVector2f){1, 1});
    objects[0]->weight = -5108;
    objects[2] = create_object("res/ground.png",
    15, (sfVector2f){0, -20}, (sfVector2f){1, 1});
    objects[2]->weight = -3816;
    objects[1] = create_object("res/hills.png",
    4, (sfVector2f){0, 0}, (sfVector2f){1, 1});
    objects[1]->weight = -3816;
    objects[3] = create_object("res/boy_run.png",
    0, (sfVector2f){50, 420}, (sfVector2f){0.7, 0.7});
    objects[3]->rect = create_rect(162, 244);
    objects[4] = create_object("res/ninja_jump.png",
    0, (sfVector2f){50, 350}, (sfVector2f){1.3, 1.3});
    objects[4]->rect = create_rect(100, 190);
    objects[4]->rect.left = 330;
    objects = create_enemy(objects, game);
    return (objects);
}
