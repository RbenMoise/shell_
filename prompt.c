#include "main.h"
#include <stdlib.h>


/**
 * display_prompt - Displays the shell prompt.
 */
void display_prompt(void)
{
    printf("$ ");  // You can customize the prompt as needed
    fflush(stdout);
}

/**
 * read_input - Reads a line of input from the user.
 * Return: A string containing the user's input.
 */
char *read_input(void)
{
    char *input = NULL;
    size_t bufsize = 0;

    if (getline(&input, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            printf("\n");  /* Handle Ctrl+D (EOF) gracefully*/
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("getline");
            exit(EXIT_FAILURE);
        }
    }

    return input;
}

