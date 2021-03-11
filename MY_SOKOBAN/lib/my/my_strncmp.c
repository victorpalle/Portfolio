/*
** EPITECH PROJECT, 2020
** my_strncmp.c
** File description:
** task04
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int vrai = 0;
    int i = 0;

    while ((s1[i] != '\0' && i < n) || (s2[i] != '\0' && i < n)) {
        if (s1[i] != s2[i]) {
            vrai = 1;
        }
        i++;
    }
    return (vrai);
}

