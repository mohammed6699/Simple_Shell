#include "main.h"

/**
 * get_location - a function that tack the location
 * @command: is the char that will execute command
 * Return: NULL.
 */

char *get_location(char *command)
    {
        char *path;
        char *path_copy;
        int command_length;
        char *token;
        char *path_file;
        struct stat buffer;
        int dir_length = 0;

        path = getenv("PATH");

    if (path)
    {
        path_copy = strdup(path);
        command_length = strlen(command);
        token = strtok(path_copy, ":");
        while (token != NULL)
        {
        dir_length = strlen(token);
        path_file = malloc(command_length + dir_length + 2);
        strcpy(path_file, token);
        strcat(path_file, "/");
        strcat(path_file, command);
        strcat(path_file, "\0");
        if (stat(path_file, &buffer) == 0)
        {
            free(path_copy);
            return (path_file);
        }
        else
        {
            free(path_file);
            token = strtok(NULL, ":");
        }
        }
        free(path_copy);
        if (stat(command, &buffer) == 0)
        {
            return (command);
        }
    }
    return (NULL);
    }
