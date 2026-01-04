/*
** EPITECH PROJECT, 2025
** my_strcmp
** File description:
** Task06
*/

#include "../../include/my.h"

static int maxlen(char const *s1, char const *s2)
{
    if (my_strlen(s1) > my_strlen(s2))
        return my_strlen(s1);
    return my_strlen(s2);
}

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; i < maxlen(s1, s2); i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        if (s1[i] == '\0' || s2[i] == '\0')
            return 0;
    }
    return 0;
}
