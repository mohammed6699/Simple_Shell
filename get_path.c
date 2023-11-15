#include "main.h"

/**
 * get_path - function for all definations of all variables in the get_path
 * @token: token from the user
 * @command: command enter by the user
 *
 * Return: path_file
 */

char *get_path(char *token, char *command)
{
	int dir_length = strlen(token);
	int command_length = strlen(command);
	char *path_file = malloc(command_length + dir_length + 2);

	strcpy(path_file, token);
	strcat(path_file, "/");
	strcat(path_file, command);
	strcat(path_file, "\0");
	return (path_file);
}
