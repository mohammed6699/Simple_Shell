#include "main.h"

/**
 * main - Main function
 * @argc: argument count check number of argument enter by the user
 * @argv: argument which take the token enter by the user
 * Return: (0) success, (1) fail
 */

int main(int argc, char **argv)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t char_read;
	int number_tokens = 0;
	int i;

	/*void variables*/
	(void)argc;

	while (1)
	{
		printf("$");
		char_read = getline(&lineptr, &n, stdin);
		if (char_read == -1)
		{
			perror("char_read");
			return (-1);
		}
		argv = get_tokens(lineptr, &number_tokens);
		if (argv == NULL)
		{
			perror("get_tokens");
			free(lineptr);
			return (-1);
		}
		if (argv[0][0] == 'e' && argv[0][1] == 'x' && argv[0][2] == 'i' &&
				argv[0][3] == 't' && argv[0][4] == '\0')
		{
			for (i = 0; i < number_tokens; i++)
			{
				free(argv[i]);
			}
			return (0);
		}
		execmd(argv);
		free(argv);
	}
	free(lineptr);
	return (0);
}
