/*
** EPITECH PROJECT, 2025
** my_swap
** File description:
** Task01
*/

#include <unistd.h>
#include "../../include/my.h"

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
