#include "main.h"

/**
 * get_tokens - function that print line to number of tokens
 * @lineptr: pointer to the command line
 * @number_tokens: number of tokens enter by the user
 * Return: allocate_memory_for_tokens
 */

char **get_tokens(char *lineptr, int *number_tokens)
{
	char *token;
	char *line_copy = strdup(lineptr);
	const char limit = "\n";

	if (line_copy == NULL)
	{
		perror("strdup");
		return (NULL);
	}
	token = strtok(line_copy, limit);
	while (token != NULL)
	{
		(*number_tokens)++;
		token = strtok(NULL, limit);
	}
	(*number_tokens)++;
	return allocate_memory_for_tokens(line_copy, number_tokens, limit);
}
