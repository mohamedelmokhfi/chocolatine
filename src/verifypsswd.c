/*
** EPITECH PROJECT, 2025
** my sudo
** File description:
** verifypsswd
*/

#include "../include/my.h"

int verify_psswd(char *user, char *salt, char *found_password, char *temp_passwd)
{
    int attempt = 0;

    while (attempt != 3) {
        user = getpass("[my_sudo] password for samy:");
        if (user == NULL || salt == NULL) {
            return 84;
        }
        temp_passwd = crypt(user, salt);
        if (!strcmp(temp_passwd, found_password)) {
            printf("Success!\n");
            return 0;
        } else {
            printf("Sorry, try again.\n");
        }
        attempt++;
    }
    printf("sudo: 3 incorrect password attempts\n");
    return 84;
}