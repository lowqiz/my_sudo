/*
** EPITECH PROJECT, 2025
** count_islands
** File description:
** mini_projet_2
*/

#include "../include/my.h"

int if_in_or_denied2(password_t *psswd, arg_t *recup_argv)
{
    if (verif_psswd(psswd) == 1) {
        if (my_exec(recup_argv) == 84)
            return 84;
        return 1;
    } else {
        if (recup_argv->cpt_error_pwd <= 1)
            printf("Sorry, try again.\n");
        else
            printf("my_sudo: 3 incorrect password attempts\n");
        for (; recup_argv->cpt_error_pwd < 2;) {
            recup_argv->cpt_error_pwd += 1;
            check_password(recup_argv);
        }
        return 84;
    }
    return 0;
}

int if_in_or_denied(password_t *psswd, char **user_group, arg_t *recup_argv)
{
    for (int i = 0; user_group[i] != NULL; i++) {
        if (strcmp(user_group[i], psswd->user) == 0)
            return if_in_or_denied2(psswd, recup_argv);
    }
    printf("%s is not in the sudoers file.\n", psswd->user);
    return 84;
}

int if_user_in_group(password_t *psswd, char **group_sudoers, arg_t *recup_argv)
{
    char **user_group = NULL;

    if (group_sudoers[3] != NULL) {
        user_group = my_str_to_word_array(group_sudoers[3], ",\n\0");
        return if_in_or_denied(psswd, user_group, recup_argv);
    }
    return 0;
}

int find_if_in_group(password_t *psswd, open_file_t *open, arg_t *recup_argv)
{
    char **group_sudoers = NULL;
    char *str_line = NULL;
    size_t size_file = 0;
    FILE *fd = fopen("/etc/group", "r");

    if (fd == NULL) {
        return 84;
    }
    while (getline(&str_line, &size_file, fd) != -1) {
        group_sudoers = my_str_to_word_array(str_line, ":\n");
        if (strcmp(group_sudoers[0], psswd->percentgroup_sudoers[0]) == 0) {
            return if_user_in_group(psswd, group_sudoers, recup_argv);
        }
    }
    return 0;
}
