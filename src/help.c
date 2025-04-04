/*
** EPITECH PROJECT, 2025
** sudo
** File description:
** help
*/

#include "../include/my.h"

void help(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'h') {
            my_putstr("usage: ");
            my_putstr("./my_sudo -h\n");
            my_putstr("usage: ");
            my_putstr("./my_sudo [-ugEs] [command [args ...]]\n");
        }
    }
}
