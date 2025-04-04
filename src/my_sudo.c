/*
** EPITECH PROJECT, 2025
** sudo
** File description:
** my_sudo
*/

#include "../include/my.h"

int find_username_in_sudoers(const char *username)
{
    FILE *file = fopen("/etc/sudoers", "r");
    char *line = NULL;
    size_t len = 0;
    int found = 0;

    if (!file) {
        perror("ERROR");
        return 0;
    }
    while (getline(&line, &len, file) > 0) {
        if (strstr(line, username)) {
            found = 1;
            break;
        }
    }
    free(line);
    fclose(file);
    return found;
}

FILE *check_shadow_file(FILE *shadow_file)
{
    if (!shadow_file) {
        perror("ERROR");
        return NULL;
    }
    return shadow_file;
}

char *get_salt(char **password, const char *username)
{
    FILE *shadow_file;
    char *line = NULL;
    size_t len = 0;

    shadow_file = fopen("/etc/shadow", "r");
    if (check_shadow_file(shadow_file) == NULL)
        return NULL;
    while (getline(&line, &len, shadow_file) > 1) {
        if (!strcmp(strtok(line, ":"), username)) {
            *password = strtok(NULL, ":");
            break;
        }
    }
    return strndup(*password, strchr(*password + 7, '$') - *password);
    fclose(shadow_file);
}

int user_passwrd(const char *username)
{
    char *found_password = NULL;
    char *user = NULL;
    char *salt;
    char *temp_passwd = NULL;

    salt = get_salt(&found_password, username);
    verify_psswd(user, salt, found_password, temp_passwd);
    return 0;
}

int uid_gid(int ac, char **av)
{
    char *str = malloc(200);
    int count = 0;

    for (int i = 0; i < ac; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            str[count] = av[i][j];
            count++;
        }
        setuid(0);
        setgid(0);
        str[count] = '\0';
        system(str);
    }
    return 0;
}
