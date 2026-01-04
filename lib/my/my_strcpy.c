/*
** EPITECH PROJECT, 2025
** my_strcpy.c
** File description:
** Task01
*/

#include "../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!dest || !src)
        return 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
