/*
** EPITECH PROJECT, 2025
** sudo
** File description:
** my
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
    i++;
    }
    return i;
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return my_strlen(str);
}
