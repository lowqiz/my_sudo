/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** Task04
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "../../include/my.h"

static int separateur(char c, char *str_separateur)
{
    for (int i = 0; str_separateur[i] != '\0'; i++) {
        if (str_separateur[i] == c)
            return -1;
    }
    return 0;
}

static int comptage_mot2
(char const *str, int *i, int ctgmots, char *str_separateur)
{
    while (separateur(str[*i], str_separateur) == -1 && str[*i] != '\0')
        *i = *i + 1;
    if (str[*i] == '\0')
        return ctgmots + 1;
    return ctgmots + 1;
}

static int comptage_mot(char const *str, char *str_separateur)
{
    int ctgmots = 0;

    if (separateur(str[0], str_separateur) == 0)
        ctgmots++;
    if (separateur(str[strlen(str) - 1], str_separateur) == -1)
        ctgmots--;
    if (separateur(str[strlen(str) - 1], str_separateur) == -1
        && separateur(str[0], str_separateur) == -1)
        ctgmots--;
    for (int i = 0; str[i] != '\0'; i++){
        if (separateur(str[i], str_separateur) == -1){
            ctgmots = comptage_mot2(str, &i, ctgmots, str_separateur);
        }
    }
    return ctgmots;
}

static int comptage_lettres(char const *str, int i, char *str_separateur)
{
    int compteur = 0;

    for (; str[i] != '\0' && separateur(str[i], str_separateur) == 0; i++) {
        compteur++;
    }
    return compteur;
}

char **arraynul(char const *str, char **array, int nbmots, int i)
{
    if (str[i] == '\0') {
        array[nbmots] = NULL;
        return array;
    }
    return array;
}

char **arraynul2(char **array, int z)
{
    if (array[z] == NULL){
        return NULL;
    }
    return array;
}

static int remplir_tableau
(char const *str, char **array, int tab[2], char *str_separateur)
{
    int q = 0;
    int nblettres = comptage_lettres(str, tab[0], str_separateur);

    for (int k = 0; (k < nblettres) && (str[tab[0]] != '\0'); tab[0]++) {
        array[tab[1]][q] = str[tab[0]];
        q++;
        k++;
    }
    array[tab[1]][nblettres] = '\0';
    return tab[0];
}

char **my_str_to_word_array(char const *str, char *str_separateur)
{
    int nbmots;
    char **array;
    int nblettres = 0;
    int tab[2] = {0, 0};

    if (str == NULL || str_separateur == NULL)
        return NULL;
    nbmots = comptage_mot(str, str_separateur);
    array = malloc(sizeof(char*) * (nbmots + 1));
    for (; str[tab[0]] != '\0'; tab[0]++){
        for (; separateur(str[tab[0]], str_separateur) == -1; tab[0]++);
        nblettres = comptage_lettres(str, tab[0], str_separateur);
        array[tab[1]] = malloc(sizeof(char) * (nblettres + 1));
        tab[0] = remplir_tableau(str, array, tab, str_separateur);
        tab[1]++;
    }
    array[nbmots] = NULL;
    return array;
}
