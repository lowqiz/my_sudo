/*
** EPITECH PROJECT, 2025
** count_islands
** File description:
** mini_projet_2
*/

#include "../include/my.h"

int my_exec(arg_t *recup_argv)
{
    char *arg[] = {recup_argv->argv_str[1], recup_argv->argv_str[2], NULL};

    if (execvp(arg[0], arg) == -1) {
        printf("sudo: %s: command not found\n", recup_argv->argv_str[1]);
        return 84;
    }
    return 0;
}

static int initialize
(password_t *psswd, open_file_t *open, arg_t *recup_argv)
{
    psswd->user = NULL;
    psswd->mdp = NULL;
    psswd->int_of_id = 0;
    psswd->id_user = getuid();
    open->fd = fopen("/etc/passwd", "r");
    open->size_file = 0;
    if (psswd->id_user == 0)
        return my_exec(recup_argv);
    return 0;
}

static int recup_group(password_t *psswd)
{
    char *str_line = NULL;
    size_t size_file = 0;
    FILE *fd = fopen("/etc/sudoers", "r");

    psswd->name_sudoers = NULL;
    psswd->percentgroup_sudoers = NULL;
    if (fd == NULL) {
        return -1;
    }
    while (getline(&str_line, &size_file, fd) != -1) {
        if (str_line[0] == '%' &&
            my_strstr(str_line, "ALL=(ALL") == 0) {
            psswd->percentgroup_sudoers =
                my_str_to_word_array(str_line, "% \t\n");
        }
    }
    return 0;
}

static int recup_user(password_t *psswd, open_file_t *open, arg_t *recup_argv)
{
    if (psswd->name_sudoers == NULL)
        return 84;
    if (strcmp(psswd->user, psswd->name_sudoers[0]) == 0)
        return if_in_or_denied(psswd, psswd->name_sudoers, recup_argv);
    else
        return find_if_in_group(psswd, open, recup_argv);
}

int cat_sudoers(password_t *psswd, open_file_t *open, arg_t *recup_argv)
{
    char *str_line = NULL;
    size_t size_file = 0;
    FILE *fd = fopen("/etc/sudoers", "r");

    recup_group(psswd);
    while (getline(&str_line, &size_file, fd) != -1) {
        if (str_line[0] != '#' && str_line[0] != '%' &&
            my_strstr(str_line, "ALL=(ALL") == 0) {
            psswd->name_sudoers = my_str_to_word_array(str_line, " \t\n");
            return recup_user(psswd, open, recup_argv);
        }
    }
    free(str_line);
    fclose(fd);
    return 0;
}

static char *get_user(password_t *psswd)
{
    char **recup_id = NULL;

    recup_id = my_str_to_word_array(psswd->str_line, ":\n");
    if (recup_id == NULL)
        return NULL;
    psswd->int_of_id = atoi(recup_id[2]);
    if (psswd->int_of_id == psswd->id_user)
        psswd->user = strdup(recup_id[0]);
    free(recup_id);
    return psswd->user;
}

static int print_sudo(password_t *psswd, open_file_t *open)
{
    printf("[my_sudo] password for %s : ", psswd->user);
    fflush(stdout);
    if (getline(&psswd->mdp, &open->size_file, stdin) == -1)
        return 84;
    return 0;
}

int check_password(arg_t *recup_argv)
{
    password_t psswd;
    open_file_t open;

    initialize(&psswd, &open, recup_argv);
    if (open.fd == NULL)
        return 84;
    while (getline(&psswd.str_line, &open.size_file, open.fd) != -1) {
        psswd.user = get_user(&psswd);
    }
    fclose(open.fd);
    if (psswd.user == NULL)
        return 84;
    if (print_sudo(&psswd, &open) == 84)
        return 84;
    if (cat_sudoers(&psswd, &open, recup_argv) == 84)
        return 84;
    return 0;
}

int main(int argc, char **argv)
{
    arg_t recup_argv;

    recup_argv.argv_str = argv;
    recup_argv.nb_arg = argc;
    recup_argv.cpt_error_pwd = 0;
    if (argc == 1) {
        printf("usage: ./my_sudo -h\n"
            "usage: ./my_sudo [-ug] [command [args ...]]\n");
        return 84;
    }
    if (handle_flags(&recup_argv) == 1)
        return 0;
    if (check_password(&recup_argv) == 84)
        return 84;
}
