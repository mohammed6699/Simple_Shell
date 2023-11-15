#include "main.h"

/**
 * main - Main function
 * @argc: argument count check number of argument enter by the user
 * @argv: argument which take the token enter by the user
 * Return: (0) success, (1) fail
 */

int main(int argc, char **argv)
{
	char *prom = "$";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t char_read;
	int number_tokens = 0;

	/*void variables*/
	(void)argc;

	while (1)
	{
		printf("%s", prom);
		char_read = getline(&lineptr, &n, stdin);
		if (char_read == -1)
		{
			printf("Exiting the shell....\n");
			return (-1);
		}
		argv = get_tokens(lineptr, &number_tokens);
		if (argv[0][0] == 'e' && argv[0][1] == 'x' && argv[0][2] == 'i' &&
				argv[0][3] == 't' && argv[0][4] == '\0')
		{
			printf("Exiting the shell...\n");
			return (0);
		}
		execmd(argv);
	}
	free(lineptr);
	return (0);
}
