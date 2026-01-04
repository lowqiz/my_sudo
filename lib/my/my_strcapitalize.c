/*
** EPITECH PROJECT, 2025
** capitalize
** File description:
** Task
*/

#include "../../include/my.h"

static int minuscule(char c)
{
    if (!(97 <= c && c <= 122))
        return 0;
    return 1;
}

static int separateur(char c)
{
    if (!((48 <= c && c <= 57) ||
            (65 <= c && c <= 90) || (97 <= c && c <= 122)))
        return 0;
    return 1;
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (minuscule(str[i]) == 1 && (i == 0 || separateur(str[i - 1]) == 0)) {
            str[i] = str[i] - 32;
        }
    }
    return str;
}
