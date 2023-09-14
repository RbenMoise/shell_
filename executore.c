#include "main.h"
#include <stdlib.h>


/**
 * execute_command - Executes a command with the given arguments.
 * @command: The command to execute.
 * @args: An array of arguments (including the command itself).
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char *command, char **args)
{
    pid_t child_pid;
    int status;

    if (command == NULL)
        return (-1);

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        return (-1);
    }

    if (child_pid == 0)
    {
        /* This code is executed by the child process */
        if (execve(command, args, NULL) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* This code is executed by the parent process */
        do
        {
            if (waitpid(child_pid, &status, WUNTRACED) == -1)
            {
                perror("waitpid");
                return (-1);
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return (0);
}

