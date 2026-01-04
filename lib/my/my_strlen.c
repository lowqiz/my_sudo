/*
** EPITECH PROJECT, 2025
** my_strlen
** File description:
** Task03
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (*str != '\0'){
        str++;
        i++;
    }
    return i;
}
