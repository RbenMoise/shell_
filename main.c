#include "main.h"

int main(void)
{
    char *command;
    size_t len = 0;
    ssize_t read;

    while (1)
    {
        printf("$ ");
        read = getline(&command, &len, stdin);

        if (read == -1)
        {
            if (isatty(STDIN_FILENO))
                printf("\n");
            break;
        }

        if (read > 1)
        {
            /* Remove the newline character from the end of the command*/
            if (command[read - 1] == '\n')
                command[read - 1] = '\0';

            /* Execute the command*/
            execute_command(command);
        }
    }

    free(command);
    return (0);
}

void execute_command(char *command)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Fork error");
        return;
    }

    if (child_pid == 0)
    {
        /* This code is executed by the child process*/
        if (execve(command, NULL, NULL) == -1)
        {
            perror("Command execution error");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* This code is executed by the parent process*/
        waitpid(child_pid, &status, 0);
    }
}

