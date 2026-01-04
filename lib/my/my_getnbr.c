/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** 5th task
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int nbint = 0;
    int i = 0;
    unsigned char isneg = 0;

    for (; str[i] && (str[i] < '0' || str[i] > '9'); i++);
    if (i > 0 && str[i - 1] != '\0' && str[i - 1] == '-')
        isneg = 1;
    for (; str[i] && str[i] >= '0' && str[i] <= '9'; i++){
        nbint = nbint * 10 + (str[i] - 48);
    }
    return (isneg) ? -nbint : nbint;
}
