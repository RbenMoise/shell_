#include "main.h"
#include  <stdlib.h>


/**
 * split_commands - Splits a line into multiple commands using the ';' delimiter.
 * @line: The input string containing one or more commands.
 * @commands: An array to store the separated commands.
 * @max_commands: The maximum number of commands to split and store.
 * Return: The number of commands found.
 */
int split_commands(char *line, char *commands[], int max_commands)
{
    int num_commands = 0;
    char *token = strtok(line, ";"); // Split the line using ';' delimiter

    while (token != NULL && num_commands < max_commands)
    {
        commands[num_commands++] = token;
        token = strtok(NULL, ";");
    }

    return num_commands;
}

/**
 * process_commands - Process an array of commands.
 * @commands: An array of command strings.
 * @num_commands: The number of commands in the array.
 */
void process_commands(char *commands[], int num_commands)
{
    for (int i = 0; i < num_commands; i++)
    {
        /* Process each command, e.g., by passing it to your command execution logic.
        // You can use the execute_command function or your own logic here.*/
        execute_command(commands[i]);
    }
}

