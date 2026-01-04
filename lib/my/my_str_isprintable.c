/*
** EPITECH PROJECT, 2025
** my_str_isprintable
** File description:
** Task 16
*/

#include "../../include/my.h"

int my_str_isprintable(char const *str)
{
    if (str[0] == '\0')
        return 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(32 <= str[i] && str[i] <= 126))
            return 0;
    }
    return 1;
}
