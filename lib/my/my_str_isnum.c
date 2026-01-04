/*
** EPITECH PROJECT, 2025
** lib
** File description:
** Task01
*/

#include "../../include/my.h"

int my_str_isnum(char const *str)
{
    int i = 0;
    int a = 0;

    for (; str[i] != '\0'; i++) {
        if (48 <= str[i] && str[i] <= 57)
            a++;
    }
    if (i == a)
        return 0;
    return 1;
}
