/*
** EPITECH PROJECT, 2025
** my_putstr.c
** File description:
** Task02
*/

#include <unistd.h>
#include "../../include/my.h"

int my_putstr(char const *str)
{
    while (*str != '\0'){
        my_putchar(*str);
        str++;
    }
    return 0;
}
