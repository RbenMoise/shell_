#include "main.h"

/**
 * tokenizer - Tokenizes a string into an array of tokens.
 * @str: The string to tokenize.
 * @delimiter: The delimiter used to split the string.
 *
 * Return: An array of tokens on success, NULL on failure.
 */
char **tokenizer(char *str, const char *delimiter)
{
    char **tokens = NULL;
    char *token = NULL;
    int token_count = 0;
    int token_size = TOKEN_SIZE;
    int i = 0;

    if (str == NULL || delimiter == NULL)
        return (NULL);

    tokens = malloc(sizeof(char *) * token_size);
    if (tokens == NULL)
        return (NULL);

    token = strtok(str, delimiter);
    while (token != NULL)
    {
        if (token_count >= token_size)
        {
            token_size += TOKEN_SIZE;
            tokens = _realloc(tokens, sizeof(char *) * token_size);
            if (tokens == NULL)
                return (NULL);
        }
        tokens[token_count] = strdup(token);
        if (tokens[token_count] == NULL)
            return (NULL);
        token = strtok(NULL, delimiter);
        token_count++;
    }

    tokens[token_count] = NULL;
    return (tokens);
}

/**
 * free_tokens - Frees an array of tokens.
 * @tokens: The array of tokens to free.
 */
void free_tokens(char **tokens)
{
    if (tokens == NULL)
        return;

    for (int i = 0; tokens[i] != NULL; i++)
        free(tokens[i]);

    free(tokens);
}

