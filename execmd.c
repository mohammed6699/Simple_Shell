#include "main.h"

/**
 * execmd - function to execute the command enter by the user
 * @argv: argument vetcor that responsible for execute the commands
 * Return:
 */

void execmd(char **argv)
{
	char *location;
	int status;
	pid_t pid;

	if (argv[0][0] == 'e' && argv[0][1] == 'n' &&	argv[0][2] == 'v'
	&& argv[0][3] == '\n')
	{
		get_env();
		return;
	}
	pid = fork();
	/*execute the location of the env*/
	location = get_location(argv[0]);
	/*check the success of get_location*/
	if (location == NULL)
	{
		printf("command not found...");
		return (-1);
	}
	/*create new process*/
	pid = fork();
	if (pid == 0)
	{
		if (execve(location, argv, NULL) < 0)
		{
			perror("execve");
			exit(1);
		}
	}
	else if (pid == -1)
	{
		perror("fork");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(location);
}
