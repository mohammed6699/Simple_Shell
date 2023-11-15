#include "main.h"

/**
 * get_env - function thats handel with var.
 *
 * Return: (0) for success, (-1) for fail
 */

int get_env(void)
{
	char *variable;
	int i;
	int num_variables;
	char *env_variables[] = {"USER", "LANGUAGE", "SESSION",
		"COMPIZ_CONFIG_PROFILE", "SHLVL", "HOME", "C_IS",
			"DESKTOP_SESSION", "LOGNAME", "TERM", "PATH", "DISPLAY"};

	num_variables = sizeof(env_variables) / sizeof(char *);

	for (i = 0; i < num_variables; i++)
	{
		variable = getenv(env_variables[i]);

		if (variable != NULL)
		{
			printf("%s: %s\n", env_variables[i], variable);
		}
		else
		{
			printf("Environment variables not exists....\n");
			return (-1);
		}
	}
	return (0);
}
