/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** Task02
*/

#include "../../include/my.h"

int ssstrlen(char const *str)
{
    int i = 0;

    while (*str != '\0'){
        str++;
        i++;
    }
    return i;
}

char *my_strcat(char *dest, char const *src)
{
    int a = ssstrlen(dest);

    for (int i = 0; src[i] != '\0'; i++) {
        dest[a] = src[i];
        a++;
    }
    return dest;
}
