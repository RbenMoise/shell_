#include "main.h"

/**
 * read_file - Reads the content of a file and returns it as a string.
 * @filename: The name of the file to read.
 * Return: A string containing the file content, or NULL on failure.
 */
char *read_file(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char *content = (char *)malloc(size + 1);
    if (content == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        fclose(file);
        return NULL;
    }

    size_t bytesRead = fread(content, 1, size, file);
    if (bytesRead != (size_t)size)
    {
        fprintf(stderr, "Error reading file %s\n", filename);
        free(content);
        fclose(file);
        return NULL;
    }

    content[size] = '\0';
    fclose(file);

    return content;
}

/**
 * write_file - Writes content to a file.
 * @filename: The name of the file to write to.
 * @content: The content to write to the file.
 * Return: 0 on success, -1 on failure.
 */
int write_file(const char *filename, const char *content)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file %s\n", filename);
        return -1;
    }

    if (fprintf(file, "%s", content) < 0)
    {
        fprintf(stderr, "Error writing to file %s\n", filename);
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}

