/*
** EPITECH PROJECT, 2020
** SEMESTRE 1
** File description:
** my_music
*/

#ifndef MY_MUSIC_H_
#define MY_MUSIC_H_

#include <SFML/Window/Export.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void music(sfMusic *theme);
void sound(sfMusic *theme);

#endif /* !MY_MUSIC_H_ */
