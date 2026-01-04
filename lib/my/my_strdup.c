/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** Task01
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (i = 0; src[i] != '\0'; i++){
        str[i] = src[i];
    }
    str[i] = '\0';
    return str;
}
