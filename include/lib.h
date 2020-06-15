/*
** EPITECH PROJECT, 2020
** lib
** File description:
** .h
*/

#ifndef LIB_H
#define LIB_H
#include <stdio.h>

int my_getnbr(char const *str);
char *concate(char *dest, char *src);
int my_strlen(char const *str);
char *my_itoa(int nb);
char *my_revstr(char *str);
char *my_strdup(char const *str);
int my_strcmp(char *s1, char *s2);
char **my_str_to_word_array(char const *str, char delim);
int my_fprintf(FILE *stream, const char *str, ...);

#endif
