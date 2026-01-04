/*
** EPITECH PROJECT, 2025
** my_strcat
** File description:
** Task03
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "../../include/my.h"

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        write(1, tab[i], my_strlen(tab[i]));
        my_putchar('\n');
    }
    return 0;
}
