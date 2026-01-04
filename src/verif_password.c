/*
** EPITECH PROJECT, 2025
** count_islands
** File description:
** mini_projet_2
*/

#include "../include/my.h"

void user_without_backslash_n(password_t *psswd)
{
    size_t len = strlen(psswd->mdp);

    psswd->mdp[len - 1] = '\0';
}

int verif_psswd(password_t *psswd)
{
    char *str_line = NULL;
    char *psswd_modif = NULL;
    char **line_for_psswd = NULL;
    size_t size_file = 0;
    FILE *fd = fopen("/etc/shadow", "r");

    user_without_backslash_n(psswd);
    if (!fd)
        return -1;
    while (getline(&str_line, &size_file, fd) != -1) {
        line_for_psswd = my_str_to_word_array(str_line, ":\n");
        if (strcmp(line_for_psswd[0], psswd->user) == 0) {
            psswd->mdp_hash = strdup(line_for_psswd[1]);
            break;
        }
    }
    psswd_modif = crypt(psswd->mdp, psswd->mdp_hash);
    if (strcmp(psswd_modif, psswd->mdp_hash) == 0)
        return 1;
    return 0;
}
