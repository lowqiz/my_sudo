/*
** EPITECH PROJECT, 2025
** my_strncpy.c
** File description:
** Task02
*/

#include "../../include/my.h"

int len(char const *str)
{
    int i = 0;

    while (*str != '\0'){
        str++;
        i++;
    }
    return i;
}

char strncpy2(char *dest, char const *src, int n, int i)
{
    if (n > len(src))
        dest[i] = '\0';
    if (!dest || !src)
        return 0;
    while (i != n) {
        dest[i] = src[i];
        i++;
    }
    return 0;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (n > len(src)) {
        n = len(src);
        if (!dest || !src)
            return 0;
        while (i != n) {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    } else {
        strncpy2(dest, src, n, i);
    }
    return dest;
}
