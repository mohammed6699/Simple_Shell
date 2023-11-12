#include "main.h"

/**
 * main - Main function
 *
 * Return (0) success, (1) fail
 */

int main(int argc, char **argv)
{
	char *prompt = "#cisfun$ ";
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t chars_read;
	int num_tokens = 0;
	char *token;
	const char *limit = "\n";
	int i;

	/*check argc*/
	if (argc < 1)
	{
		return (-1);
	}
	while (1)
	{
	printf ("%s", prompt);
	/*check the getline function in order to read and print what the user types*/
	chars_read = getline(&lineptr, &n, stdin);
	/*check the success of getline function*/
	if (chars_read == -1)
	{
		printf("Exiting the shell...");
		return (-1);
	}
	/*split the argv into arrays*/
	token = strtok(lineptr, limit);
	/*cal. num.of arrays*/
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, limit);
	}
	num_tokens++;
	/*allocate space to hold the arrays*/
	argv = malloc(sizeof(char *) * num_tokens);
	/*store each token in an array*/
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
	}
	argv[i] = NULL;
	/*check for exit*/
	if (argv[0][0] == 'e' && argv[0][1] == 'x' && argv[0][2] == 'i' && argv[0][3] == 't' && argv[0][4] == '\0');
	{
		printf("Exiting the shell....\n");
		return (0);
	}
	/*execute the command*/
	execmd(argv);
	/*free the allocated memory*/
	for (i = 0; i < num_tokens; i++)
	{
		free(argv[i]);
	}
	}
	free(argv);
	free(lineptr);

	return (0);
}
