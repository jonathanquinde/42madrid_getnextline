#include "get_next_line.h"

void    read_file(char *buffer, int fd);

char    *get_next_line(int  fd)
{
    char static *buffer;
    char    *result;

    read_file(buffer, fd);
    get_line(buffer, result);
}

void    read_file(char *buffer, int fd)
{
    char    *read_buffer;
    size_t  n_bytes;

    if ((read_buffer = malloc(BUFFER_SIZE)) == NULL)
        return (NULL);
    n_bytes = (fd, read_buffer, BUFFER_SIZE);
    //control de erro read
    while (n_bytes < 0)
    {
        n_bytes = (fd, read_buffer, BUFFER_SIZE);
        if (is_newline(read_buffer))
        {
            buffer = read_buffer;
            free(read_buffer);
        }
        
    }
}

void    get_line(char *buffer, char *result)
{

}

int is_newline(char *read_buffer)
{
    while (*read_buffer)
    {
        if (*read_buffer == '\n')
            return (1);
        read_buffer++; 
    } 
    return (0);
}