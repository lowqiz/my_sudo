/*
** EPITECH PROJECT, 2025
** my_strncat
** File description:
** Task03
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int a = my_strlen(dest);

    for (int i = 0; src[i] != src[nb]; i++) {
        dest[a] = src[i];
        a++;
    }
    return dest;
}
