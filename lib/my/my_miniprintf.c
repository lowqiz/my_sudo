/*
** EPITECH PROJECT, 2025
** my_miniprintf
** File description:
** miniprintf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

static int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}

static int my_put_nbr(int nb, int cpt)
{
    if (nb < 0) {
        my_putchar('-');
        cpt++;
        return (-nb);
    }
    if (nb >= 10)
        my_put_nbr(nb / 10, cpt);
    my_putchar(nb % 10 + '0');
    cpt++;
    return cpt;
}

static int my_putstr(char const *str)
{
    int cpt = 0;

    while (*str != '\0'){
        my_putchar(*str);
        cpt++;
        str++;
    }
    return cpt;
}

static int my_strlen_my(char const *str)
{
    int i = 0;

    while (*str != '\0'){
        str++;
        i++;
    }
    return i;
}

int diff(int i, const char *format, va_list list, int *cpt)
{
    if (format[i] == 's') {
        *cpt += my_putstr(va_arg(list, char*));
        return i;
    }
    if (format[i] == 'c') {
        *cpt += my_putchar(va_arg(list, int));
        return i;
    }
    if ((format[i] == 'd' || format[i] == 'i')) {
        *cpt += my_put_nbr(va_arg(list, int), 0);
        return i;
    }
    if (format[i] == '%') {
        my_putchar('%');
        cpt++;
    }
    return i;
}

int error(const char *format, int i)
{
    if (format[i] == '%' && format[i + 1] == '\0')
        return -1;
    if (format[i] == '%' && (format[i + 1] != 's' && format[i + 1] != 'c'
            && format[i + 1] != 'd' && format[i + 1] != 'i'
            && format[i + 1] != '%'))
        return -1;
    return 0;
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int i = 0;
    int cpt = 0;

    va_start(list, format);
    for (; i < my_strlen_my(format); i++) {
        if (error(format, i) == -1)
            return -1;
        if (format[i] == '%') {
            i++;
            i = diff(i, format, list, &cpt);
        } else
            cpt += my_putchar(format[i]);
    }
    va_end(list);
    return cpt;
}
