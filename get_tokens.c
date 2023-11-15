#include "main.h"

/**
 * get_tokens - function that print line to number of tokens
 * @lineptr: pointer to the command line
 * @number_tokens: number of tokens enter by the user
 * Return: argv
 */

char **get_tokens(char *lineptr, int *number_tokens)
{
	char *token;
	int i;
	char **argv;
	char *line_copy = strdup(lineptr);
	const char *limit = "\n";

	/*split the token*/
	token = strtok(line_copy, limit);
	/*cal. number of tokens*/
	while (token != NULL)
	{
		(*number_tokens)++;
		token = strtok(NULL, limit);
	}
	(*number_tokens)++;
	/*allocate space to hold the array*/
	argv = malloc(sizeof(char *) * (*number_tokens));
	/*store exach token in an array*/
	token = strtok(line_copy, limit);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, limit);
	}
	argv[i] = NULL;
	free(line_copy);
	return (argv);
}
