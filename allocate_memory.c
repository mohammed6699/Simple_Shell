#include "main.h"

/**
 * allocate_memory_for_tokens - function to allocate memory
 * @line_copy: line_copy
 * @number_tokens: number of tokens
 * @limit: consta char hat brwak with atrtok
 *
 * Return: argv
 */
char **allocate_memory_for_tokens(char *line_copy, int *number_tokens, const char *limit)
{
	char *token;
	int i;
	char **argv;

	argv = malloc(sizeof(char *) * (*number_tokens));
	if (argv == NULL)
	{
		perror("malloc");
		free(line_copy);
		return (NULL);
	}
	token = strtok(line_copy, limit);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (argv == NULL)
		{
			perror("malloc");
			while (i > 0)
			{
				free(argv[--i]);
			}
			free(argv);
			free(line_copy);
			return (NULL);
		}
		strcpy(argv[i], token);
		token = strtok(NULL, limit);
	}
	argv[i] = NULL;
	free(line_copy);
	return (argv);
}
