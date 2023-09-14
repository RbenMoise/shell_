#include "main.h"
#include <stdlib.h>


/**
 * remove_comments - Removes comments from a string.
 * @line: The input string containing a command line.
 */
void remove_comments(char *line)
{
    char *hash = strchr(line, '#'); // Find the first occurrence of '#' in the line
    if (hash)
    {
        *hash = '\0'; // Null-terminate the string at the '#' character
    }
}

/**
 * remove_trailing_whitespace - Removes trailing whitespace from a string.
 * @line: The input string.
 */
void remove_trailing_whitespace(char *line)
{
    int length = strlen(line);
    if (length == 0)
        return;

    int i = length - 1;
    while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))
    {
        line[i] = '\0';
        i--;
    }
}

/**
 * preprocess_input - Preprocesses the input line, removing comments and trailing whitespace.
 * @line: The input string containing a command line.
 */
void preprocess_input(char *line)
{
    if (line == NULL)
        return;

    remove_comments(line);
    remove_trailing_whitespace(line);
}

