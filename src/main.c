/*
** EPITECH PROJECT, 2025
** sudo
** File description:
** main
*/

#include "../include/my.h"

int main(int ac, char **av)
{
    if (ac < 2) {
        my_putstr("usage:\t./my_sudo [-ugEs] [command [args ...]]\n");
        return 1;
    }
    help(ac, av);
    if (!user_passwrd(getenv("USER")))
        return 84;
    uid_gid(ac - 1, av + 1);
    return 0;
}
