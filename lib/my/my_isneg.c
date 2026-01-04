/*
** EPITECH PROJECT, 2025
** my_isneg.c
** File description:
** Task04
*/

#include <unistd.h>
#include "../../include/my.h"

int my_isneg(int nb)
{
    if (nb < 0){
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return (0);
}
