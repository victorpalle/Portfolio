/*
** EPITECH PROJECT, 2020
** SEMESTRE 1
** File description:
** parser
*/

#include "my_navy.h"

core_t *global;

void win(navy_t *s)
{
    if (s->error != 0)
        return;
    if (s->win == 14) {
        my_printf("\nI won\n\n");
        s->error = 0;
    } else {
        my_printf("\nEnemy won\n\n");
        s->error = 1;
    }
}

int is_validpid(char *av)
{
    int i = 0;
    int number = my_getnbr(av);

    if (number < 0)
        return (1);
    for (i = 0; av[i] != '\0'; i++)
        if (av[i] >= '0' && av[i] <= '9')
            return (0);
        else
            return (1);
}

int navy(int ac, char **av, navy_t *s)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        navy_help();
    if (ac < 2 || ac > 3)
        return (0);
    if (ac == 2) {
        fill_map_and_struct(s, ac, av);
        if (s->error != 0)
            return (0);
        player_one(s);
        win(s);
    } else if (ac == 3) {
        if (is_validpid(av[1]) == 1) {
            s->error = 84;
            return (84);
        }
        fill_map_and_struct(s, ac, av);
        if (s->error != 0)
            return (0);
        player_two(s, av[1]);
        win(s);
    }
}

int parser(int ac, char **av)
{
    navy_t s;
    int return_value;

    fill_global();
    fill_struct(&s);
    navy(ac, av, &s);
    return_value = s.error;
    free(global);
    return (return_value);
}
