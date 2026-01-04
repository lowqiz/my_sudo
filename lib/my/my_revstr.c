/*
** EPITECH PROJECT, 2025
** my_revstr
** File description:
** Task03
*/

#include <stdio.h>
#include "../../include/my.h"

static int my_compteur(char const *str)
{
    int i = 0;

    while (*str != '\0'){
        str++;
        i++;
    }
    return i;
}

char *my_revstr(char *str)
{
    int f = 0;
    char a;

    if (!str)
        return 0;
    f = my_compteur(str);
    for (int i = 0; i != my_compteur(str) / 2; i++){
        f--;
        a = str[f];
        str[f] = str[i];
        str[i] = a;
    }
    return str;
}
