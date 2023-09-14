#include "main.h"

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
    char input[MAX_INPUT_SIZE];
    int should_run = 1;

    while (should_run)
    {
        printf("Shell > ");
        fflush(stdout);

        /* Read user input */
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break; /* Exit on EOF (Ctrl+D) */
        }

        /* Remove trailing newline */
        input[strcspn(input, "\n")] = '\0';

        /* Check for exit command */
        if (strcmp(input, "exit") == 0)
        {
            should_run = 0;
            printf("Exiting the shell...\n");
        }
        else
        {
            /* Execute the command */
            executeCommand(input);
        }
    }

    return (0);
}

/**
 * executeCommand - Tokenizes and executes a command with arguments
 * @input: The user input containing the command and optional arguments
 */
void executeCommand(char *input)
{
    char *args[MAX_INPUT_SIZE / 2 + 1];
    int arg_count = 0;
    char *token;

    /* Tokenize the input */
    token = strtok(input, " \n");
    while (token != NULL)
    {
        args[arg_count] = token;
        arg_count++;
        token = strtok(NULL, " \n");
    }
    args[arg_count] = NULL;

    /* Fork a new process */
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
    }
    else if (pid == 0)
    {
        /* Child process */
        if (execvp(args[0], args) == -1)
        {
            perror("Execution failed");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process */
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status))
        {
            if (WEXITSTATUS(status) != 0)
            {
                printf("Command exited with non-zero status %d\n", WEXITSTATUS(status));
            }
        }
        else
        {
            printf("Command terminated abnormally\n");
        }
    }
}

