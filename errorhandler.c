#include "main.h"

/**
 * print_error - Prints an error message to stderr.
 * @message: The error message to print.
 */
void print_error(char *message)
{
    fprintf(stderr, "%s\n", message);
}

/**
 * exit_with_error - Prints an error message and exits the shell with a status code.
 * @message: The error message to print.
 * @status: The exit status code.
 */
void exit_with_error(char *message, int status)
{
    print_error(message);
    exit(status);
}

