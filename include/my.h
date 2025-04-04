/*
** EPITECH PROJECT, 2025
** my sudo
** File description:
** my sudo
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <sys/types.h>

void my_putchar(char c);
int my_strlen(char const *str);
int my_putstr(char const *str);
void help(int ac, char **av);
int user_passwrd(const char *username);
void help(int ac, char **av);
int uid_gid(int ac, char **av);
int verify_psswd(char *user, char *salt, char *found_password, char *temp_passwd);

#endif /* !MY_H_ */
