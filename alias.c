#include "main.h"

/**
 * print_aliases - Prints a list of all defined aliases.
 * @aliases: An array of alias structures.
 */
void print_aliases(alias_t *aliases)
{
    alias_t *current = aliases;

    while (current != NULL)
    {
        printf("%s='%s'\n", current->name, current->value);
        current = current->next;
    }
}

/**
 * add_alias - Adds a new alias to the list.
 * @aliases: A pointer to the list of alias structures.
 * @name: The name of the alias.
 * @value: The value or command associated with the alias.
 * Return: 0 on success, -1 on failure.
 */
int add_alias(alias_t **aliases, char *name, char *value)
{
    alias_t *new_alias, *current;

    if (!name || !value)
        return (-1);

    new_alias = malloc(sizeof(alias_t));
    if (!new_alias)
        return (-1);

    new_alias->name = strdup(name);
    if (!new_alias->name)
    {
        free(new_alias);
        return (-1);
    }

    new_alias->value = strdup(value);
    if (!new_alias->value)
    {
        free(new_alias->name);
        free(new_alias);
        return (-1);
    }

    new_alias->next = NULL;

    if (*aliases == NULL)
    {
        *aliases = new_alias;
    }
    else
    {
        current = *aliases;
        while (current->next != NULL)
            current = current->next;
        current->next = new_alias;
    }

    return (0);
}

/**
 * find_alias - Finds an alias by name.
 * @aliases: A pointer to the list of alias structures.
 * @name: The name of the alias to find.
 * Return: A pointer to the alias structure if found, NULL otherwise.
 */
alias_t *find_alias(alias_t *aliases, char *name)
{
    alias_t *current = aliases;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
            return (current);
        current = current->next;
    }

    return (NULL);
}

/**
 * free_aliases - Frees the list of alias structures.
 * @aliases: A pointer to the list of alias structures.
 */
void free_aliases(alias_t *aliases)
{
    alias_t *current, *next;

    current = aliases;
    while (current != NULL)
    {
        next = current->next;
        free(current->name);
        free(current->value);
        free(current);
        current = next;
    }
}

