/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** task04
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strdup(char const *src);

int is_delim_caracters(char x, char delim)
{
    if (x == delim)
        return 1;
    else
        return 0;
}

char *my_strdup_ext(char const *src, int size)
{
    char *dest;

    dest = malloc(sizeof(char) * size + 1);
    my_strncpy(dest, src, size);
    if (dest[size - 1] == '\n')
        size -= 1;
    dest[size] = '\0';
    return (dest);
}

int nbr_of_tab(char const *str, char delim)
{
    int tab = 0;
    int i = 0;

    while (str[i] != 0) {
        if (str[i] == delim)
            tab = tab + 1;
        i = i + 1;
    }
    return (tab + 1);
}

char **my_str_to_word_array(char const *str, char delim)
{
    char **returned = malloc(sizeof(char *) * (nbr_of_tab(str, delim) + 1));
    int nbr_char = 0;
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (!is_delim_caracters(str[i], delim)) {
            nbr_char = nbr_char + 1;
        } else if (nbr_char != 0) {
            returned[j] = my_strdup_ext(str + (i - nbr_char), nbr_char);
            j = j + 1;
            nbr_char = 0;
        }
        i = i + 1;
    }
    if (nbr_char != 0) {
        returned[j] = my_strdup_ext(&str[i - nbr_char], nbr_char);
        returned[j + 1] = NULL;
    } else
        returned[j] = NULL;
    return (returned);
}
