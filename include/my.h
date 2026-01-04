/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** Task02
*/

#ifndef MY_H
    #define MY_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <string.h>
    #include <crypt.h>
typedef struct password_s
{
    unsigned int id_user;
    char *mdp_hash;
    char *mdp;
    int int_of_id;
    char *user;
    char *str_line;
    char **name_sudoers;
    char **percentgroup_sudoers;

} password_t;

typedef struct arg_s
{
    int nb_arg;
    char **argv_str;
    int cpt_error_pwd;

} arg_t;

typedef struct open_file_s
{
    size_t size_file;
    FILE *fd;

} open_file_t;

int my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_putnbr_base(unsigned long long nb, char const *base,
    int precision, int specifier);
char **my_str_to_word_array(char const *str, char *str_separateur);
int my_getnbr(char const *str);
char *my_revstr(char *str);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
int my_strstr(char *str, char const *to_find);
void my_swap(int *a, int *b);
int mini_printf(const char *format, ...);
int my_show_word_array(char *const *tab);
void free_array(char **map);
int if_in_or_denied(password_t *psswd, char **user_group, arg_t *recup_argv);
int if_user_in_group
(password_t *psswd, char **group_sudoers, arg_t *recup_argv);
int find_if_in_group(password_t *psswd, open_file_t *open, arg_t *recup_argv);
int verif_psswd(password_t *psswd);
int my_exec(arg_t *recup_argv);
int check_password(arg_t *recup_argv);
void user_without_backslash_n(password_t *psswd);
int verif_psswd(password_t *psswd);
int handle_flags(arg_t *recup_argv);
#endif
