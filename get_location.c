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
	char *path_file;
	char *token;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		token = strtok(path_copy, ":");
		while (token != NULL)
		{
			path_file = get_path(token, command);
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
