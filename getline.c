#include "main.h"
#include <stdlib.h>


/**
 * _getline - Custom getline function.
 * @buffer: A pointer to a buffer where the line will be stored.
 * @buf_size: The size of the buffer.
 * @fd: The file descriptor to read from.
 *
 * Return: On success, the number of characters read (including the newline
 * character if present), 0 at the end of the file, and -1 on failure.
 */
ssize_t _getline(char **buffer, size_t *buf_size, int fd)
{
    ssize_t bytes_read = 0;
    ssize_t total_bytes = 0;
    char *line = NULL;
    char c;

    if (buffer == NULL || buf_size == NULL || fd < 0)
        return (-1);

    *buffer = NULL;
    *buf_size = 0;

    do {
        if (total_bytes == *buf_size)
        {
            *buf_size += READ_SIZE;
            line = _realloc(line, total_bytes, *buf_size);
            if (line == NULL)
                return (-1);
        }
        bytes_read = read(fd, &c, 1);
        if (bytes_read == -1 || (bytes_read == 0 && total_bytes == 0))
        {
            free(line);
            return (-1);
        }
        line[total_bytes++] = c;
    } while (c != '\n' && bytes_read > 0);

    if (bytes_read == 0 && total_bytes == 1)
    {
        free(line);
        return (0);
    }

    line[total_bytes] = '\0';
    *buffer = line;

    return (total_bytes);
}

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated with malloc(old_size).
 * @old_size: The size, in bytes, of the allocated space for ptr.
 * @new_size: The new size, in bytes, for the new memory block.
 *
 * Return: On success, a pointer to the newly allocated memory block.
 * On failure, NULL is returned, and the pointer ptr is left unchanged.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    void *new_ptr;
    unsigned int min_size;

    if (new_size == old_size)
        return (ptr);

    if (ptr == NULL)
        return (malloc(new_size));

    if (new_size == 0 && ptr != NULL)
    {
        free(ptr);
        return (NULL);
    }

    min_size = old_size < new_size ? old_size : new_size;
    new_ptr = malloc(new_size);

    if (new_ptr == NULL)
        return (NULL);

    for (unsigned int i = 0; i < min_size; i++)
        ((char *)new_ptr)[i] = ((char *)ptr)[i];

    free(ptr);
    return (new_ptr);
}

