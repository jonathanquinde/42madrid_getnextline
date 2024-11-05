/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:56:04 by jquinde-          #+#    #+#             */
/*   Updated: 2024/10/15 12:56:04 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_file(int fd, char	**buffer);
static char	*get_line(char **buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			read_status;
	char		*result;

	if (buffer == NULL)
	{
		buffer = malloc(1);
		if (buffer == NULL)
			return (NULL);
		*buffer = 0;
	}
	read_status = 0;
	if (!(is_newline(buffer, ft_strlen(buffer))))
		read_status = read_file(fd, &buffer);
	if (read_status == 2)
	{
		free (buffer);
		return (buffer = NULL);
	}
	result = get_line(&buffer);
	return (result);
}

//0=quedan bytes; 1=ultima linea; 2=error(mallloc, read)
static int	read_file(int fd, char **buffer)
{
	char	*read_buffer;
	int		n_bytes;

	read_buffer = malloc(BUFFER_SIZE);
	if (read_buffer == NULL)
		return (2);
	n_bytes = read(fd, read_buffer, BUFFER_SIZE);
	while (n_bytes > 0 && *buffer)
	{
		if (!join_and_free(buffer, read_buffer, n_bytes))
		{
			free (read_buffer);
			return (2);
		}
		if (is_newline(read_buffer, n_bytes) && *buffer)
		{
			free(read_buffer);
			return (0);
		}
		n_bytes = read(fd, read_buffer, BUFFER_SIZE);
	}
	free(read_buffer);
	if (n_bytes == -1 || **buffer == 0)
		return (2);
	return (1);
}

static char	*get_line(char **buffer)
{
	char	*result;
	size_t	i;
	size_t	len;

	i = 0;
	while ((*buffer)[i] != '\n' && (*buffer)[i])
		i++;
	result = malloc(i + 1 + ((*buffer)[i] == '\n'));
	if (result == NULL)
	{
		free (*buffer);
		*buffer = NULL;
		return (NULL);
	}
	ft_strncpy(result, *buffer, i + ((*buffer)[i] == '\n'));
	len = ft_strlen((*buffer) + i + ((*buffer)[i] == '\n'));
	ft_strncpy(*buffer, (*buffer) + i + ((*buffer)[i] == '\n'), len);
	return (result);
}

/*
int main(void)
{
	int fd;
	char *line;

	fd = open("hola.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		//printf("Line: %s", line);	
		free (line);
		line = get_next_line(fd);
	}
	//printf("\nLine: %s", line);	
}*/