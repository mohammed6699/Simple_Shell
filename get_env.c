#include "main.h"

/**
 * get_env - function thats handel with var.
 * Return:
 */

void get_env(void)
{
	int i;

    char *env_variables[] = {"USER", "LANGUAG", "SESSION", "COMPIZ_CONFIG_PROFILE", "SHLVL", "HOME", "C_IS", "DESKTOP_SESSION", "LOGNAME", "TERM", "PATH", "DISPLAY"};
    int num_variables = sizeof(env_variables) / sizeof(char*);
    for (i = 0; i < num_variables; i++)
    {
        char *variable = getenv(env_variables[i]);
        if (variable != NULL)
        {
            printf("%s: %s\n", env_variables[i], variable);
        }
    }
}
