/*
** EPITECH PROJECT, 2025
** my_strstr.c
** File description:
** Task05
*/

#include <stddef.h>
#include "../../include/my.h"

int my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    if (str == NULL || to_find == NULL)
        return -1;
    if (my_strlen(to_find) == 0)
        return 0;
    if (my_strlen(to_find) > my_strlen(str))
        return -1;
    while (str[i] != '\0') {
        j = 0;
        while (to_find[j] != '\0' && str[i + j] == to_find[j])
            j++;
        if (to_find[j] == '\0')
            return 0;
        i++;
    }
    return -1;
}
