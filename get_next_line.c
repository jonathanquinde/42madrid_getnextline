#include "get_next_line.h"

char	*read_file(char *buffer, int fd);
char	*join_and_free(char *buffer, char *read_buffer, int n_bytes);
void	get_line(char *buffer, char *result);
int		is_newline(char *read_buffer);

char	*get_next_line(int fd)
{
	char static	*buffer;
	char		*result;

	buffer = ft_calloc(1, 1);
	read_file(buffer, fd);
	get_line(buffer, result);
	return (result);
}

char	*read_file(char *buffer, int fd)
{
	char	*read_buffer;
	int		n_bytes;

	read_buffer = malloc(BUFFER_SIZE);
	if (read_buffer == NULL)
		return (NULL);
	n_bytes = read(fd, read_buffer, BUFFER_SIZE);
	while (n_bytes > 0)
	{
		printf("---------\nn_bytes: %d, read: |%s|:", n_bytes, read_buffer);
		for (size_t i = 0; i < n_bytes; i++)
		{
			printf(" %d", read_buffer[i]);
			printf("\n");
		}	
		buffer = join_and_free(buffer, read_buffer, n_bytes);
        printf("pato1");
		printf("-----------\n");

        printf("pato2");
		if (is_newline(read_buffer))
		{
            printf("Hey esto funciona");
			free(read_buffer);
			return (buffer);
		}
		n_bytes = read(fd, read_buffer, BUFFER_SIZE);
	}
	return ("Hey porque");
}

char	*join_and_free(char *old_buffer, char *read_buffer, int n_bytes)
{
	char	*new_buffer;
	size_t	buffer_len;
	size_t	i;

	i = 0;
	buffer_len = ft_strlen(old_buffer);
	new_buffer = malloc(buffer_len + n_bytes + 1);
	if (new_buffer == NULL)
		return (NULL);
	while (i < buffer_len)
	{
		new_buffer[i] = old_buffer[i];
		i++;
	}
	while (i < n_bytes + buffer_len)
	{
		new_buffer[i] = read_buffer[i - buffer_len];
		i++;
	}
    printf("Old Buffer: |%s|, size: %zu\n", old_buffer, buffer_len);
    new_buffer[i] = 0;
    printf("New Buffer: |%s|, size: %zu\n", new_buffer, buffer_len + n_bytes);
	free(old_buffer);
	return (new_buffer);
}

void	get_line(char *buffer, char *result)
{
	result = malloc(ft_strlen(buffer) + 1);
	ft_strlcpy(result, buffer, ft_strlen(buffer) + 1);

	free(buffer);
}

int	is_newline(char *read_buffer)
{
	while (*read_buffer)
	{
		if (*read_buffer == '\n')
        {
            printf("pato3");
			return (1);
        }
		read_buffer++;
	}
	return (0);
}