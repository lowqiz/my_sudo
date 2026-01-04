/*
** EPITECH PROJECT, 2025
** count_islands
** File description:
** mini_projet_2
*/

#include "../include/my.h"

static int flag(char c, int i)
{
    switch (c) {
        case 'h':
            printf("usage: ./my_sudo -h\n"
                "usage: ./my_sudo [-ug] [command [args ...]]\n");
            i = 1;
            return i;
        case 'u':
            i = 1;
            return i;
        case 'g':
            i = 1;
            return i;
    }
    return i;
}

int handle_flags(arg_t *recup_argv)
{
    int i = 0;

    if (recup_argv->argv_str[1][1] == 'h' ||
        recup_argv->argv_str[1][1] == 'g' ||
        recup_argv->argv_str[1][1] == 'u') {
        for (char c = getopt(recup_argv->nb_arg, recup_argv->argv_str, "hug");
            c != -1;
            c = getopt(recup_argv->nb_arg, recup_argv->argv_str, "hug")) {
            i = flag(c, i);
        }
    }
    return i;
}
