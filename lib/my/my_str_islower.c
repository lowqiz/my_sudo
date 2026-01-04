/*
** EPITECH PROJECT, 2025
** lib
** File description:
** Task01
*/

#include "../../include/my.h"

int my_str_islower(char const *str)
{
    int a = 0;
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (97 <= str[i] && str[i] <= 122) {
            a++;
        }
    }
    if (a == i) {
        return 1;
    }
    return 0;
}
