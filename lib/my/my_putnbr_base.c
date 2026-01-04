/*
** EPITECH PROJECT, 2025
** my_putnbr_base
** File description:
** convert and print an int into the given base
*/

#include "../../include/my.h"
#include <stdlib.h>

int my_putnbr_base(unsigned long long nb, char const *base,
    int precision, int specifier)
{
    unsigned long long temp = nb;
    int len = 1;
    int strlenbase = my_strlen(base);
    int recup = 0;

    (void)specifier;
    while (temp >= (unsigned long long) strlenbase) {
        temp /= (unsigned long long)strlenbase;
        len++;
    }
    for (int i = 0; i < precision - len; i++) {
        recup += my_putchar('0');
    }
    if (nb >= (unsigned long long) my_strlen(base))
        recup += my_putnbr_base(nb / my_strlen(base), base, 0, 0);
    recup += my_putchar(base[nb % my_strlen(base)]);
    return recup;
}
