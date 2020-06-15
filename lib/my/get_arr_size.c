/*
** EPITECH PROJECT, 2019
** get_arr_size.c
** File description:
** count arr size
*/

#include <stdlib.h>

int get_arr_size(char **arr)
{
    int size = 0;

    if (arr == NULL)
        return 0;
    for (; arr[size]; size++);
    return size;
}
