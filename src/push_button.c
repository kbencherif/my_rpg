/*
** EPITECH PROJECT, 2020
** project_name
** File description:
** push_button
*/

#include "button.h"
#include <stdlib.h>

list_t *push_button(button_t *button, list_t *list)
{
    list_t *tmp = list;
    list_t *new_elem = malloc(sizeof(list_t));

    new_elem->next = NULL;
    new_elem->button = button;
    if (!tmp)
        return new_elem;
    while (tmp && tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = new_elem;
    return list;
}
