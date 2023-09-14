#include "main.h"

/**
 * print_env - Prints the current environment variables.
 */
void print_env(void)
{
    int i;
    extern char **environ;

    for (i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
}

